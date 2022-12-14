#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool in[1000000];
bool vis[1000000];
bool adj[1001][1001];
int par[1000000];
int n;
vector<pair<int,int> > pos;
void dfs(int v)
{
    vis[v]=1;
    in[v]=1;
    for (int u=1;u<=n;u++) {
        if (adj[v][u]==0)continue;
        if (vis[u] && in[u] && pos.size()==0) {
            int x = v;
            while(x!=u) {
                pos.push_back({par[x],x});
                x=par[x];
            }
            pos.push_back({v,u});
        }
        if (vis[u])continue;
        par[u]=v;
        dfs(u);
    }
    in[v]=0;
}
bool has=0;
void cycle(int v)
{
    vis[v]=1;
    in[v]=1;
    for (int u=1;u<=n;u++) {
        if (adj[v][u]==0)continue;
        if (vis[u] && in[u]) {
            has=1;
        }
        if (vis[u])continue;
        cycle(u);
    }
    in[v]=0;
}
bool ok=0;
void check_cycle() {
    has=0;
    memset(vis,0,sizeof(vis));
    memset(in,0,sizeof(in));
    for (int i=1;i<=n;i++) {
        if (!vis[i])cycle(i);
    }
    if (!has)ok=1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int m;
    cin>>n>>m;
    for (int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
    }
    for (int i=1;i<=n;i++) {
        if (!vis[i])dfs(i);
    }
    for (auto p:pos){
        adj[p.first][p.second]=0;
        check_cycle();
        adj[p.first][p.second]=1;
    }
    if (ok || pos.size()==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}