#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;


char clok[10];

long long INT(char ch)
    {
    return (long long)ch-(long long)'0';
    }

int main()
    {
    long long i;
    long long hs,ms;

    double degreesH,degreesM;

    scanf("%s",clok);

    hs=INT(clok[0])*10+INT(clok[1]);
    hs=hs%12;

    ms=INT(clok[3])*10+INT(clok[4]);

    degreesM=6.0*(double)ms;
    degreesH=(double)hs*30.0 + ( ms*0.5 );

    printf("%4.9f %4.9f\n",degreesH,degreesM);
    return 0;
    }