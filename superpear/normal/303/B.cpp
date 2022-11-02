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

int gcd(int a,int b)
{
    if (b==0) return a; else return gcd(b,a%b);
}

double dis(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

bool small(int a,int b,int c,int d,int e,int f,int g,int h)
{
    if (a<e) return true;
    if (a>e) return false;
    if (b<f) return true;
    if (b>f) return false;
    if (c<g) return true;
    if (c>g) return false;
    return d<h;
}

int n,m,x,y,a,b,xc,yc,xd,yd,tt,u1,u2,v1,v2,ec;

void doit(int x1,int y1,int x2,int y2)
{
    double e1,e2;
    if (x1<0) x2-=x1,x1=0;
    if (y1<0) y2-=y1,y1=0;
    if (x2>n) x1-=(x2-n),x2=n;
    if (y2>m) y1-=(y2-m),y2=m;
    if (xc==-1)
    {
        xc=x1,yc=y1,xd=x2,yd=y2;
    }
    else
    {
        e1=dis(x,y,(xc+xd)/double(2),(yc+yd)/double(2));
        e2=dis(x,y,(x1+x2)/double(2),(y1+y2)/double(2));
        if (e2<e1) xc=x1,yc=y1,xd=x2,yd=y2; else
        if (abs(e1-e2)<1e-14)
        {
            if (small(x1,y1,x2,y2,xc,yc,xd,yd)) xc=x1,yc=y1,xd=x2,yd=y2;
        }
    }
}

int main()
{
    cin>>n>>m>>x>>y>>a>>b;
    ec=gcd(a,b);
    a/=ec,b/=ec;
    tt=min(n/a,m/b);
    a*=tt,b*=tt;
    u1=a/2,u2=a-a/2,v1=b/2,v2=b-b/2;
    xc=-1;
    doit(x-u1,y-v1,x+u2,y+v2);
    doit(x-u1,y-v2,x+u2,y+v1);
    doit(x-u2,y-v1,x+u1,y+v2);
    doit(x-u2,y-v2,x+u1,y+v1);
    cout<<xc<<" "<<yc<<" "<<xd<<" "<<yd<<endl;

    return 0;
}