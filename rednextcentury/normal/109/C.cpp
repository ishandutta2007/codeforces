#include<bits/stdc++.h>
using namespace std;
bool vis[1000000];
vector<pair<int,int> > adj[1000000];
long long sz[1000000];
long long num[1000000];
bool isLucky(int X)
{
    while(X)
    {
        if (X%10!=4 && X%10!=7)
            return 0;
        X/=10;
    }
    return 1;
}
void pre(int v,int p)
{
    sz[v]=1;
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i].first;
        if (u==p)continue;
        pre(u,v);
        sz[v]+=sz[u];
        if (adj[v][i].second==1)
            num[v]+=sz[u];
        else
            num[v]+=num[u];
    }
}
long long ret=0;
void dfs(int v,long long X)
{
    long long sum=0;
    vis[v]=1;
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i].first,w=adj[v][i].second;
        if (vis[u])continue;
        if (w==1)
            dfs(u,sz[1]-sz[u]);
        else
            dfs(u,X+num[v]-num[u]);
        sum+=(w==1)?(sz[u]):(num[u]);
    }
    sum+=X;
    ret+=(sum)*(sum-1);
}
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<n;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        w=isLucky(w);
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    pre(1,-1);
    dfs(1,0);
    cout<<ret<<endl;
}