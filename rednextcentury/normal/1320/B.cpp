#include<bits/stdc++.h>
using namespace std;
#define ll long long
int s,t;
vector<int> adj[1000000];
set<int> par[1000000];
int n;
bool vis[1000000];
int dist[1000000];
void bfs(){
    for (int i=1;i<=n;i++) dist[i] = 1e9;
    dist[t]=0;
    vis[t]=1;
    queue<int> q;
    q.push(t);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for (auto u:adj[v]){
            if (dist[v]+1<dist[u]){
                dist[u] = dist[v]+1;
                par[u].clear();
                par[u].insert(v);
                q.push(u);
                vis[u]=1;
            } else if (dist[v]+1==dist[u]) par[u].insert(v);
        }
    }
}
int path[1000000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int m;
    cin>>n>>m;
    for (int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[v].push_back(u);
    }
    int len;
    cin>>len;
    for (int i=1;i<=len;i++)cin>>path[i];
    s = path[1], t = path[len];
    bfs();
    int cur = s;
    int mn=0,mx=0;
    for (int i=2;i<=len;i++){
        int has=0;
        if (par[cur].count(path[i])) has=1;
        if (par[cur].size()>has) mx++;
        if (par[cur].count(path[i])==0) mn++;
        cur = path[i];
    }
    cout<<mn<<' '<<mx<<endl;
}