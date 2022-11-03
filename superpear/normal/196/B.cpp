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

int m,n,xc,yc,xd,yd,rc,fc;
char ch;
PII start;
int a[1606][1606];
PII u[3000000];
PII vis[1606][1606];
int vi[10],vj[10];

int main()
{
    scanf("%d %d\n",&m,&n);
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
        {
            ch=getchar();
            if (ch=='#') a[i][j]=1; else
            if (ch=='.') a[i][j]=0; else
            u[1]=m_p(i,j);
        }
        ch=getchar();
    }
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            vis[i][j]=m_p(maxlongint,maxlongint);
    vis[u[1].w1][u[1].w2]=m_p(0,0);
    rc=1;fc=1;
    vi[1]=-1,vj[1]=0;
    vi[2]=0,vj[2]=-1;
    vi[3]=0,vj[3]=1;
    vi[4]=1,vj[4]=0;
    while (rc<=fc)
    {
        for (int ic=1;ic<=4;ic++)
        {
            xc=u[rc].w1+vi[ic];
            yc=u[rc].w2+vj[ic];
            xd=vis[u[rc].w1][u[rc].w2].w1;
            yd=vis[u[rc].w1][u[rc].w2].w2;
            if (xc<1) xc+=m,--xd;
            if (xc>m) xc-=m,++xd;
            if (yc<1) yc+=n,--yd;
            if (yc>n) yc-=n,++yd;
            if (a[xc][yc]==1) continue;
            if (vis[xc][yc].w1!=maxlongint)
                if (vis[xc][yc]!=m_p(xd,yd))
                {
                    cout<<"Yes"<<endl;
                    return 0;
                }
            if (vis[xc][yc].w1==maxlongint)
            {
                ++fc;
                vis[xc][yc]=m_p(xd,yd);
                u[fc]=m_p(xc,yc);
            }
        }
        ++rc;
    }

    cout<<"No"<<endl;

    return 0;
}