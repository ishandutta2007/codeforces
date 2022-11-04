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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<char> is_frined(n, 0);
    for (int i = 0; i < k; ++i) {
        int v;
        cin >> v;
        is_frined[--v] = 1;
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> closest_friend_in_subtree(n, INF);
    auto dfs_precalc = [&](auto& dfs_precalc, int v, int p = -1) -> void {
        for (auto& x : g[v]) {
            if (x == p) continue;
            dfs_precalc(dfs_precalc, x, v);
            cmin(closest_friend_in_subtree[v], closest_friend_in_subtree[x] + 1);
        }
        if (is_frined[v]) {
            closest_friend_in_subtree[v] = 0;
        }
    };
    dfs_precalc(dfs_precalc, 0);
    auto dfs_ans = [&](auto& dfs_ans, int v, int p = -1, int d = 0) -> int {
        if (closest_friend_in_subtree[v] <= d) {
            return 1;
        }
        if (p != -1 && len(g[v]) == 1) {
            return -1;
        }
        int sm = 0;
        for (auto& x : g[v]) {
            if (x == p) continue;
            int ret = dfs_ans(dfs_ans, x, v, d + 1);
            if (ret == -1) {
                return -1;
            }
            sm += ret;
        }
        return sm;
    };
    cout << dfs_ans(dfs_ans, 0) << '\n';
}