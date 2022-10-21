#include <bits/stdc++.h>
using namespace std;
const int MAX_N=2e5+10;

int n,k,col;
vector<pair<int,int>> G[MAX_N];
int ans[MAX_N];

void dfs(int v,int p,int d){
    int now=1;
    if (col<G[v].size()) for (auto e:G[v]){
        if (e.first==p) continue;
        ans[e.second]=1;
        dfs(e.first,v,ans[e.second]);
    } else for (auto e:G[v]){
        if (e.first==p) continue;
        if (now==d) ++now;
        ans[e.second]=now++;
        dfs(e.first,v,ans[e.second]);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k; cin >> n >> k;
    vector<int> deg(n,0);
    for (int i=0;i<n-1;++i){
        int u,v; cin >> u >> v;
        ++deg[--u],++deg[--v];
        G[u].emplace_back(v,i);
        G[v].emplace_back(u,i);
    }
    sort(deg.begin(),deg.end());
    reverse(deg.begin(),deg.end());
    col=deg[k];
    cout << col << '\n';
    dfs(0,-1,-1);
    for (int i=0;i<n-1;++i) cout << ans[i] << (i+1==n?'\n':' ');
}