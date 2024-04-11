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


const int INF = (is_same<int, ll>::value ? 1e18l + 666 : 1e9 + 666);
const ll INFll = 1e18l + 666;
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

// #define TASK "mining"

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
    vector<vector<int>> g(n);
    for (int i = 0; i < n; ++i) {
        int l;
        cin >> l;
        g[i].resize(l);
        for (auto& x : g[i]) {
            cin >> x;
            --x;
        }
    }

    vector<int> top_sort;
    vector<char> used(n, 0);

    function<bool(int)> build_top_sort = [&top_sort, &used, &build_top_sort, &g](int v) {
        ++used[v];
        for (auto& x : g[v]) {
            if (used[x] == 2) continue;
            if (used[x] == 1 || !build_top_sort(x)) {
                return false;
            }
        }
        top_sort.pb(v);
        ++used[v];
        return true;
    };

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            if (!build_top_sort(i)) {
                cout << -1 << '\n';
                return;
            }
        }
    }

    vector<int> dp(n, 1);
    for (int i = 0; i < n; ++i) {
        int v = top_sort[i];
        for (auto& x : g[v]) {
            cmax(dp[v], dp[x] + (v < x));
        }
    }
    cout << *max_element(all(dp)) << endl;
}