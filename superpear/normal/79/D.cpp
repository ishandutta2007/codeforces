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

int N,K,L,cs,rc,fc,flag;
int a[25],b[250];
vector<int> f[10005];
int dp[1100001],dis[25][10005],u[1000005];

int main()
{
    //freopen("D.in","r",stdin);
    scanf("%d %d %d",&N,&K,&L);
    for (int i=1;i<=K;i++)
    {
        scanf("%d",&cs);
        a[i*2-1]=cs;
        a[i*2]=cs+1;
    }
    for (int i=1;i<=L;i++) scanf("%d",&b[i]);
    K*=2;
    for (int i=1;i<=N+1;i++)
        for (int j=1;j<=L;j++)
            if (i+b[j]<=N+1)
            {
                f[i].p_b(i+b[j]);
                f[i+b[j]].p_b(i);
            }
    memset(dis,127,sizeof(dis));
    for (int i=1;i<=K;i++)
    {
        rc=1,fc=1,u[rc]=a[i],dis[i][a[i]]=0;
        while (rc<=fc)
        {
            for (int j=0;j<f[u[rc]].size();j++)
                if (dis[i][u[rc]]+1<dis[i][f[u[rc]][j]])
                {
                    ++fc;
                    u[fc]=f[u[rc]][j];
                    dis[i][f[u[rc]][j]]=dis[i][u[rc]]+1;
                }
            ++rc;
        }
    }
    memset(dp,127,sizeof(dp));
    dp[0]=0;
    for (int i=0;i<(1<<K)-1;i++)
        if (dp[i]!=biglongint)
        {
            flag=0;
            for (int j=1;j<=K;j++)
                if ((i>>(j-1))%2==0)
                 {
                    flag=j;
                    break;
                }
            for (int j=flag+1;j<=K;j++)
                if ((i>>(j-1))%2==0)
                {
                    cs=i+(1<<(flag-1))+(1<<(j-1));
                    dp[cs]=min(dp[cs],dp[i]+dis[flag][a[j]]);
                }
        }
    if (dp[(1<<K)-1]==biglongint) printf("-1\n"); else printf("%d\n",dp[(1<<K)-1]);

    return 0;
}