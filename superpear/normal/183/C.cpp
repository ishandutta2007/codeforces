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

const int maxn=100005;

int N,M,xc,yc,huan;
int vis[maxn],a[maxn],u[maxn];
vector<PII> f[maxn];

void dfs(int s,int fa,int depth)
{
    vis[s]=depth;
    int cs;
    for (int i=0;i<f[s].size();i++)
        if (f[s][i].w1!=fa)
        {
            cs=f[s][i].w1;
            if ((vis[cs]!=biglongint)&&(vis[cs]!=vis[s]+f[s][i].w2))
            {
                huan=abs(vis[cs]-(vis[s]+f[s][i].w2));
                return;
            }
            if (vis[cs]==biglongint)
                dfs(cs,s,depth+f[s][i].w2);
        }
}

bool check(int color)
{
    memset(a,0,sizeof(a));
    PII cs;
    int rc,fc,tt;
    for (int i=1;i<=N;i++)
        if (a[i]==0)
        {
            rc=1,fc=1,u[rc]=i,a[i]=1;
            while (rc<=fc)
            {
                for (int j=0;j<f[u[rc]].size();j++)
                {
                    cs=f[u[rc]][j];
                    if (a[cs.w1]==0)
                    {
                        a[cs.w1]=(a[u[rc]]+cs.w2+color-1)%color+1;
                        ++fc,u[fc]=cs.w1;
                    }
                    else
                    {
                        tt=(a[u[rc]]+cs.w2+color-1)%color+1;
                        if (tt!=a[cs.w1]) return false;
                    }
                }
                ++rc;
            }
        }
    return true;
}

int main()
{
    scanf("%d %d",&N,&M);
    for (int i=1;i<=M;i++)
    {
        scanf("%d %d",&xc,&yc);
        f[xc].p_b(m_p(yc,1));
        f[yc].p_b(m_p(xc,-1));
    }
    huan=-1;
    memset(vis,127,sizeof(vis));
    for (int i=1;i<=N;i++)
        if (vis[i]==biglongint)
        {
            dfs(i,0,1);
            if (huan!=-1) break;
        }

    if (huan==-1) printf("%d\n",N); else
    {
        for (int i=huan;i>=1;i--)
            if ((huan%i==0)&&(check(i)))
            {
                printf("%d\n",i);
                break;
            }
    }


    return 0;
}