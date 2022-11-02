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

const int maxn=105;

vector<int> must[maxn],lsb[maxn];
vector<int> f[maxn];
int n,m,xc,yc,start,over,k,tc,td,ans;
int dp[maxn][maxn],maps[maxn][maxn],vis[maxn][maxn];
PII bus[maxn];

int getdis(int xc,int yc,int k)
{
    int rc,fc,cs;
    int dis[maxn],u[maxn];

    if (k==xc) return maxlongint;
    memset(dis,127,sizeof(dis));
    dis[xc]=0;
    rc=1,fc=1,u[rc]=xc;
    while (rc<=fc)
    {
        for (int i=0;i<f[u[rc]].size();i++)
        {
            cs=f[u[rc]][i];
            if ((cs!=k)&&(dis[u[rc]]+1<dis[cs]))
            {
                dis[cs]=dis[u[rc]]+1;
                ++fc,u[fc]=cs;
            }
        }
        ++rc;
    }
    return dis[yc];
}

void search(int nplace,int nbus)
{
    if (vis[nplace][nbus]==1) return;
    vis[nplace][nbus]=1;

    int ct=-1,cs;
    for (int i=0;i<f[nplace].size();i++)
    {
        cs=f[nplace][i];
        //if ((n==36)&&(nplace==1)&&(nbus==50))
        //    cout<<cs<<" "<<bus[nbus].w2<<" "<<maps[cs][bus[nbus].w2]<<" "<<maps[nplace][bus[nbus].w2]<<endl;
        if (maps[cs][bus[nbus].w2]+1==maps[nplace][bus[nbus].w2])
        {
            search(cs,nbus);
            ct=max(ct,dp[cs][nbus]);
        }
    }
    if (ct!=-1) dp[nplace][nbus]=min(dp[nplace][nbus],ct);
    for (int i=0;i<lsb[nplace].size();i++)
    {
        cs=lsb[nplace][i];
        search(nplace,cs);
        dp[nplace][nbus]=min(dp[nplace][nbus],dp[nplace][cs]+1);
    }
}

int main()
{
    scanf("%d %d %d %d",&n,&m,&start,&over);
    memset(maps,127,sizeof(maps));
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d",&xc,&yc);
        f[xc].p_b(yc);
        maps[xc][yc]=1;
    }
    scanf("%d",&k);
    for (int i=1;i<=k;i++)
    {
        scanf("%d %d",&xc,&yc);
        bus[i]=m_p(xc,yc);
    }

    for (int i=1;i<=n;i++) maps[i][i]=0;
    for (int t=1;t<=n;t++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if ((maps[i][t]!=biglongint)&&(maps[t][j]!=biglongint))
                    maps[i][j]=min(maps[i][j],maps[i][t]+maps[t][j]);

    for (int i=1;i<=k;i++)
    {
        xc=bus[i].w1,yc=bus[i].w2;
        tc=getdis(xc,yc,-1);
        int flag=0;
        for (int j=1;j<=n;j++)
        {
            td=getdis(xc,yc,j);
            if (td!=tc) must[i].p_b(j),lsb[j].p_b(i);
        }
    }

    //if (n==36) for (int i=0;i<must[50].size();i++) cout<<must[50][i]<<"  ";cout<<endl;
    /*
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<lsb[i].size();j++) cout<<lsb[i][j]<<" ";
        cout<<endl;
    }
    */

    memset(dp,127,sizeof(dp));
    for (int tt=1;tt<=100;tt++)
    {
        memset(vis,0,sizeof(vis));
        for (int i=0;i<lsb[over].size();i++)
            dp[over][lsb[over][i]]=1,vis[over][lsb[over][i]]=1;
        for (int i=0;i<lsb[start].size();i++)
            search(start,lsb[start][i]);
    }

    ans=maxlongint;
    for (int i=0;i<lsb[start].size();i++)
        ans=min(ans,dp[start][lsb[start][i]]);
    if (ans>=biglongint/2) ans=-1;
    printf("%d\n",ans);

    return 0;
}