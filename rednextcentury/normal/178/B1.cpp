#include <bits/stdc++.h>
using namespace std;
bool viss[1000000];
int dis[1000000];
int disc[1000000];
int tim;
int low[1000000];
int pa[100004][20];
vector<int> adj[1000000];
vector<int> len[1000000];
int pp[1000000];
void dffs(int v)
{
    viss[v]=1;
    disc[v]=tim;
    low[v]=tim++;
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if (pp[v]==u)continue;
        if (viss[u]){
            low[v]=min(low[v],disc[u]);
            continue;
        }
        pp[u]=v;
        dffs(u);
        low[v]=min(low[v],low[u]);
        if (low[u]>disc[v])
            len[v][i]=1;
    }
}
bool vis[1000000];
int cur[1000000];
int lvl[1000000];
void dfs(int v,int lev)
{
    lvl[v]=lev;
    vis[v]=1;
    cur[lev]=v;
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if (vis[u]){
            continue;
        }
        dis[u]=dis[v]+len[v][i];
        dfs(u,lev+1);
    }
    for (int i=0;i<20;i++)
    {
        if (lev-(1<<i)>=0)
            pa[v][i]=cur[lev-(1<<i)];
    }
}
int LCA(int u,int v)
{
    if (lvl[u]>lvl[v])
        swap(u,v);
    int x=lvl[v]-lvl[u];
    for (int i=0;i<20;i++)
        if (x & (1<<i))
            v=pa[v][i];
    if (u==v)
        return v;
    for (int i=19;i>=0;i--)
        if (pa[v][i]!=pa[u][i])
            v=pa[v][i],u=pa[u][i];
    return pa[v][0];
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
        len[x].push_back(0);
        len[y].push_back(0);
    }
    dffs(1);
    dfs(1,0);
    int k;
    scanf("%d",&k);
    while(k--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        int x=LCA(u,v);
        printf("%d\n",dis[u]+dis[v]-2*dis[x]);
    }
}