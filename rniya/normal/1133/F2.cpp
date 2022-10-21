#include <bits/stdc++.h>
using namespace std;
const int MAX_N=2e5+10;

int n,m,D;
vector<int> G[MAX_N];
int seen[MAX_N];
set<int> con;
vector<pair<int,int>> ans;
vector<pair<int,int>> edge;
vector<int> one;


void dfs(int v){
    seen[v]=1;
    for (int u:G[v]){
        if (seen[u]||!u) continue;
        ans.emplace_back(u,v);
        if (con.count(u)) edge.emplace_back(u,v);
        dfs(u);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m >> D;
    for (int i=0;i<m;++i){
        int u,v; cin >> u >> v; --u,--v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
        if (!u||!v) con.emplace(u+v);
    }
    if (G[0].size()<D){cout << "NO" << '\n'; return 0;}
    int cnt=0;
    for (int v:con) if (!seen[v]){
        dfs(v),++cnt;
        one.emplace_back(v);
    }
    if (D<cnt){cout << "NO" << '\n'; return 0;}
    cout << "YES" << '\n';
    set<pair<int,int>> erased;
    for (int i=0;i<D-cnt;++i){
        erased.emplace(edge[i]);
        one.emplace_back(edge[i].first);
    }
    for (auto p:ans){
        if (erased.count(p)) continue;
        cout << p.first+1 << ' ' << p.second+1 << '\n';
    }
    for (int u:one) cout << 1 << ' ' << u+1 << '\n';
}