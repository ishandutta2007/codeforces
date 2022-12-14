#include <bits/stdc++.h>
using namespace std;
#define ll long long
int st[1000000];
int en[1000000];
int dx[1000000];
int col[1000000];
vector<int> adj[1000000];
bool vis[1000000];
bool bipartite=1;
void dfs(int v,int c) {
    vis[v]=1;
    col[v]=c;
    for (auto u:adj[v]) {
        if (vis[u] && col[u]==col[v]) bipartite=0;
        if (vis[u]) continue;
        dfs(u, 1-c);
    }
}
int main(){
    ios_base::sync_with_stdio(0);

    int t;
    cin>>t;
    while(t--){
        bipartite=1;
        int n, m;
        cin>>n>>m;
        for (int i=1;i<=n;i++) {
            cin>>st[i];
            vis[i]=0;
            adj[i].clear();
        }
        for (int i=1;i<=n;i++) {
            cin>>en[i];
            dx[i] = en[i]-st[i];
        }
        for (int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, 1);
        ll sum=0;
        if (bipartite) {
            for (int i=1;i<=n;i++) if (col[i]==1) sum += dx[i]; else sum -= dx[i];
            if (sum==0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        } else {
            for (int i=1;i<=n;i++) {
                if (abs(dx[i])%2) sum++;
            }
            if (sum%2==0)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}