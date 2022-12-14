#include<bits/stdc++.h>
using namespace std;
vector<pair<int,long long> > adj[1000000];
long long dist[1000000];
bool vis[1000000];
int n;
void dijkstra()
{
    priority_queue<pair<long long,int> > q;
    for (int i=1;i<=n;i++)
        q.push({-dist[i],i});
    while(!q.empty())
    {
        int v = q.top().second;
        long long d = -q.top().first;
        q.pop();
        if (vis[v])continue;
        vis[v]=1;
        for (int i=0;i<adj[v].size();i++)
        {
            int u=adj[v][i].first;
            long long w = adj[v][i].second;
            if (dist[u]>d+w)
            {
                dist[u]=d+w;
                q.push({-dist[u],u});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        int u,v;
        long long w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w*2});
        adj[v].push_back({u,w*2});
    }
    for (int i=1;i<=n;i++)
        cin>>dist[i];
    dijkstra();
    for (int i=1;i<=n;i++)
        cout<<dist[i]<<' ';
}