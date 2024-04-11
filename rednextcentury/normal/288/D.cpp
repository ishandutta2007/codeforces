# include <iostream>
# include <vector>
# include <stdio.h>
#include <limits.h>
#include <stack>
#include <algorithm>
using namespace std;
vector<int> adj[1000000];
long  long  sz[1000000];
long  long  ret=0;
long  long  n;
long  long  root;
long  long  now;
long  long  go[1000000];
long  long p[1000000];
long  long  sms[1000000];
long  long  op[1000000];
long  long sum=0;
void dfs(long  long v,long  long pa)
{
    long  long m=adj[v].size();
    for (long  long i=0;i<m;i++)
    {
        long  long u=adj[v][i];
        if (u==pa)
            continue;
        p[u]=v;
        dfs(u,v);
        sz[v]+=sz[u];
    }
    long  long sm=sz[v];
    op[v]=sm;
    for (long  long i=0;i<m;i++)
    {
        long  long u=adj[v][i];
        if (u==pa)
            continue;
        sm-=sz[u];
        op[v]+=sz[u]*sm;
    }
    sz[v]++;
}
void solve(long  long v,long  long pa,long  long first)
{
    long  long m=adj[v].size();
    for (long  long i=0;i<m;i++)
    {
        long  long u=adj[v][i];
        if (u==pa)
            continue;
        long  long g;
        if (p[first]==1)
            g=first;
        else
            g=v;
        solve(u,v,g);
        if (p[u]==1)
            g=u;
        now=go[v]-(n-sz[u])*sz[u];
        ret+=(now)*(sz[u])*(sz[u]-1)/2+(op[u])*(n-sz[u])*(n-sz[u]-1)/2;
       // cout<<v<<" "<<u<<" "<<now<<endl;
    }
}
int  main()
{
    cin>>n;
    for (long  long  i=1;i<n;i++)
    {
        long  long  u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    long  long m=adj[1].size();
    for (long  long i=0;i<m;i++)
    {
        long  long u=adj[1][i];
        sum+=sz[u];
    }
    root=sum;
    for (long  long i=0;i<m;i++)
    {
        sum-=sz[adj[1][i]];
        root+=sum*sz[adj[1][i]];
    }
    sum=0;
    go[1]=root;
    for (long  long i=0;i<m;i++)
    {
        sum+=sz[adj[1][i]];
    }
    sms[1]=sum;
    //cout<<root<<endl;
    long  long sm=0;
    for (long  long j=2;j<=n;j++)
    {
        sm=0;
        long  long m=adj[j].size();
        for (long  long i=0;i<m;i++)
        {
            long  long u=adj[j][i];
            if (u==p[j])
                continue;
            sm+=sz[u];
        }
        go[j]=sm;
        sms[j]=sm;
        for (long  long i=0;i<m;i++)
        {
            if (adj[j][i]==p[j])
                continue;
            sm-=sz[adj[j][i]];
            go[j]+=sm*sz[adj[j][i]];
        }
        go[j]+=sz[j]*(n-sz[j]);
    }
    solve(1,-1,0);
    cout<<ret<<endl;
}