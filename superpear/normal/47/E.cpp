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

const int maxn=100005;
const double g=9.8;

int n,m,now;
double V,xc,yc,cs,t,ny,alpha,x[maxn],y[maxn];
PDI e[maxn];
PDD f[maxn],ans[maxn];

bool equal(double a,double b)
{
    if (abs(a-b)<=1e-9) return true; else return false;
}

int main()
{
    scanf("%d %lf",&n,&V);
    for (int i=1;i<=n;i++)
    {
        scanf("%lf",&cs);
        e[i]=m_p(cs,i);
    }
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%lf %lf",&xc,&yc);
        f[i]=m_p(xc,yc);
    }
    sort(f+1,f+m+1);
    sort(e+1,e+n+1);
    now=1;
    for (int i=1;i<=n;i++)
    {
        alpha=e[i].w1;
        while (now<=m)
        {
            xc=f[now].w1,yc=f[now].w2;
            t=xc/(V*cos(alpha));
            ny=V*sin(alpha)*t-0.5*g*t*t;
            if (((ny>0)&&(ny<yc))||equal(ny,yc)||equal(ny,0))
            {
                ans[e[i].w2]=m_p(xc,ny);
                break;
            }
            if (ny<0) break;
            ++now;
        }
        if ((ny<0)||(now>m))
        {
            t=V*sin(alpha)*2/g;
            ans[e[i].w2]=m_p(V*cos(alpha)*t,0);
        }
    }
    for (int i=1;i<=n;i++)
        printf("%.10lf %.10lf\n",ans[i].w1,ans[i].w2);

    return 0;
}