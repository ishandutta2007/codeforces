#include <iostream>
#include <stdio.h>
#include <math.h>

#define ep 1e-4

using namespace std;

double fgcd(double x, double y){
    if(y<ep) return x; else return fgcd(y, fmod(x,y));
}

double sqr(double x){
    return x*x;
}

int main(){
//    freopen("in.txt", "r", stdin);
    double ax, ay, bx, by, cx, cy;
    scanf("%lf %lf %lf %lf %lf %lf", &ax, &ay, &bx, &by, &cx, &cy);
    double a,b,c,A,B,C;
    a = sqrt(sqr(bx-cx)+sqr(by-cy)); b = sqrt(sqr(ax-cx)+sqr(ay-cy)); c = sqrt(sqr(bx-ax)+sqr(by-ay));
    double p = (a+b+c)/2;
    double s = sqrt(p*(p-a)*(p-b)*(p-c));
    double r = a*b*c/(4*s);
    A = acos((sqr(b)+sqr(c)-sqr(a))/(2*b*c)); B = acos((sqr(a)+sqr(c)-sqr(b))/(2*a*c)); C = acos((sqr(b)+sqr(a)-sqr(c))/(2*b*a));
    double n = M_PI / fgcd(A, fgcd(B,C));
    double res = n*r*r*sin(2*M_PI/n)/2;
    printf("%.8lf\n", res);
}