#include <bits/stdc++.h>
using namespace std;
int n,m;
int ret=1000000000;
pair<int,pair<int,char> > edges[1000000];
bool is[1000000];
int group[1000000];
int sz[1000000];
vector<int> G[1000000];
vector<int> adj[1000000];
bool vis[1000000];
vector<int> cc[2];
int col[1000000];
void add(int u,int v)
{
    sz[v]+=sz[u];
    sz[u]=0;
    for (auto x:G[u])
    {
        group[x]=v;
        G[v].push_back(x);
    }
    G[u].clear();
}
void dsu(int x,int y)
{
    int u=group[x],v=group[y];
    if (u==v)return;
    if (G[u].size()<G[v].size())
        add(u,v);
    else
        add(v,u);
}
bool ok=1;
void dfs(int v,int color=0)
{
    col[v]=color;
    cc[color].push_back(v);
    vis[v]=1;
    for (auto u:adj[v])
    {
        if (!vis[u])
            dfs(u,1-color);
        else
        {
            if (col[u]==col[v])
                ok=0;
        }
    }
}
void solve()
{
    int sol=0;
    ok=1;
    for (int i=1;i<=n;i++)
    {
        vis[i]=0;
        G[i].clear();G[i].push_back(i);
        sz[i]=1;
        adj[i].clear();
        group[i]=i;
    }
    for (int i=0;i<m;i++)
    {
        int u = edges[i].first;
        int v = edges[i].second.first;
        char c = edges[i].second.second;
        if (c=='R')
            dsu(u,v);
    }
    for (int i=0;i<m;i++)
    {
        int u = edges[i].first;
        int v = edges[i].second.first;
        char c = edges[i].second.second;
        if (c=='B')
        {
            if (group[u]==group[v])return;
            adj[group[u]].push_back(group[v]),adj[group[v]].push_back(group[u]);
        }
    }
    for (int i=1;i<=n;i++)
    {
        if (!vis[group[i]])
        {
            cc[0].clear();
            cc[1].clear();
            dfs(group[i]);
            if (!ok)return;
            int zero = 0,one=0;
            for (auto x:cc[0])
                zero+=sz[x];
            for (auto x:cc[1])
                one+=sz[x];
            sol+=min(one,zero);
            if (one>zero)
            {
                for (auto x:cc[0])
                    col[x]=1-col[x];
                for (auto x:cc[1])
                    col[x]=1-col[x];
            }
        }
    }
    if (sol<ret)
    {
        ret=sol;
        for (int i=1;i<=n;i++)
            is[i]=col[group[i]];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for (int i=0;i<m;i++)
        cin>>edges[i].first>>edges[i].second.first>>edges[i].second.second;
    solve();
    for (int i=0;i<m;i++)
    {
        if (edges[i].second.second=='R')edges[i].second.second='B';
        else edges[i].second.second='R';
    }
    solve();
    if (ret>1e8)
        cout<<-1<<endl;
    else
    {
        vector<int> vec;
        for (int i=1;i<=n;i++)
            if (is[i])
                vec.push_back(i);
        cout<<vec.size()<<endl;
        for (int i=0;i<vec.size();i++)
            cout<<vec[i]<<' ';
        cout<<endl;
    }

}