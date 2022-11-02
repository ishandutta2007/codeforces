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

const double PI=3.1415926535897932384626;

bool equal(double a,double b)
{
    return abs(a-b)<=1e-9;
}

double cross(PDD c,PDD x1,PDD x2)
{
    x1.w1-=c.w1,x1.w2-=c.w2;
    x2.w1-=c.w1,x2.w2-=c.w2;
    return x1.w1*x2.w2-x1.w2*x2.w1;
}

PDD getcross(PDD x1,PDD y1,PDD x2,PDD y2)
{
    double c1=cross(x1,y2,x2);
    double c2=cross(y1,x2,y2);
    PDD q;
    q.w1=x1.w1+(y1.w1-x1.w1)/(c1+c2)*c1;
    q.w2=x1.w2+(y1.w2-x1.w2)/(c1+c2)*c1;
    return q;
}

bool iscross(PDD x1,PDD y1,PDD x2,PDD y2)
{
    PDD c=getcross(x1,y1,x2,y2);
    if (equal(c.w1,x1.w1)||(equal(c.w1,y1.w1))||((c.w1>x1.w1)&&(c.w1<y1.w1))||((c.w1>y1.w1)&&(c.w1<x1.w1)))
    if (equal(c.w1,x2.w1)||(equal(c.w1,y2.w1))||((c.w1>x2.w1)&&(c.w1<y2.w1))||((c.w1>y2.w1)&&(c.w1<x2.w1)))
    if (equal(c.w2,x1.w2)||(equal(c.w2,y1.w2))||((c.w2>x1.w2)&&(c.w2<y1.w2))||((c.w2>y1.w2)&&(c.w2<x1.w2)))
    if (equal(c.w2,x2.w2)||(equal(c.w2,y2.w2))||((c.w2>x2.w2)&&(c.w2<y2.w2))||((c.w2>y2.w2)&&(c.w2<x2.w2)))
        return true;
    return false;
}

int main()
{
    int angle;
    double w,h,ag;
    PDD x1,x2,x3,x4,y1,y2,y3,y4;

    scanf("%lf %lf %d",&w,&h,&angle);
    if ((angle==0)||(angle==180))
    {
        printf("%.10lf\n",w*h);
        return 0;
    }
    if (angle==90)
    {
        printf("%.10lf\n",min(w,h)*min(w,h));
        return 0;
    }
    ag=double(angle);
    complex <double> base(cos(ag/180*PI),sin(ag/180*PI));
    x1=m_p(w/2,h/2);
    x2=m_p(-w/2,h/2);
    x3=m_p(-w/2,-h/2);
    x4=m_p(w/2,-h/2);
    complex <double> c1(x1.w1,x1.w2);
    c1*=base;
    y1=m_p(c1.real(),c1.imag());
    complex <double> c2(x2.w1,x2.w2);
    c2*=base;
    y2=m_p(c2.real(),c2.imag());
    complex <double> c3(x3.w1,x3.w2);
    c3*=base;
    y3=m_p(c3.real(),c3.imag());
    complex <double> c4(x4.w1,x4.w2);
    c4*=base;
    y4=m_p(c4.real(),c4.imag());

    vector<PDD> z;
    if (iscross(x1,x2,y1,y2)) z.p_b(getcross(x1,x2,y1,y2));
    if (iscross(x1,x2,y2,y3)) z.p_b(getcross(x1,x2,y2,y3));
    if (iscross(x1,x2,y3,y4)) z.p_b(getcross(x1,x2,y3,y4));
    if (iscross(x1,x2,y4,y1)) z.p_b(getcross(x1,x2,y4,y1));
    if (iscross(x2,x3,y1,y2)) z.p_b(getcross(x2,x3,y1,y2));
    if (iscross(x2,x3,y2,y3)) z.p_b(getcross(x2,x3,y2,y3));
    if (iscross(x2,x3,y3,y4)) z.p_b(getcross(x2,x3,y3,y4));
    if (iscross(x2,x3,y4,y1)) z.p_b(getcross(x2,x3,y4,y1));
    if (iscross(x3,x4,y1,y2)) z.p_b(getcross(x3,x4,y1,y2));
    if (iscross(x3,x4,y2,y3)) z.p_b(getcross(x3,x4,y2,y3));
    if (iscross(x3,x4,y3,y4)) z.p_b(getcross(x3,x4,y3,y4));
    if (iscross(x3,x4,y4,y1)) z.p_b(getcross(x3,x4,y4,y1));
    if (iscross(x4,x1,y1,y2)) z.p_b(getcross(x4,x1,y1,y2));
    if (iscross(x4,x1,y2,y3)) z.p_b(getcross(x4,x1,y2,y3));
    if (iscross(x4,x1,y3,y4)) z.p_b(getcross(x4,x1,y3,y4));
    if (iscross(x4,x1,y4,y1)) z.p_b(getcross(x4,x1,y4,y1));

    //for (int i=0;i<z.size();i++) cout<<z[i].w1<<" "<<z[i].w2<<endl;

    double minc=1e10,left=1e10,ek;
    for (int i=0;i<z.size();i++)
        if ((z[i].w1<minc)||(equal(z[i].w1,minc)&&(z[i].w2<left)))
        {
            minc=z[i].w1;
            left=z[i].w2;
            ek=i;
        }
    swap(z[ek],z[0]);

    for (int i=1;i<z.size();i++)
        for (int j=i+1;j<z.size();j++)
            if (cross(z[0],z[i],z[j])<0) swap(z[i],z[j]);

    double area=0;
    z.p_b(z[0]);
    for (int i=0;i<z.size()-1;i++)
        area+=cross(m_p(0,0),z[i],z[i+1]);
    area=abs(area/2);

    printf("%.10lf\n",area);

    return 0;
}