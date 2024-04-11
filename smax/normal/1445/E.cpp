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

const int MAX = 5e5 + 5;

template<int SZ>
struct DSU {
    int par[SZ], sz[SZ];
    bool color[SZ];
    vector<pair<int, bool>> stk;

    void init(int n) {
        for (int i=0; i<n; i++) {
            par[i] = i;
            sz[i] = 1;
            color[i] = false;
        }
        stk.clear();
    }

    pair<int, bool> findRoot(int u) {
        if (u == par[u])
            return {u, false};
        auto p = findRoot(par[u]);
        p.second ^= color[u];
        return p;
    }

    bool unite(int a, int b) {
        auto [u, x] = findRoot(a);
        auto [v, y] = findRoot(b);
        if (u == v)
            return x != y;
        if (sz[u] < sz[v])
            swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        stk.emplace_back(v, color[v]);
        color[v] = x ^ y ^ 1;
        return true;
    }

    void undo(int t) {
        while ((int) stk.size() > t) {
            auto [u, x] = stk.back();
            stk.pop_back();
            sz[par[u]] -= sz[u];
            par[u] = u;
            color[u] = x;
        }
    }
};

int c[MAX];
bool bad[MAX];
DSU<MAX> ds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    for (int i=0; i<n; i++) {
        cin >> c[i];
        c[i]--;
    }

    ds.init(n);
    map<pair<int, int>, vector<pair<int, int>>> mp;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (c[a] == c[b]) {
            if (!ds.unite(a, b))
                bad[c[a]] = true;
        } else {
            if (c[a] > c[b])
                swap(a, b);
            mp[{c[a], c[b]}].emplace_back(a, b);
        }
    }

    long long tot = 0;
    for (int i=0; i<k; i++)
        tot += !bad[i];
    long long ret = tot * (tot - 1) / 2;
    for (auto &[p, v] : mp)
        if (!bad[p.first] && !bad[p.second]) {
            int t = ds.stk.size();
            bool ok = true;
            for (auto &e : v)
                ok &= ds.unite(e.first, e.second);
            if (!ok)
                ret--;
            ds.undo(t);
        }
    cout << ret << "\n";

    return 0;
}