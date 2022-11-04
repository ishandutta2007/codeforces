// #pragma GCC optimize("Ofast,unroll-all-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
// #pragma GCC target("popcnt")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;

#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define pb push_back
#define kek pop_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
// #define int ll


const int INF = (is_same<int, ll>::value ? 1e18 + 666 : 1e9 + 666);
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

// const int MEM_SIZE = 5e8;
// char mem[MEM_SIZE];
// int cur_mem_ptr = 0;

// void* operator new(size_t n) {
//     cur_mem_ptr += n;
//     return mem + cur_mem_ptr - n;
// }

// void operator delete(void*) noexcept {}
// void operator delete(void*, size_t) noexcept {}

template<class t1, class t2>
inline bool cmin(t1 &a, const t2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class t1, class t2>
inline bool cmax(t1 &a, const t2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

inline int bpow(int a, int b, int mod) {
    int res = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            res *= a;
            res %= mod;
        }
        a *= a;
        a %= mod;
    }
    return res;
}

#ifndef LOCAL
void UseFiles(const string &s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
#else
void UseFiles(const string&) {}
#endif

void run();

signed main() {
    // UseFiles("taskname");
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

pll getVec(array<int, 4> p, int dir) {
    dir <<= 1;
    p[dir] += p[dir + 1];
    ll x = 1ll * p[0] * p[3], y = 1ll * p[2] * p[1];
    ll g = gcd(x, y);
    x /= g;
    y /= g;
    return {x, y};
}

vector<vector<pii>> g;
vector<int> used;
vector<pii> ans;

int dfs(int v, int p = -1) {
    ++used[v];
    vector<int> edges;
    for (auto& [u, e] : g[v]) {
        if (used[u] == 2) continue;
        if (used[u] == 1) {
            if (e != p) {
                edges.pb(e);
            }
        } else {
            if (int d = dfs(u, e); d == -1) {
                edges.pb(e);
            } else {
                ans.pb({e, d});
            }
        }
    }
    while (len(edges) > 1) {
        ans.pb({edges.back(), edges[len(edges) - 2]});
        edges.kek();
        edges.kek();
    }
    ++used[v];
    if (len(edges)) {
        return edges[0];
    }
    return -1;
}

void run() {
    int m;
    cin >> m;
    vector<pair<pll, pll>> vecs(m);
    vector<pll> crd;
    for (auto& [v1, v2] : vecs) {
        array<int, 4> vec;
        for (auto& x : vec) {
            cin >> x;
        }
        crd.pb(v1 = getVec(vec, 0));
        crd.pb(v2 = getVec(vec, 1));
    }
    sort(all(crd));
    crd.resize(unique(all(crd)) - crd.begin());
    auto idx = [&crd](pll x) {
        return (int)(lower_bound(all(crd), x) - crd.begin());
    };

    int n = len(crd);
    g.resize(n);
    used.resize(n, 0);
    for (int i = 0; i < m; ++i) {
        int u = idx(vecs[i].first), v = idx(vecs[i].second);
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) dfs(i);
    }
    cout << len(ans) << endl;
    for (auto& [a, b] : ans) {
        cout << a + 1 << " " << b + 1 << endl;
    }
}