//
//  lab3.hpp
//  lab3OOP
//
//  Created by Антон Волков on 22.12.2017.
//  Copyright © 2017 Антон Волков. All rights reserved.
//
#ifndef lab3_hpp
#define lab3_hpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
using namespace std;
class Driver;
class Car;
class Engine;
class Transmission;
class Accelerator;
class Wheels;

class Driver {
public:
    Driver(string name, Car& au80);
    string name;
    Car* au80;
    void speedUpCar(ofstream &fout);
    void pressPedal(ofstream &fout);
    void unPressPedal(ofstream &fout);
};
class Car {
public:
    Car(string name, int maxSpeedCar, Transmission& akpp4, Wheels& r15, Accelerator& pedal, Engine& valve8);
    string name;
    Transmission* akpp4;
    Wheels* r15;
    Accelerator* pedal;
    Engine* valve8;
    int maxSpeedCar;
};
class Engine {
public:
    Engine(double maxSpeeds);
    double maxSpeeds;
    
    double getCurrSpeeds();
    double upSpeeds();
    double downSpeeds();
private:
    double currSpeeds;
};
class Accelerator {
public:
    Accelerator(Engine &valve8);
    Engine* valve8;
    double changeSpeedsEngine(ofstream &fout);
    void setPedalForce(int pressForce);
    void setPedalPress();
    void setPedalUnpress();
protected:
    bool pedalPressed;
    int force; //0 - не нажата, 1 - в половину, 2 - на максимум
};
class Transmission {
public:
    Transmission(int countNum, const vector<double> &gears, Engine &valve8);
    int countNum;
    vector<double>* gears; //передачи
    double mainGear;
    vector<double> akppGears;
    Wheels* r15;
    Engine* valve8;
    int getCurrGear();
    double getGearRatio();
    double setUnionGearRatio();
    //void setSpeedsToUnGearRatio(ofstream &fout);
    double setSpeedsToUnGearRatio();
    // OБОРОТЫ ДВИГАТЕЛЯ / ОБЩЕЕ ПЕРЕДАТОЧНОЕ ОТНОШЕНИЕ
    int gearShift(ofstream &fout); //переключить передачу
private:
    double gearRatio; //передаточное отношение
    double unionGearRatio; //общее
    int currGear;
    bool clutchPressed;
    double speedsToUnGearRatio;
};
class Wheels {
public:
    Wheels(int diameter, Transmission& akpp4);
    Transmission* akpp4;
    int diameter;
    
    void getCurrSpeedWh(ofstream &fout);
    int setCurrSpeedWh();
    //ОБОРОТЫ ДВИГАТЕЛЯ / ОБЩЕЕ ПЕРЕДАТОЧНОЕ ОТНОШЕНИЕ х ДИАМЕТР КОЛЕСА (см) / 530,616
private:
    int currSpeedWheels;
};
#endif /* lab3_hpp */
