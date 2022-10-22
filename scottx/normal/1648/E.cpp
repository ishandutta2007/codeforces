#include <bits/stdc++.h>
 
using i64 = long long;
 
struct DSU {
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
};
 
void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::array<int, 4>> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        a--;
        b--;
        edges[i] = {c, a, b, i};
    }
    
    std::sort(edges.begin(), edges.end());
    
    std::vector<std::array<int, 3>> edges2;
    
    DSU g1(n), g2(n);
    
    std::vector<std::set<int>> comps(n), verts(n), adj(n);
    
    for (int i = 0; i < n; i++) {
        comps[i].insert(i);
        verts[i].insert(i);
    }
    for (auto [c, a, b, i] : edges) {
        adj[a].insert(b);
        adj[b].insert(a);
    }
    
    for (auto [c, a, b, i] : edges) {
        if (g1.same(a, b)) {
            continue;
        }
        
        a = g1.leader(a);
        b = g1.leader(b);
        for (auto x : comps[a]) {
            auto s = comps[b];
            for (auto y : s) {
                bool ok = false;
                for (auto u : verts[x]) {
                    for (auto v : verts[y]) {
                        if (!adj[u].count(v)) {
                            ok = true;
                            break;
                        }
                    }
                    if (ok) {
                        break;
                    }
                }
                if (ok) {
                    int v = g2.leader(x);
                    edges2.push_back({c, v, y});
                    
                    g2.merge(y, v);
                    if (g1.leader(v) == b) {
                        if (verts[v].size() > verts[y].size()) {
                            std::swap(verts[v], verts[y]);
                        }
                        for (auto u : verts[v]) {
                            verts[y].insert(u);
                        }
                        verts[v].clear();
                    }
                }
            }
            comps[b].clear();
            for (auto y : s) {
                if (g2.leader(y) == y) {
                    comps[b].insert(y);
                }
            }
        }
        
        g1.merge(b, a);
        for (auto x : comps[a]) {
            if (g2.leader(x) == x) {
                comps[b].insert(x);
            } else {
                int y = g2.leader(x);
                if (verts[x].size() > verts[y].size()) {
                    std::swap(verts[x], verts[y]);
                }
                for (auto u : verts[x]) {
                    verts[y].insert(u);
                }
                verts[x].clear();
            }
        }
        
        comps[a].clear();
    }
    
    std::vector<int> l(m, 0), r(m, n - 2);
    
    while (true) {
        bool ok = true;
        
        for (auto [c, a, b, i] : edges) {
            if (l[i] < r[i]) {
                ok = false;
            }
        }
        
        if (ok) {
            break;
        }
        
        std::sort(edges.begin(), edges.end(), [&](auto a, auto b) {
            return l[a[3]] + r[a[3]] < l[b[3]] + r[b[3]];
        });
        
        DSU g(n);
        int j = 0;
        for (auto [c, a, b, i] : edges) {
            if (l[i] == r[i]) {
                continue;
            }
            
            int mid = (l[i] + r[i]) / 2;
            
            while (j <= mid) {
                g.merge(edges2[j][1], edges2[j][2]);
                j++;
            }
            
            if (g.same(a, b)) {
                r[i] = mid;
            } else {
                l[i] = mid + 1;
            }
        }
    }
 
    for (int i = 0; i < m; i++) {
        std::cout << edges2[l[i]][0] << " \n"[i == m - 1];
    }
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}