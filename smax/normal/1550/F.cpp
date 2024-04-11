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
    int comp;
    vector<int> par, sz;
    vector<vector<int>> nodes;

    DSU(int n) : comp(n), par(n), sz(n, 1), nodes(n) {
        iota(par.begin(), par.end(), 0);
        for (int i=0; i<n; i++)
            nodes[i] = {i};
    }

    int find(int u) {
        return u == par[u] ? u : par[u] = find(par[u]);
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        if (sz[u] < sz[v])
            swap(u, v);
        comp--;
        par[v] = u;
        sz[u] += sz[v];
        nodes[u].insert(nodes[u].end(), nodes[v].begin(), nodes[v].end());
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, s, d;
    cin >> n >> q >> s >> d;
    s--;
    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];

    DSU dsu(n);
    vector<vector<pair<int, int>>> adj(n);
    while (dsu.comp > 1) {
        set<pair<int, int>> st;
        for (int i=0; i<n; i++)
            st.emplace(a[i], i);
        vector<array<int, 3>> edges;
        for (int i=0; i<n; i++)
            if (dsu.find(i) == i) {
                array<int, 3> mn{INT_MAX, INT_MAX, INT_MAX};
                for (int u : dsu.nodes[i])
                    st.erase({a[u], u});
                for (int u : dsu.nodes[i])
                    for (int x : {-d, d}) {
                        auto it = st.lower_bound({a[u] + x, 0});
                        if (it != st.end())
                            mn = min(mn, {abs(abs(a[u] - it->first) - d), u, it->second});
                        if (it != st.begin())
                            mn = min(mn, {abs(abs(a[u] - prev(it)->first) - d), u, prev(it)->second});
                    }
                for (int u : dsu.nodes[i])
                    st.emplace(a[u], u);
                assert(mn[0] != INT_MAX);
                edges.push_back(mn);
            }
        for (auto [w, u, v] : edges)
            if (dsu.unite(u, v)) {
                adj[u].emplace_back(v, w);
                adj[v].emplace_back(u, w);
            }
    }

    vector<int> ret(n);

    auto dfs = [&] (auto &self, int u, int p, int x) -> void {
        ret[u] = x;
        for (auto [v, w] : adj[u])
            if (v != p)
                self(self, v, u, max(x, w));
    };

    dfs(dfs, s, -1, 0);
    while (q--) {
        int i, k;
        cin >> i >> k;
        i--;
        cout << (ret[i] <= k ? "Yes" : "No") << "\n";
    }

    return 0;
}