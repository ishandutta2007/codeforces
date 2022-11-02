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

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;
typedef pair<double,double> PDD;

int tt;
double R,r,k,xc,yc,qd,e1,a1,b1,c1,xu1,xu2,yu1,yu2;
PDD p1,p2;

double dis(PDD x1,PDD x2)
{
    return sqrt((x2.first-x1.first)*(x2.first-x1.first)+(x2.second-x1.second)*(x2.second-x1.second));
}

PDD back(PDD a)
{
    PDD b;
    double e=dis(a,m_p(0,0));
    b.first=a.first/(e*e);
    b.second=a.second/(e*e);
    return b;
}

int main()
{
    cin>>tt;
    for (int gb=1;gb<=tt;gb++)
    {
        cin>>R>>r>>k;
        qd=1/(2*r)-1/(2*R);
        xc=1/(2*r)-(qd/2);
        yc=k*qd;
        k=yc/xc;
        a1=k*k+1;
        b1=-2*(xc+k*yc);
        c1=xc*xc+yc*yc-qd*qd/4;
        xu1=(-b1+sqrt(b1*b1-4*a1*c1))/(2*a1);
        xu2=(-b1-sqrt(b1*b1-4*a1*c1))/(2*a1);
        yu1=k*xu1;
        yu2=k*xu2;
        p1=m_p(xu1,yu1);
        p2=m_p(xu2,yu2);
        p1=back(p1);
        p2=back(p2);
        printf("%.10lf\n",dis(p1,p2)/2);
    }
    return 0;
}