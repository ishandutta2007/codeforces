#include "bits/stdc++.h"

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


const int INF = (is_same<int, ll>::value ? 3e18l + 666 : 1e9 + 666);
const ll INFll = 3e18l + 666;
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

void solve();

void run() {
    int n;
    cin >> n;
    while (n --> 0) {
        solve();
    }
}

struct DSU {
    vector<int> l, s;

    DSU(int n) : l(n), s(n, 1) {
        iota(all(l), 0);
    }

    int get_root(int v) {
        if (l[v] == v) return v;
        return l[v] = get_root(l[v]);
    }

    bool Union(int u, int v) {
        u = get_root(u);
        v = get_root(v);
        if (u == v) return false;
        if (s[u] > s[v]) swap(u, v);
        l[u] = v;
        s[v] += s[u];
        return true;
    }

    void reset() {
        iota(all(l), 0);
        fill(all(s), 1);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edges(m);
    for (auto& [w, u, v] : edges) {
        cin >> u >> v >> w;
        --u, --v;
    }
    int ans = 0;
    {
        vector<array<int, 3>> tmp;
        tmp.reserve(n);
        DSU d(n);
        for (int bit = 30; bit >= 0; --bit) {
            int cnt = n;
            for (auto& [w, u, v] : edges) {
                if (!(w & (1 << bit))) {
                    tmp.pb({w, u, v});
                    cnt -= d.Union(u, v);
                }
            }
            if (cnt == 1) {
                edges.swap(tmp);
            } else {
                ans |= (1 << bit);
            }
            tmp.clear();
            d.reset();
        }
    }
    cout << ans << endl;
}