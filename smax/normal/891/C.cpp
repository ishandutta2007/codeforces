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
    vector<int> par, sz, stk;

    DSU(int n) : par(n), sz(n, 1) {
        iota(par.begin(), par.end(), 0);
    }

    int find(int u) {
        return u == par[u] ? u : find(par[u]);
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
        par[v] = u;
        sz[u] += sz[v];
        stk.push_back(v);
        return true;
    }

    void undo(int t) {
        while ((int) stk.size() > t) {
            int u = stk.back();
            stk.pop_back();
            sz[par[u]] -= sz[u];
            par[u] = u;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edges;
    map<int, vector<int>> groups;
    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges.push_back({u, v, w});
        groups[w].push_back(i);
    }

    int q;
    cin >> q;
    map<int, map<int, vector<int>>> queries;
    for (int i=0; i<q; i++) {
        int k;
        cin >> k;
        while (k--) {
            int e;
            cin >> e;
            e--;
            queries[edges[e][2]][i].push_back(e);
        }
    }

    vector<int> ret(q, true);
    DSU dsu(n);
    for (const auto &p : groups) {
        if (queries.count(p.first))
            for (const auto &mp : queries[p.first]) {
                int t = (int) dsu.stk.size();
                for (int e : mp.second)
                    ret[mp.first] &= dsu.unite(edges[e][0], edges[e][1]);
                dsu.undo(t);
            }
        for (int e : p.second)
            dsu.unite(edges[e][0], edges[e][1]);
    }

    for (int x : ret)
        cout << (x ? "YES" : "NO") << "\n";

    return 0;
}