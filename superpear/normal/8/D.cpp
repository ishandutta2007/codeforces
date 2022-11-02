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
typedef pair<pair<double,double>,double> circle;
typedef pair<double,double> point;

double dist(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double dist(point a,point b)
{
    double x1=a.w1,y1=a.w2,x2=b.w1,y2=b.w2;
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

bool equal(double a,double b)
{
    return abs(a-b)<=1e-12;
}

pair<point,point> cross(circle a1,circle a2)
{
    double a=a1.w2,b=a2.w2,c=dist(a1.w1,a2.w1);
    double theta=acos((a*a+c*c-b*b)/(2*a*c));
    complex<double> f1(a2.w1.w1-a1.w1.w1,a2.w1.w2-a1.w1.w2);
    complex<double> fd((a/c)*cos(theta),(a/c)*sin(theta));
    complex<double> fe((c/a)*cos(theta),(c/a)*sin(theta));
    complex<double> f3=f1*fd,f4=f1/fe;
    return m_p(m_p(f3.real()+a1.w1.w1,f3.imag()+a1.w1.w2),
               m_p(f4.real()+a1.w1.w1,f4.imag()+a1.w1.w2));
}

bool inside(pair<point,point> a,circle b)
{
    double e;
    e=dist(a.w1,b.w1);
    if (equal(e,b.w2)||(e<b.w2)) return true;
    e=dist(a.w2,b.w1);
    if (equal(e,b.w2)||(e<b.w2)) return true;
    return false;
}

bool inside(point a,circle b)
{
    double e;
    e=dist(a,b.w1);
    if (equal(e,b.w2)||(e<b.w2)) return true;
    return false;
}

void print(circle a)
{
    cout<<"("<<a.w1.w1<<","<<a.w1.w2<<")  "<<a.w2<<endl;
}

void print(point a)
{
    cout<<"("<<a.w1<<","<<a.w2<<")"<<endl;
}

bool check(double nowans,double xc,double yc,double x0,double y0,double x1,double y1,double t1,double t2)
{
    circle cir1=m_p(m_p(xc,yc),nowans);
    circle cir2=m_p(m_p(x0,y0),dist(xc,yc,x0,y0)+t2-nowans);
    circle cir3=m_p(m_p(x1,y1),dist(xc,yc,x1,y1)+t1-nowans);
    //print(cir1);print(cir2);print(cir3);
    pair<point,point> a=cross(cir1,cir2);
    //print(a.w1);print(a.w2);
    if (cir2.second<0) return false;
    if (cir3.second<0) return false;
    if (inside(cross(cir1,cir2),cir3)) return true;
    if (inside(cross(cir2,cir3),cir1)) return true;
    if (inside(cross(cir3,cir1),cir2)) return true;
    if (inside(cir1.w1,cir2)&&inside(cir1.w1,cir3)) return true;
    if (inside(cir2.w1,cir1)&&inside(cir2.w1,cir3)) return true;
    if (inside(cir3.w1,cir2)&&inside(cir3.w1,cir1)) return true;
    return false;
}

int main()
{
    double t1,t2,xc,yc,x0,y0,x1,y1,l,r,m;

    //freopen("D1.in","r",stdin);
    scanf("%lf %lf",&t1,&t2);
    scanf("%lf %lf",&xc,&yc);
    scanf("%lf %lf",&x0,&y0);
    scanf("%lf %lf",&x1,&y1);
    if (dist(xc,yc,x1,y1)+dist(x1,y1,x0,y0)-dist(xc,yc,x0,y0)<=t2)
    {
        printf("%.10lf\n",min(dist(xc,yc,x1,y1)+dist(x1,y1,x0,y0)+t1,
                              dist(xc,yc,x0,y0)+t2));
        return 0;
    }

    l=0;r=300;
    while (abs(l-r)>1e-8)
    {
        m=(l+r)/2;
        if (check(m,xc,yc,x0,y0,x1,y1,t1,t2)) l=m; else r=m;
    }
    printf("%.10lf\n",m);

    return 0;
}