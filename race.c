#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Structures section
struct  Race{
  int numberOfLabs;
  int currentLap;
  char  firstPlaceDriverName[20];
  char  firstPlaceRaceCarColor[20];
};
struct RaceCar{
    char  driverName[20];
    char  raceCarColor[20];
    int totalLapTime;
};

// Print functions section
void printIntro(){
  printf("Welcome to our main event digital race fans! I hope everybody has their snacks because we are about to begin!\n");

}
void printCountDown(){
  printf("5\n4\n3\n2\n1\nRace!\n");
}

void printFirstPlaceAfterLap(struct Race race){
  printf("after lap number %d\n" , race.currentLap);
  printf("First Place Is: %s in the %s race car!\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);

}

void printCongratulation(struct RaceCar raceCar){
  printf("Let's all congratulate %s in the %s race car for an amazing performance. It truly was a great race and everybody have a goodnight!", raceCar.driverName, raceCar.raceCarColor);
}

// Logic functions section
int calculateTimeToCompleteLap(){
  int speed = (rand() % 3) + 1;
  int acceleration = (rand() % 3) + 1;
  int nerves = (rand() % 3) + 1;
  return speed + acceleration + nerves;
}
void updateRaceCar(struct RaceCar *raceCar){
  int labTime = calculateTimeToCompleteLap();
  raceCar->totalLapTime = labTime;
}



void updateFirstPlace(struct Race *race, struct RaceCar *raceCar1, struct RaceCar *raceCar2){
  if (raceCar1->totalLapTime <= raceCar2->totalLapTime){
    strcpy(race->firstPlaceDriverName, raceCar1->driverName);
    strcpy(race->firstPlaceRaceCarColor, raceCar1->raceCarColor);
  } else {
    strcpy(race->firstPlaceDriverName, raceCar2->driverName);
    strcpy(race->firstPlaceRaceCarColor, raceCar2->raceCarColor);
  }

}

void startRace(struct RaceCar *raceCar1, struct RaceCar *raceCar2){
  struct Race race = {5, 1, "", ""};
  for (int lap = 1; lap <= race.numberOfLabs; lap++){
    updateRaceCar(raceCar1);
  updateRaceCar(raceCar2);
  race.currentLap = lap;
  updateFirstPlace(&race, raceCar1, raceCar2);
  printFirstPlaceAfterLap(race);
  }
  if (raceCar1->totalLapTime <= raceCar2->totalLapTime){
    printCongratulation(*raceCar1);
  } else {
    printCongratulation(*raceCar2);
  }
}

int main() {
  srand(time(0));
  printIntro();
  printCountDown();

  struct RaceCar car1 = {"Driver 1", "Red", 0};
  struct RaceCar car2 = {"Driver 2", "Blue", 0};
  
  startRace(&car1, &car2);
  return 0;
}
