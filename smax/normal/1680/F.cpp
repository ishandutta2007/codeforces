#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

struct DSU {
    bool bipartite;
    vector<int> par, sz, color;
    vector<array<int, 3>> stk;

    DSU(int n) : bipartite(true), par(n), sz(n, 1), color(n) {
        iota(par.begin(), par.end(), 0);
    }

    pair<int, int> find(int u) {
        if (u != par[u]) {
            auto [v, c] = find(par[u]);
            return {v, color[u] ^ c};
        }
        return {u, color[u]};
    }

    bool same(int u, int v) {
        return find(u).first == find(v).first;
    }

    void unite(int u, int v) {
        int x, y;
        tie(u, x) = find(u);
        tie(v, y) = find(v);
        if (u == v) {
            if (x == y) {
                stk.push_back({-1, -1, bipartite});
                bipartite = false;
            }
            return;
        }
        if (sz[u] < sz[v])
            swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        stk.push_back({v, color[v], bipartite});
        color[v] = x ^ y ^ 1;
    }

    void undo(int t) {
        while ((int) stk.size() > t) {
            auto [u, c, b] = stk.back();
            stk.pop_back();
            if (u != -1) {
                sz[par[u]] -= sz[u];
                par[u] = u;
                color[u] = c;
            }
            bipartite = b;
        }
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
        vector<pair<int, int>> edges;
        DSU dsu(n);
        for (int i=0; i<m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            edges.emplace_back(u, v);
            dsu.unite(u, v);
        }

        if (dsu.bipartite) {
            cout << "YES\n";
            for (int i=0; i<n; i++)
                cout << dsu.find(i).second;
            cout << "\n";
            continue;
        }

        vector<vector<pair<int, int>>> st(8 * m);

        auto update = [&] (auto &self, int p, int l, int r, int i, int j, int u, int v) -> void {
            if (i > r || j < l)
                return;
            if (i <= l && r <= j) {
                st[p].emplace_back(u, v);
                return;
            }
            int mid = (l + r) / 2;
            self(self, 2 * p, l, mid, i, j, u, v);
            self(self, 2 * p + 1, mid + 1, r, i, j, u, v);
        };

        auto solve = [&] (auto &self, int p, int l, int r) -> bool {
            int ti = (int) dsu.stk.size();
            for (auto [u, v] : st[p])
                dsu.unite(u, v);
            if (l == r) {
                if (l >= m && dsu.bipartite) {
                    auto [u, v] = edges[l-m];
                    if (!dsu.same(u, v) || dsu.find(u).second == dsu.find(v).second) {
                        bool one = dsu.same(u, v), flipU = dsu.find(u).second == 0, flipV = dsu.find(v).second == 0;
                        cout << "YES\n";
                        for (int i=0; i<n; i++)
                            cout << (dsu.find(i).second ^ (dsu.same(i, u) && flipU) ^ (!one && dsu.same(i, v) && flipV));
                        cout << "\n";
                        return true;
                    }
                }
            } else {
                int mid = (l + r) / 2;
                if (self(self, 2 * p, l, mid) || self(self, 2 * p + 1, mid + 1, r))
                    return true;
            }
            dsu.undo(ti);
            return false;
        };

        for (int i=0; i<m; i++) {
            update(update, 1, 0, 2 * m - 1, i, m + i - 1, edges[i].first, edges[i].second);
            update(update, 1, 0, 2 * m - 1, m + i + 1, 2 * m - 1, edges[i].first, edges[i].second);
        }
        dsu.undo(0);
        if (!solve(solve, 1, 0, 2 * m - 1))
            cout << "NO\n";
    }

    return 0;
}