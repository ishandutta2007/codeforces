#include <bits/stdc++.h>
using namespace std;
int a[1000000];
bool vis[1000000];
vector<pair<int,long long> > adj[1000000];
int pa[1000000][20];
long long dist[1000000];
int lev[1000000];
void dfs(int v)
{
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i].first;
        dist[u]=dist[v]+adj[v][i].second;
        lev[u]=lev[v]+1;
        pa[u][0]=v;
        dfs(u);
    }
}
int b[1000000];
int ret[1000000];
int cur[1000000];
void lastdfs(int v)
{
    cur[v]=b[v];
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i].first;
        lastdfs(u);
        cur[v]+=cur[u];
    }
    ret[v]=cur[v];
}
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=2;i<=n;i++)
    {
        int p,w;
        cin>>p>>w;
        adj[p].push_back(make_pair(i,w+0LL));
    }
    dfs(1);
    for (int i=1;i<=18;i++)
        for (int j=1;j<=n;j++)
            pa[j][i]=pa[pa[j][i-1]][i-1];
    for (int i=1;i<=n;i++)
    {
        int v=i;
        for (int j=18;j>=0;j--)
        {
            int u=pa[v][j];
            if (u==0)continue;
            if (dist[i]-dist[u]<=a[i])
                v=u;
        }
        if (v!=i)
        {
            b[pa[i][0]]++;
            b[pa[v][0]]--;
        }
    }
    lastdfs(1);
    for (int i=1;i<=n;i++)
        cout<<ret[i]<<' ';
}