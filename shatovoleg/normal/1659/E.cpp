#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
// typedef long double ld;

#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define pb push_back
#define kek pop_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
// #define int ll

const int INF = (is_same<int, ll>::value ? 4e18l + 666 : 1e9 + 666);
const ll INFll = 4e18l + 666;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

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
    a %= mod;
    int res = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            res = int(1ll * res * a % mod);
        }
        a *= a;
        a %= mod;
    }
    return res;
}

template<class T, class U>
istream& operator>>(istream& in, std::pair<T, U>& p);

template<class T>
istream& operator>>(istream& in, vector<T>& v);

template<class T>
istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) {
        in >> x;
    }
    return in;
}

template<class T, class U>
istream& operator>>(istream& in, std::pair<T, U>& p) {
    return in >> p.first >> p.second;
}

template<class TLambda>
struct YPredicate {
    YPredicate(TLambda&& l) : l_(l) {}

    template<class... TArgs>
    auto operator()(TArgs&&... args) {
        return l_(*this, std::forward<TArgs>(args)...);
    }

private:
    TLambda l_;
};

void run();

// #define TASK "taskname"

signed main() {
#if defined(TASK) && !defined(LOCAL)
    freopen(TASK ".in", "r", stdin);
    freopen(TASK ".out", "w", stdout);
#endif
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

struct DSU {
    DSU(int n) : l(n), s(n, 1) {
        iota(all(l), 0);
    }

    int GetRoot(int v) {
        if (v == l[v]) {
            return v;
        }
        return l[v] = GetRoot(l[v]);
    }

    bool Union(int u, int v) {
        u = GetRoot(u);
        v = GetRoot(v);
        if (u == v) {
            return false;
        }
        if (s[u] > s[v]) {
            swap(u, v);
        }
        l[u] = v;
        s[v] += s[u];
        return true;
    }

    vector<int> l, s;
};

void run() {
    constexpr int bits = 30;

    int n, m;
    cin >> n >> m;
    vector<vector<pii>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }

    vector<char> has_even_edges(n, 0);
    for (int v = 0; v < n; ++v) {
        for (auto [u, w] : g[v]) {
            if ((w & 1) == 0) {
                has_even_edges[v] = 1;
            }
        }
    }

    vector<vector<char>> good_component;
    vector<DSU> components;
    for (int i = 0; i < bits; ++i) {
        components.emplace_back(n);
        good_component.emplace_back(n, 0);
        for (int v = 0; v < n; ++v) {
            for (auto [u, w] : g[v]) {
                if (w & (1 << i)) {
                    components.back().Union(v, u);
                }
            }
        }

        for (int v = 0; v < n; ++v) {
            if (!has_even_edges[v]) continue;
            good_component.back()[components.back().GetRoot(v)] = 1;
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        bool found = false;
        for (auto& dsu : components) {
            if (dsu.GetRoot(u) == dsu.GetRoot(v)) {
                found = true;
                break;
            }
        }
        if (found) {
            cout << 0 << '\n';
            continue;
        }

        found = false;
        for (int b = 1; b < bits; ++b) {
            if (good_component[b][components[b].GetRoot(u)]) {
                found = true;
                break;
            }
        }
        if (found) {
            cout << 1 << '\n';
            continue;
        }
        cout << 2 << '\n';
    }
}