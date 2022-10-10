#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<vector<int>> adj(2 * n);
    for (int i=0; i<2*n; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    vector<bool> vis(2 * n);
    vector<int> cycle;
    
    auto dfs = [&] (auto &self, int u, int p) -> void {
        vis[u] = true;
        cycle.push_back(u);
        for (int v : adj[u])
            if (v != p && v != cycle[0]) {
                self(self, v, u);
                return;
            }
    };
    
    long long ret = 0;
    for (int u=0; u<n; u++)
        if (!vis[u]) {
            cycle.clear();
            dfs(dfs, u, -1);
            // whole cycle
            int l = n - 1, r = 0, L = 2 * n - 1, R = n;
            for (int x : cycle) {
                if (x < n) {
                    l = min(l, x);
                    r = max(r, x);
                } else {
                    L = min(L, x);
                    R = max(R, x);
                }
            }
            ret += (long long) (cycle.size() + 1) / 2 * (l + 1) * (n - r) * (L - n + 1) * (2 * n - R);
            // some path in cycle
            for (int i=0; i<(int)cycle.size(); i++) {
                int bef = cycle[(i + cycle.size() - 1) % cycle.size()];
                l = n - 1, r = 0, L = 2 * n - 1, R = n;
                for (int j=i, len=0; cycle[j]!=bef; j=(j+1)%cycle.size(), len++) {
                    if (cycle[j] < n) {
                        l = min(l, cycle[j]);
                        r = max(r, cycle[j]);
                    } else {
                        L = min(L, cycle[j]);
                        R = max(R, cycle[j]);
                    }
                    int aft = cycle[(j + 1) % cycle.size()];
                    if ((bef < l || bef > r) && (bef < L || bef > R) && (aft < l || aft > r) && (aft < L || aft > R))
                        ret += (long long) (len + 1) / 2 * (l - max(bef < l ? bef : -1, aft < l ? aft : -1))
                                                         * (min({bef > r ? bef : n, aft > r ? aft : n, n}) - r)
                                                         * (L - max({bef < L ? bef : n - 1, aft < L ? aft : n - 1, n - 1}))
                                                         * (min(bef > R ? bef : 2 * n, aft > R ? aft : 2 * n) - R);
                }
            }
        }
    cout << ret << "\n";
    
    return 0;
}