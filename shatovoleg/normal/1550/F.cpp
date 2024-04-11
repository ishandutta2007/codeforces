// #pragma GCC optimize("Ofast,unroll-all-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
// #pragma GCC target("popcnt")

#include <bits/stdc++.h>
#include <unistd.h>

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

inline int bpow(ll a, ll b, int mod) {
    int res = 1;
    a %= mod;
    for (; b; b >>= 1) {
        if (b & 1) {
            res = int((1ll * a * res) % mod);
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

struct Dsu {
    Dsu(int n) : l(n), r(n, 1) {
        iota(all(l), 0);
    }

    int get_root(int v) {
        if (l[v] == v) {
            return v;
        }
        return l[v] = get_root(l[v]);
    }

    bool Union(int u, int v) {
        u = get_root(u);
        v = get_root(v);
        if (u == v) {
            return false;
        }
        if (r[u] > r[v]) {
            swap(u, v);
        }
        l[u] = v;
        r[v] += r[u];
        return true;
    }

    vector<int> l, r;
};

void run() {
    int n, q, s, d;
    cin >> n >> q >> s >> d;
    --s;
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
    }
    auto get_dist = [&v, d](int i, int j) {
        if (i < j) {
            return abs(v[i] + d - v[j]);
        }
        return abs(v[i] - d - v[j]);
    };
    vector<array<int, 3>> edges;
    Dsu dsu(n);
    vector<int> crd(n);
    vector<vector<int>> comps;
    set<pii> elems;
    for (int i = 0; i < n; ++i) {
        elems.emplace(v[i], i);
    }
    while (len(edges) != n - 1) {
        fill(all(crd), -1);
        int c = 0;
        for (int i = 0; i < n; ++i) {
            if (int r = dsu.get_root(i); crd[r] == -1) {
                crd[r] = c++;
            }
        }
        comps.resize(c);
        for (int i = 0; i < n; ++i) {
            comps[crd[dsu.get_root(i)]].pb(i);
        }
        vector<array<int, 3>> cedges;
        cedges.reserve(c);
        for (auto& comp : comps) {
            for (auto& i : comp) {
                elems.erase({v[i], i});
            }
            array<int, 3> edge = {INF, -1, -1};
            auto relax = [&edge, &get_dist, &elems, n](int i, int crd) {
                auto it = elems.lower_bound({crd, -1});
                if (it != elems.end() && it->second != i) {
                    cmin(edge, array<int, 3>{get_dist(i, it->second), i, it->second});
                }
                if (it == elems.begin()) return;
                --it;
                if (it->second != i) {
                    cmin(edge, array<int, 3>{get_dist(i, it->second), i, it->second});
                }
            };
            for (auto& i : comp) {
                relax(i, v[i] + d);
                relax(i, v[i] - d);
            }
            for (auto& i : comp) {
                elems.emplace(v[i], i);
            }
            cedges.pb(edge);
        }
        for (auto& [w, u, v] : cedges) {
            if (dsu.Union(u, v)) {
                edges.push_back({u, v, w});
            }
        }
        comps.clear();
    }

    vector<vector<pii>> g(n);
    for (auto& [u, v, w] : edges) {
        g[u].pb({v, w});
        g[v].pb({u, w});
    }

    vector<int> path_max(n, 0);
    function<void(int, int)> dfs = [&dfs, &g, &path_max](int v, int p) {
        for (auto& [u, w] : g[v]) {
            if (u == p) continue;
            path_max[u] = max(path_max[v], w);
            dfs(u, v);
        }
    };
    dfs(s, -1);

    for (int i = 0; i < q; ++i) {
        int v, w;
        cin >> v >> w;
        --v;
        if (w >= path_max[v]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}