#include <stdio.h>
#include <math.h>

#define sqr(a) ((a)*(a))

using namespace std;

double x[3], y[3], r[3], cx, cy, ste, ang[3];

double f(double xx, double yy){
    for(int i=0; i<3; i++){
        ang[i] = sqrt(sqr(x[i]-xx) + sqr(y[i]-yy)) / r[i];
    }
    double res = 0;
    for(int i=0; i<3; i++){
        res += sqr(ang[i] - ang[(i+1)%3]);
    }
    return res;
}

int main(){
    //freopen("in.txt", "r", stdin);
    cx = 0; cy = 0;
    for(int i=0; i<3; i++) {
        scanf("%lf %lf %lf", &x[i], &y[i], &r[i]);
        cx += x[i]/3; cy += y[i]/3;
    }
    ste = 1;
    while(ste>1e-6){
        if(f(cx,cy) > f(cx+ste, cy)) cx+=ste;
        else if(f(cx,cy) > f(cx, cy+ste)) cy+=ste;
        else if(f(cx,cy) > f(cx-ste, cy)) cx-=ste;
        else if(f(cx,cy) > f(cx, cy-ste)) cy-=ste;
        else ste*=0.5;
    }
    if(f(cx,cy)<1e-5) printf("%lf %lf\n", cx, cy);
}