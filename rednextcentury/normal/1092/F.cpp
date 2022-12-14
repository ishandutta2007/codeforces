#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000000];
vector<int> adj[1000000];
ll sum[1000000];
ll tot[1000000];
void dfs(int v,int p){
    sum[v]=a[v];
    for (auto u:adj[v]){
        if (u==p)continue;
        dfs(u,v);
        sum[v]+=sum[u];
        tot[v]+=tot[u]+sum[u];
    }
}
ll ret[1000000];
ll mx = 0;
void dfs2(int v, ll S, ll T,int pa){
    ret[v]=tot[v]+T;
    mx=max(mx,ret[v]);
    for (auto u:adj[v]){
        if (u==pa)continue;
        dfs2(u, S + sum[v] - sum[u], T + tot[v] - tot[u]  - sum[u] +  S + sum[v]-sum[u], v);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)cin>>a[i];
    for (int i=0;i+1<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    dfs2(1,0,0,0);
    cout<<mx<<endl;
}