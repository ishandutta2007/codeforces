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

// #define TASK "codes"

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

vector<vector<pii>> g;
vector<int> color;

pair<int, int> dfs(int v, int c) {
    color[v] = c;
    int a = 1, b = 0;
    for (auto& [u, w] : g[v]) {
        if (color[u] == -1) {
            auto [aa, bb] = dfs(u, c ^ w);
            if (aa == -1) {
                return {-1, -1};
            }
            if (w) {
                swap(aa, bb);
            }
            a += aa;
            b += bb;
        } else if (color[u] != (c ^ w)) {
            return {-1, -1};
        }
    }
    return {a, b};
}

void solve() {
    int n, m;
    cin >> n >> m;
    g.assign(n, {});
    color.assign(n, -1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        string s;

        cin >> u >> v >> s;
        --u, --v;
        int val = 0;
        if (s == "imposter") {
            val = 1;
        }
        g[u].emplace_back(v, val);
        g[v].emplace_back(u, val);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (color[i] == -1) {
            auto [a, b] = dfs(i, 0);
            if (a == -1) {
                cout << -1 << endl;
                return;
            }
            ans += max(a, b);
        }
    }
    cout << ans << endl;
}