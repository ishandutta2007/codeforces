#include<bits/stdc++.h>
using namespace std;
char ret[1000000];
bool vis[1000000];
int V,W;
int sz[1000000];
vector<int> adj[1000000];
int full;
void pre(int v,int p)
{
    sz[v]=1;
    for (auto u:adj[v])
    {
        if (vis[u] || p==u)continue;
        pre(u,v);
        sz[v]+=sz[u];
    }
}
void get(int v,int p)
{
    int mx=0;
    for (auto u:adj[v])
    {
        if (vis[u] || p==u)continue;
        get(u,v);
        mx = max(mx,sz[u]);
    }
    mx=max(mx,full-sz[v]);
    if (mx<W)
        W=mx,V=v;
}
void sol(int v,char c)
{
    W=1000000;
    V=-1;
    pre(v,-1);
    full = sz[v];
    get(v,-1);
    ret[V]=c;
    vis[V]=1;
    for (auto u:adj[V])
    {
        if (!vis[u])
            sol(u,c+1);
    }
}
int main()
{
    int n;
    cin>>n;
    for (int i=0;i+1<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    sol(1,'A');
    for (int i=1;i<=n;i++)
        cout<<ret[i]<<' ';
    cout<<endl;
}