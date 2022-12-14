#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector<pair<int,int> > adj[1000001];
int pa[1000001][20];
int dep[1000001];
bool vis[1000001];
long long len[1000000];
vector<int> spec;
int has[1000000];
void dfs(int v)
{
    vis[v]=1;
    for (int i=0;i<adj[v].size();i++)
    {
        pair<int,int> u = adj[v][i];
        if (vis[u.first])
        {
            if (u.first==pa[v][0])continue;
            if (++has[v]==1)
                spec.push_back(v);
            if (++has[u.first]==1)
                spec.push_back(u.first);
            continue;
        }
        pa[u.first][0]=v;
        dep[u.first]=dep[v]+1;
        len[u.first]=len[v]+u.second;
        dfs(u.first);
    }
}
int n,m;
void Init()
{
    for (int j=1;j<19;j++)
        for (int i=1;i<=n;i++)
            pa[i][j]=pa[pa[i][j-1]][j-1];
}
int LCA(int u,int v)
{
    if (dep[u]<dep[v])swap(u,v);
    int need = dep[u]-dep[v];
    for (int i=0;i<19;i++)
        if ((1<<i)&need)
            u=pa[u][i];
    if (u==v)return u;
    for (int i=18;i>=0;i--)
    {
        if (pa[u][i]==0)continue;
        if (pa[u][i]!=pa[v][i])
        {
            u=pa[u][i];
            v=pa[v][i];
        }
    }
    return pa[u][0];
}
long long getTreePath(int u,int v)
{
    int lca = LCA(u,v);
    return len[u]+len[v]-2*len[lca];
}
long long dist[45][100001];
void dijkstra(int V)
{
    for (int i=1;i<=n;i++)
        vis[i]=0,dist[V][i]=(1LL<<55);
    int v=spec[V];
    dist[V][v]=0;
    priority_queue<pair<long long,int> > q;
    q.push({0,v});
    while(!q.empty())
    {
        pair<long long,int> p = q.top();
        q.pop();
        v = p.second;
        long long d = -p.first;
        if (vis[v])continue;
        for (int i=0;i<adj[v].size();i++)
        {
            long long w = adj[v][i].second;
            int u = adj[v][i].first;
            if (dist[V][u]>d+w)
            {
                dist[V][u]=d+w;
                q.push({-dist[V][u],u});
            }
        }
    }
}
long long getBestPath(int u,int v)
{
    long long ret = getTreePath(u,v);
    for (int i=0;i<spec.size();i++)
    {
        ret=min(ret,dist[i][u]+dist[i][v]);
    }
    return ret;
}
int main()
{
    //fast;
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dfs(1);
    Init();
    int q;
    scanf("%d",&q);
    for (int i=0;i<spec.size();i++)
        dijkstra(i);
    while(q--)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        printf("%lld\n",getBestPath(u,v));
    }
//    for (int i=0)
}