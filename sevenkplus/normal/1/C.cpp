#include <cmath>
#include <iostream>
#include <stdio.h>
using namespace std;
#define pi 3.141592653589793238462643383279502884197169399375105820974944
#define eps 1e-4
#define d(a) (fabs(sin(n*(a)/2))<eps)
int f(double a1,double a2,double a3,int n)
{
    return (d(a1-a2)&&d(a2-a3)&&d(a3-a1));
}
void calc(double x1,double y1,double x2,double y2,double &a,double &b,double &c)
{
    double x3,y3,a1,b1,c1;
    x3=(x1+x2)/2;y3=(y1+y2)/2;
    a1=y1-y2;b1=x2-x1;c1=a1*x1+b1*y1;
    a=-b1;b=a1;c=a1*y3-b1*x3;
}
void calc2(double a1,double b1,double c1,double a2,double b2,double c2,double &x,double &y)
{
    x=(c1*b2-b1*c2)/(a1*b2-a2*b1);
    if (b1!=0) y=(c1-a1*x)/b1; else y=(c2-a2*x)/b2;
}
int main()
{
    double x1,y1,x2,y2,x3,y3,xc,yc,a12,b12,c12,a13,b13,c13,a1,a2,a3,r;
    int n;
    scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
    calc(x1,y1,x2,y2,a12,b12,c12);
    calc(x1,y1,x3,y3,a13,b13,c13);
    calc2(a12,b12,c12,a13,b13,c13,xc,yc);
    a1=atan2(y1-yc,x1-xc);
    a2=atan2(y2-yc,x2-xc);
    a3=atan2(y3-yc,x3-xc);
    n=3;while (!f(a1,a2,a3,n))n++;
    r=sqrt((y1-yc)*(y1-yc)+(x1-xc)*(x1-xc));
    printf("%f\n",n*r*r*sin(pi/n)*cos(pi/n)); 
    return 0;
}