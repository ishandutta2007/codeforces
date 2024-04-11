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

const int maxn=400005;

vector<int> f[maxn],g[maxn];
int a[maxn],vis[maxn],u[maxn],huan[maxn],hash[maxn];
LL sum[maxn];
int n,ecj,s,rc,fc;

void dfs(int s,LL nowsum)
{
    //cout<<s<<" "<<nowsum<<endl;
    if (sum[s]>0)
    {
        ecj=s;
        return;
    }
    sum[s]=nowsum;
    int cs;
    for (int i=0;i<g[s].size();i++)
    {
        cs=g[s][i];
        if (cs<=n) dfs(cs,nowsum+a[cs]); else dfs(cs,nowsum+a[cs-n]);
    }
}

int main()
{
    //freopen("B.in","r",stdin);
    //freopen("B.out","w",stdout);
    scanf("%d",&n);
    for (int i=2;i<=n;i++) scanf("%d",&a[i]);
    s=n*2+1;
    for (int i=1;i<=n;i++)
    {
        // push i i+a[i]
        if (i+a[i]<=n)
        {
            f[i].p_b(i+a[i]+n);
            g[i+a[i]+n].p_b(i);
        }
        else
        {
            f[i].p_b(s);
            g[s].p_b(i);
        }
        // push i i-a[i]
        if (i-a[i]>0)
        {
            f[i+n].p_b(i-a[i]);
            g[i-a[i]].p_b(i+n);
        }
        else
        {
            f[i+n].p_b(s);
            g[s].p_b(i+n);
        }
    }
    //for (int i=1;i<s;i++) cout<<i<<" "<<f[i][0]<<endl;
    memset(vis,0,sizeof(vis));
    rc=1,fc=1,u[rc]=1;
    vis[1]=1;
    while (rc<=fc)
    {
        for (int i=0;i<g[u[rc]].size();i++)
            if (vis[g[u[rc]][i]]==0)
            {
                vis[g[u[rc]][i]]=1;
                ++fc,u[fc]=g[u[rc]][i];
            }
        ++rc;
    }
    memset(huan,0,sizeof(huan));
    memset(sum,0,sizeof(sum));
    dfs(s,0);
    huan[ecj]=1;
    rc=1,fc=1,u[rc]=ecj;
    while (rc<=fc)
    {
        for (int i=0;i<g[u[rc]].size();i++)
            if (huan[g[u[rc]][i]]==0)
            {
                huan[g[u[rc]][i]]=1;
                ++fc,u[fc]=g[u[rc]][i];
            }
        ++rc;
    }
    memset(hash,0,sizeof(hash));
    for (int i=1;i<s;i++)
        if (sum[i]==0)
        {
            //cout<<i<<" fdf"<<endl;
            ecj=i;
            while (hash[ecj]!=i)
            {
                hash[ecj]=i;
                ecj=f[ecj][0];
            }
            huan[ecj]=1;
            //cout<<ecj<<" fd"<<endl;
            rc=1,fc=1,u[rc]=ecj;
            while (rc<=fc)
            {
                //cout<<u[rc]<<" "<<g[u[rc]].size()<<endl;
                for (int i=0;i<g[u[rc]].size();i++)
                    if (huan[g[u[rc]][i]]==0)
                    {
                        huan[g[u[rc]][i]]=1;
                        sum[g[u[rc]][i]]=1;
                        ++fc,u[fc]=g[u[rc]][i];
                    }
                ++rc;
            }
        }
    for (int i=1;i<n;i++)
    {
        if (vis[i+1+n]==1) printf("-1\n"); else
            if (huan[i+1+n]==1) printf("-1\n"); else
                printf("%I64d\n",sum[i+1+n]+i);
    }

    return 0;
}