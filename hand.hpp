#include <string>
#include "unit.hpp"

#ifndef HAND
#define HAND

struct Direction{
    enum Directions: unsigned char{
        North = 'N',
        East = 'E',
        West = 'W',
        South = 'S',
        DontMove = 'D'
    } direction;

    Direction() : direction(DontMove) {}
    Direction(Directions direct) : direction(direct) {}
    Direction(int number){
        switch (number)
        {
        case 0:
            direction = North;
            break;
        case 1:
            direction = East;
            break;
        case 2:
            direction = West;
            break;
        case 3:
            direction = South;
            break;
        
        default:
            direction = DontMove;
            break;
        }
    }
    Direction(char direct){
        switch (direct)
        {
        case 'N':
            direction = North;
            break;
        case 'E':
            direction = East;
            break;
        case 'W':
            direction = West;
            break;
        case 'S':
            direction = South;
            break;
        
        default:
            direction = DontMove;
            break;
        }
    }
    
    bool operator==(const Direction& d)const { return direction == d.direction; }
    bool operator!=(const Direction& d)const { return direction != d.direction; }
    
    char toChar()const{
        return static_cast<char>(direction);
    }

    std::string toString()const{
        switch (direction)
        {
            case North:
                return std::string("North");
            case East:
                return std::string("East");
            case West:
                return std::string("West");
            case South:
                return std::string("South");
            default:
                return std::string("DontMove");
        }
    }
};

struct Hand{
    Unit unit;
    Direction direct;

    Hand(Unit u, Direction d){
        unit = u;
        direct = d;
    }

    Hand(std::string src){
        unit = Unit();
        unit.name = src[0];
        unit.color = src[1];
        unit.x = src[2];
        unit.y = src[3];
        direct = Direction(src[4]);
    }

    std::string toString(){
        return unit.toString() + direct.toChar();
    }
};

#endif