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
 
const int maxn=3005;
 
int m,n,ans,maxc,rc,fc;
vector<PII> f[maxn];
string st;
int a[55][55],b[55][55];
int u[maxn*100],dis[maxn];
 
int main()
{
    cin>>m>>n;
    memset(a,0,sizeof(a));
    for (int i=1;i<=m;i++)
    {
        cin>>st;
        for (int j=1;j<=n;j++)
            if (st[j-1]=='B') a[i][j]=1; else a[i][j]=0;
    }
    memset(f,0,sizeof(f));
    memset(b,0,sizeof(b));
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            b[i][j]=(i-1)*n+j;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
        {
            if (i>1)
            {
                if (a[i][j]==a[i-1][j])
                    f[b[i][j]].p_b(m_p(b[i-1][j],0));
                else
                    f[b[i][j]].p_b(m_p(b[i-1][j],1));
            }
            if (j>1)
            {
                if (a[i][j]==a[i][j-1])
                    f[b[i][j]].p_b(m_p(b[i][j-1],0));
                else
                    f[b[i][j]].p_b(m_p(b[i][j-1],1));
            }
            if (i<m)
            {
                if (a[i][j]==a[i+1][j])
                    f[b[i][j]].p_b(m_p(b[i+1][j],0));
                else
                    f[b[i][j]].p_b(m_p(b[i+1][j],1));
            }
            if (j<n)
            {
                if (a[i][j]==a[i][j+1])
                    f[b[i][j]].p_b(m_p(b[i][j+1],0));
                else
                    f[b[i][j]].p_b(m_p(b[i][j+1],1));
            }
        }
    ans=maxlongint;
    for (int i=1;i<=m*n;i++)
    {
        memset(dis,127,sizeof(dis));
        dis[i]=0;
        rc=1,fc=1,u[rc]=i;
        while (rc<=fc)
        {
            for (int j=0;j<f[u[rc]].size();j++)
                if (dis[u[rc]]+f[u[rc]][j].w2<dis[f[u[rc]][j].w1])
                {
                    dis[f[u[rc]][j].w1]=dis[u[rc]]+f[u[rc]][j].w2;
                    ++fc,u[fc]=f[u[rc]][j].w1;
                }
            ++rc;
        }
        maxc=0;
        for (int j=1;j<=m;j++)
            for (int k=1;k<=n;k++)
                if (a[j][k]==1)
                    maxc=max(maxc,dis[b[j][k]]+1);
        ans=min(ans,maxc);
    }
    cout<<ans<<endl;
 
    return 0;
}