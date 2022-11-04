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
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto& x : p) {
        cin >> x;
        --x;
    }
    vector<int> perm(n);
    for (auto& x : perm) {
        cin >> x;
        --x;
    }
    if (p[perm[0]] != perm[0]) {
        cout << "-1\n";
        return;
    }
    vector<int> back_perm(n);
    for (int i = 0; i < n; ++i) {
        back_perm[perm[i]] = i;
    }
    vector<vector<int>> pos(n);
    for (int i = 0; i < n; ++i) {
        if (i == p[i]) continue;
        pos[p[i]].pb(i);
    }
    {
        vector<int> mn_in_subtree = back_perm;
        auto dfs = [&](auto& dfs, int v) -> void {
            for (auto& x : pos[v]) {
                dfs(dfs, x);
                cmin(mn_in_subtree[v], mn_in_subtree[x]);
            }
        };
        dfs(dfs, perm[0]);
        if (mn_in_subtree != back_perm) {
            cout << "-1\n";
            return;
        }
    }
    vector<ll> dist(n, 0);
    vector<int> ans(n, 0);
    ll mx = 0;
    for (auto& x : perm) {
        if (p[x] == x) continue;
        ans[x] = max(int(mx - dist[p[x]] + 1), 1);
        cmax(mx, dist[x] = dist[p[x]] + ans[x]);
    }
    for (auto& x : ans) {
        cout << x << " ";
    }
    cout << endl;
}