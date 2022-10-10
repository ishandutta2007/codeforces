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
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adj(n);
    vector<pair<int, int>> edges;
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
        edges.emplace_back(u, v);
    }

    set<int, greater<int>> st{1, 2};
    while (*st.begin() < n)
        st.insert(*st.begin() + *next(st.begin()));

    vector<int> sz(n);
    vector<bool> cut(n);

    auto dfs1 = [&] (auto &self, int u, int p) -> void {
        sz[u] = 1;
        for (auto [v, i] : adj[u])
            if (v != p && !cut[i]) {
                self(self, v, u);
                sz[u] += sz[v];
            }
    };

    auto dfs2 = [&] (auto &self, int u, int p, int target, int tot) -> int {
        if (sz[u] == target || sz[u] == tot - target)
            return p;
        for (auto [v, i] : adj[u])
            if (i != p && !cut[i]) {
                auto ret = self(self, v, i, target, tot);
                if (ret != -1)
                    return ret;
            }
        return -1;
    };

    auto solve = [&] (auto &self, int u) -> bool {
        dfs1(dfs1, u, -1);
        if (!st.count(sz[u]))
            return false;
        if (sz[u] == 1)
            return true;
        DEBUG(u, sz[u], st, sz);
        assert(sz[u] != *st.rbegin());
        int e = dfs2(dfs2, u, -1, *st.upper_bound(sz[u]), sz[u]);
        if (e == -1)
            return false;
        cut[e] = true;
        DEBUG(edges[e]);
        return self(self, edges[e].first) && self(self, edges[e].second);
    };

    cout << (solve(solve, 0) ? "YES" : "NO") << "\n";

    return 0;
}