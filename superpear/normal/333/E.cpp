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
#include <ctime>

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

const int maxn=3005;

int x[maxn],y[maxn],tu[maxn],xc[maxn],yc[maxn],xe[maxn],u[maxn],flag[maxn];
PII ls[maxn];
int N,xx,yy,tt=0;
vector<int> v[maxn];
double q3,area;

inline double dist(int x1,int y1,int x2,int y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

inline double dist(int x1,int y1,int x2,int y2,int x3,int y3)
{
    q3=dist(x2,y2,x3,y3);
    area=(x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);
    return abs(area/q3);
}

inline int cross(int x1,int y1,int x2,int y2,int x3,int y3)
{
    return ((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1));
}

inline bool cmp(PII a,PII b)
{
    if (cross(xc[1],yc[1],a.w1,a.w2,b.w1,b.w2)>0) return true; else return false;
}

inline bool check(double r)
{
    int o,q1,q2,top;
    memset(flag,0,sizeof(flag));
    int left,down,mink;
    for (int e=1;e<=N;e++)
        if (tu[e]==1)
        {
            o=0;
            for (int i=1;i<=N;i++)
                if (dist(x[i],y[i],x[e],y[e])>=r*2) flag[i]=e,++o;
            if (o<2) continue;

            left=maxlongint,down=maxlongint,mink=0;
            for (int i=1;i<=N;i++)
                if (flag[i]==e)
                    if ((y[i]<down)||((y[i]==down)&&(x[i]<left)))
                    {
                        left=x[i],down=y[i],mink=i;
                    }

            o=1,xc[1]=x[mink],yc[1]=y[mink];
            for (int i=1;i<v[mink].size();i++)
                if (flag[v[mink][i]]==e) ++o,xc[o]=x[v[mink][i]],yc[o]=y[v[mink][i]];

            top=2,u[1]=1,u[2]=2;
            for (int i=3;i<=o;i++)
            {
                while ((top>2)&&(cross(xc[u[top-1]],yc[u[top-1]],xc[i],yc[i],xc[u[top]],yc[u[top]])>0)) --top;
                ++top,u[top]=i;
            }

            o=2%top+1;
            u[top+1]=u[1];
            for (int i=1;i<=top;i++)
            {
                q1=u[i],q2=u[i+1];
                while (dist(xc[u[o%top+1]],yc[u[o%top+1]],xc[q1],yc[q1],xc[q2],yc[q2])>
                    dist(xc[u[o]],yc[u[o]],xc[q1],yc[q1],xc[q2],yc[q2]))
                        o=o%top+1;
                if (dist(xc[u[o]],yc[u[o]],xc[q1],yc[q1])>=2*r) return true;
                if (dist(xc[u[o]],yc[u[o]],xc[q2],yc[q2])>=2*r) return true;
            }
        }
    return false;
}

inline bool cct(int a,int b)
{
    if (cross(xx,yy,x[a],y[a],x[b],y[b])>0) return true; else return false;
}

int main()
{
    //freopen("E.in","r",stdin);
    //freopen("E.out","w",stdout);
    scanf("%d",&N);
    for (int i=1;i<=N;i++) scanf("%d %d",&x[i],&y[i]);

    memset(tu,0,sizeof(tu));
    int leftc=maxlongint,downc=maxlongint,minkc=0;
    for (int i=1;i<=N;i++)
        if ((y[i]<downc)||((y[i]==downc)&&(x[i]<leftc)))
        {
            leftc=x[i],downc=y[i],minkc=i;
        }

    for (int i=1;i<=N;i++)
    {
        v[i].clear();
        v[i].p_b(i);
        for (int j=1;j<=N;j++)
            if ((y[j]>y[i])||((y[j]==y[i])&&(x[j]>x[i]))) v[i].p_b(j);
        xx=x[i],yy=y[i];
        sort(v[i].begin()+1,v[i].end(),cct);
    }

    int o,top;
    o=1,xc[1]=x[minkc],yc[1]=y[minkc],xe[1]=minkc;
    for (int i=1;i<v[minkc].size();i++)
        ++o,xc[o]=x[v[minkc][i]],yc[o]=y[v[minkc][i]],xe[o]=v[minkc][i];

    top=2,u[1]=1,u[2]=2;
    for (int i=3;i<=o;i++)
    {
        while ((top>2)&&(cross(xc[u[top-1]],yc[u[top-1]],xc[i],yc[i],xc[u[top]],yc[u[top]])>0)) --top;
        ++top,u[top]=i;
    }

    for (int i=1;i<=top;i++) tu[xe[u[i]]]=1;

    double left=0,right=15000,mid;

    while (abs(left-right)>1e-6)
    {
        mid=(left+right)/2;
        if (check(mid)) left=mid; else right=mid;
    }
    printf("%.7lf\n",mid);

    //cout<<tt<<endl;

    return 0;
}