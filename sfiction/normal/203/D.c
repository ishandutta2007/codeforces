/*
ID: Sfiction
OJ: CF128 Div2
PROB: D
*/
#include <stdio.h>
int main()
{
    double a,b,m,vx,vy,vz;
    double x,z,t;
    scanf("%lf%lf%lf",&a,&b,&m);
    scanf("%lf%lf%lf",&vx,&vy,&vz);
    t=-m/vy;
    x=a/2+t*vx;
    z=t*vz;
    while (x<0||x>a)
        if (x>a) x=2*a-x;
        else x=-x;
    while (z<0||z>b)
        if (z>b) z=2*b-z;
        else z=-z;
    printf("%.10lf %.10lf",x,z);
    return 0;
}