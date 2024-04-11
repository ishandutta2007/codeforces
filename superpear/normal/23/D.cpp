#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <sstream>
#include <list>
#include <complex>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long
#define p_b push_back
#define m_p make_pair
#define l_b lower_bound
#define w1 first
#define w2 second

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;
typedef pair<pair<int,int>,pair<int,int> > PIIII;
typedef pair<double,double> PDD;
typedef pair<double,int> PDI;
typedef pair<string,int> PSI;
typedef pair<pair<double,double>,double> PDDD;
typedef pair<pair<double,double>,pair<double,double> > PDDDD;

int tt,flag;

bool equal(double a,double b)
{
    return abs(a-b)<=1e-9;
}

int cross(double x1,double y1,double x2,double y2)
{
    double cc=x1*y2-x2*y1;
    if (equal(cc,0)) return 0;
    if (cc>0) return 1; else return -1;
}

double dis(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

bool isconvex(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4)
{
    int c1=cross(x2-x1,y2-y1,x3-x2,y3-y2);
    int c2=cross(x3-x2,y3-y2,x4-x3,y4-y3);
    int c3=cross(x4-x3,y4-y3,x1-x4,y1-y4);
    int c4=cross(x1-x4,y1-y4,x2-x1,y2-y1);
    if ((c1!=0)&&(c1==c2)&&(c2==c3)&&(c3==c4)) return true; else return false;
}

void check(double x1,double y1,double x2,double y2,double x3,double y3)
{
    if (flag==0) return;
    double x0=(x2+x3)/2,y0=(y2+y3)/2;
    double ts=dis(x0,y0,x2,y2);
    double xc=(x0-x2)/ts,yc=(y0-y2)/ts;
    swap(xc,yc);
    xc=-xc;
    double t0=2*x2-x0-x1,t1=2*y2-y0-y1,t2=x0-x2,t3=y0-y2;
    if ((xc*t0+yc*t1+xc*t2+yc*t3)==0) return;
    double k=(t0*t0+t1*t1-t2*t2-t3*t3)/(2*(xc*t0+yc*t1+xc*t2+yc*t3));
    double x4=x0+k*xc,y4=y0+k*yc;
    double x5=x3*2-x4,y5=y3*2-y4;
    double x7=x2*2-x4,y7=y2*2-y4;
    double x6=x1*2-x7,y6=y1*2-y7;
    if (isconvex(x4,y4,x5,y5,x6,y6,x7,y7))
    {
        flag=0;
        printf("YES\n");
        printf("%.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf %.10lf\n",x4,y4,x5,y5,x6,y6,x7,y7);
    }
}

int main()
{
    double x1,y1,x2,y2,x3,y3;
    scanf("%d",&tt);
    for (int gb=1;gb<=tt;gb++)
    {
        scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3);
        flag=1;
        check(x1,y1,x2,y2,x3,y3);
        check(x1,y1,x3,y3,x2,y2);
        check(x2,y2,x1,y1,x3,y3);
        check(x2,y2,x3,y3,x1,y1);
        check(x3,y3,x1,y1,x2,y2);
        check(x3,y3,x2,y2,x1,y1);
        if (flag==1)
            printf("NO\n\n");
    }

    return 0;
}