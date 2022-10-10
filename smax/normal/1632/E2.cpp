#include <bits/stdc++.h>
using namespace std;

const int LOG = 19;

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
        
        vector<int> depth(n);
        vector<vector<int>> up(LOG, vector<int>(n, -1)), nodes(n);
        
        auto dfs1 = [&] (auto &self, int u, int p, int d) -> void {
            depth[u] = d;
            up[0][u] = p;
            nodes[d].push_back(u);
            for (int v : adj[u])
                if (v != p)
                    self(self, v, u, d + 1);
        };
        
        dfs1(dfs1, 0, -1, 0);
        for (int i=1; i<LOG; i++)
            for (int j=0; j<n; j++)
                if (up[i-1][j] != -1)
                    up[i][j] = up[i-1][up[i-1][j]];
        
        auto lca = [&] (int u, int v) -> int {
            if (depth[u] < depth[v])
                swap(u, v);
            for (int i=LOG-1; i>=0; i--)
                if (depth[u] - (1 << i) >= depth[v])
                    u = up[i][u];
            if (u == v)
                return u;
            for (int i=LOG-1; i>=0; i--)
                if (up[i][u] != up[i][v]) {
                    u = up[i][u];
                    v = up[i][v];
                }
            return up[0][u];
        };
        
        auto dist = [&] (int u, int v) -> int {
            return depth[u] + depth[v] - 2 * depth[lca(u, v)];
        };
        
        int a = -1, b = -1, d = 0, mx = *max_element(depth.begin(), depth.end());
        vector<int> ret(n + 1, mx);
        for (int x=mx-1; x>0; x--) {
            for (int u : nodes[x+1]) {
                if (a == -1) {
                    a = b = u;
                    continue;
                }
                int cur = dist(a, u), cur2 = dist(b, u);
                if (cur > cur2) {
                    if (cur > d) {
                        b = u;
                        d = cur;
                    }
                } else if (cur2 > d) {
                    a = u;
                    d = cur2;
                }
            }
            if (x - (d + 1) / 2 >= 0)
                ret[x-(d+1)/2] = min(ret[x-(d+1)/2], x);
        }
        for (int i=n-1; i>0; i--)
            ret[i] = min(ret[i], ret[i+1]);
        
        for (int i=1; i<=n; i++)
            cout << ret[i] << " ";
        cout << "\n";
    }

    return 0;
}