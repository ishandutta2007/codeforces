#include <bits/stdc++.h>
using namespace std;
int a[1000000];
vector<int> vec[200];
bool vis[100005];
int dist[100005][101];
vector<int> adj[1000000];
void bfs(int id)
{
    queue<int> q;
    for (auto x:vec[id])q.push(x),dist[x][id]=0,vis[x]=1;
    while(!q.empty())
    {
        int v = q.front();q.pop();
        for (auto u:adj[v])
        {
            if (vis[u])continue;
            vis[u]=1;
            dist[u][id]=dist[v][id]+1;
            q.push(u);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m,s,k;
    cin>>n>>m>>k>>s;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        vec[a[i]].push_back(i);
    }
    for (int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i=1;i<=k;i++)
    {
        for (int j=1;j<=n;j++)
            dist[j][i]=1e6;
        memset(vis,0,sizeof(vis));
        bfs(i);
    }
    int ret = 1e9;
    for (int i=1;i<=n;i++)
    {
        int cur=0;
        sort(dist[i]+1,dist[i]+k+1);
        for (int j=1;j<=s;j++)cur+=dist[i][j];
        cout<<cur<<' ';
    }
    cout<<endl;
}