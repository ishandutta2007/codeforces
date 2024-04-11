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

struct DSU {
    vector<int> par, sz;

    DSU(int n) : par(n), sz(n, 1) {
        iota(par.begin(), par.end(), 0);
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
        par[v] = u;
        sz[u] += sz[v];
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    int tot = 0;
    vector<array<int, 3>> edges;
    set<pair<int, int>> edgeSet;
    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        tot ^= w;
        edges.push_back({w, u, v});
        edgeSet.emplace(u, v);
        edgeSet.emplace(v, u);
    }

    sort(edges.begin(), edges.end());
    long long zero = (long long) n * (n - 1) / 2 - m;
    set<int> st;
    for (int u=0; u<n; u++)
        st.insert(u);
    DSU dsu(n);
    for (int s=0; s<n; s++)
        if (st.count(s)) {
            queue<int> q;
            st.erase(s);
            q.push(s);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                vector<int> pending;
                for (int v : st)
                    if (!edgeSet.count({u, v}))
                        pending.push_back(v);
                for (int v : pending) {
                    st.erase(v);
                    q.push(v);
                    zero--;
                    dsu.unite(u, v);
                }
            }
        }

    long long ret = 0;
    vector<bool> used(m);
    for (int i=0; i<m; i++) {
        auto [w, u, v] = edges[i];
        if (dsu.unite(u, v)) {
            ret += w;
            used[i] = true;
        }
    }

    if (tot == 0 || zero > 0) {
        cout << ret << "\n";
        return 0;
    }

    DSU real(n);
    for (int i=0; i<m; i++) {
        auto [w, u, v] = edges[i];
        if (used[i])
            real.unite(u, v);
    }

    for (int i=0; i<m; i++) {
        auto [w, u, v] = edges[i];
        if (!used[i] && !real.same(u, v) && w < tot) {
            cout << ret + w << "\n";
            return 0;
        }
    }
    cout << ret + tot << "\n";

    return 0;
}