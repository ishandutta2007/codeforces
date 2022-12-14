#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<int,int> > adj[1000000];
ll dist[1000000];
bool vis[1000000];
int par[1000000];
int n;
void dijkstra(){
    for (int i=2;i<=n;i++) dist[i] = 1e15;
    priority_queue<pair<ll,int> > q;
    q.push({0, 1});
    while(!q.empty()){
        ll d = - q.top().first;
        int v = q.top().second;
        q.pop();
        if (vis[v])continue;
        vis[v]=1;
        for (auto [u,w]:adj[v]){
            if (d + w < dist[u]){
                par[u] = v;
                dist[u] = d + w;
                q.push({-dist[u], u});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int m;
    cin>>n>>m;
    for (int i=0;i<m;i++) {
        int u,v,w; 
        cin>>u>>v>>w;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }
    dijkstra();
    if (!vis[n]){
        cout<<-1<<endl;
        return 0;
    }
    int v = n;
    vector<int> path;
    while(v!=0){
        path.push_back(v);
        v = par[v];
    }
    reverse(path.begin(),path.end());
    for (auto x:path)cout<<x<<' ';
    cout<<endl;
}