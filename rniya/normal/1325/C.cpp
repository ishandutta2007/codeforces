#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> deg(n,0),ans(n-1,-1);
    vector<vector<int>> G(n);
    for (int i=0;i<n-1;++i){
        int u,v; cin >> u >> v;
        G[--u].emplace_back(i);
        G[--v].emplace_back(i);
        ++deg[u]; ++deg[v];
    }
    int now=0;
    for (int v=0;v<n;++v) if (deg[v]==1){
        for (int u:G[v]) if (ans[u]==-1) ans[u]=now++;
    }
    for (int i=0;i<n-1;++i) if (ans[i]==-1) ans[i]=now++;
    for (int i=0;i<n-1;++i) cout << ans[i] << '\n';
}