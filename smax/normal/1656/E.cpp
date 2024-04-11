#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n);
        for (int i=0; i<n-1; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> color(n);
        
        auto dfs = [&] (auto &self, int u, int p) -> void {
            for (int v : adj[u])
                if (v != p) {
                    color[v] = !color[u];
                    self(self, v, u);
                }
        };
        
        dfs(dfs, 0, -1);
        for (int i=0; i<n; i++)
            cout << (color[i] ? 1 : -1) * (int) adj[i].size() << " ";
        cout << "\n";
    }
    
    return 0;
}