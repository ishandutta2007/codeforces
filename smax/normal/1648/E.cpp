#include <bits/stdc++.h>
using namespace std;

const int LOG = 18;

struct DSU {
    vector<int> par, sz;
    
    DSU(int n) : par(n), sz(n, 1) {
        iota(par.begin(), par.end(), 0);
    }

    int find(int u) {
        return par[u] == u ? u : par[u] = find(par[u]);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return true;
        if (sz[u] < sz[v])
            swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(m), b(m), c(m);
        set<pair<int, int>> st;
        for (int i=0; i<m; i++) {
            cin >> a[i] >> b[i] >> c[i];
            a[i]--, b[i]--;
            st.emplace(a[i], b[i]);
            st.emplace(b[i], a[i]);
        }
        
        vector<int> order(m);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&] (int i, int j) -> bool {
            return c[i] < c[j];
        });
        
        DSU dsu(n), complement(n);
        vector<vector<int>> nodes(n);
        vector<set<int>> comps(n);
        vector<vector<pair<int, int>>> mst(n);
        for (int i=0; i<n; i++) {
            nodes[i].push_back(i);
            comps[i].insert(i);
        }
        for (int e : order) {
            int u = dsu.find(a[e]), v = dsu.find(b[e]);
            if (u != v) {
                if (dsu.sz[u] < dsu.sz[v])
                    swap(u, v);
                if (comps[u].size() < comps[v].size())
                    comps[u].swap(comps[v]);
                dsu.unite(u, v);
                auto it = comps[v].begin();
                while (it != comps[v].end()) {
                    int w = *it;
                    bool merged = false;
                    auto it2 = comps[u].begin();
                    while (it2 != comps[u].end()) {
                        int z = *it2;
                        bool ok = false;
                        for (int x : nodes[w])
                            for (int y : nodes[z])
                                if (!st.count({x, y})) {
                                    complement.unite(w, z);
                                    if (nodes[w].size() < nodes[z].size())
                                        nodes[z].insert(nodes[z].end(), nodes[w].begin(), nodes[w].end());
                                    else
                                        nodes[w].insert(nodes[w].end(), nodes[z].begin(), nodes[z].end());
                                    mst[x].emplace_back(y, c[e]);
                                    mst[y].emplace_back(x, c[e]);
                                    ok = true;
                                    goto done;
                                }
                        done:;
                        if (ok) {
                            w = complement.find(w);
                            merged = true;
                            it2 = comps[u].erase(it2);
                        } else {
                            it2++;
                        }
                    }
                    if (merged) {
                        comps[u].insert(w);
                        it = comps[v].erase(it);
                    } else {
                        it++;
                    }
                }
                comps[u].insert(comps[v].begin(), comps[v].end());
            }
        }
        
        vector<vector<int>> up(LOG, vector<int>(n, -1)), mx(LOG, vector<int>(n));
        vector<int> depth(n);
        
        auto dfs = [&] (auto &self, int u) -> void {
            for (auto [v, w] : mst[u])
                if (v != up[0][u]) {
                    up[0][v] = u;
                    mx[0][v] = w;
                    depth[v] = depth[u] + 1;
                    self(self, v);
                }
        };
        
        dfs(dfs, 0);
        for (int i=1; i<LOG; i++)
            for (int j=0; j<n; j++)
                if (up[i-1][j] != -1) {
                    up[i][j] = up[i-1][up[i-1][j]];
                    mx[i][j] = max(mx[i-1][j], mx[i-1][up[i-1][j]]);
                }
        
        auto query = [&] (int u, int v) -> int {
            int ret = 0;
            if (depth[u] < depth[v])
                swap(u, v);
            for (int i=LOG-1; i>=0; i--)
                if (depth[u] - (1 << i) >= depth[v]) {
                    ret = max(ret, mx[i][u]);
                    u = up[i][u];
                }
            if (u == v)
                return ret;
            for (int i=LOG-1; i>=0; i--)
                if (up[i][u] != up[i][v]) {
                    ret = max({ret, mx[i][u], mx[i][v]});
                    u = up[i][u];
                    v = up[i][v];
                }
            return max({ret, mx[0][u], mx[0][v]});
        };
        
        for (int i=0; i<m; i++)
            cout << query(a[i], b[i]) << " ";
        cout << "\n";
    }
    
    return 0;
}