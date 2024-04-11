#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

template<int SZ>
struct DSU {
    int par[SZ], sz[SZ];

    void init(int n) {
        for (int i=0; i<n; i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int findRoot(int u) {
        if (u != par[u])
            par[u] = findRoot(par[u]);
        return par[u];
    }

    bool unite(int u, int v) {
        u = findRoot(u);
        v = findRoot(v);
        if (u == v)
            return false;
        if (sz[u] < sz[v])
            swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        return true;
    }
};

int a[100005], b[100005];
DSU<200005> ds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;
    for (int i=0; i<m; i++)
        cin >> a[i];
    for (int i=0; i<n; i++)
        cin >> b[i];

    long long ret = 0;
    vector<tuple<int, int, int>> edges;
    for (int i=0; i<m; i++) {
        int s;
        cin >> s;
        while (s--) {
            int A;
            cin >> A;
            A--;
            ret += a[i] + b[A];
            edges.emplace_back(a[i] + b[A], i, A + m);
        }
    }

    sort(edges.rbegin(), edges.rend());
    ds.init(n + m);
    for (auto [w, u, v] : edges)
        if (ds.unite(u, v))
            ret -= w;
    cout << ret << "\n";

    return 0;
}