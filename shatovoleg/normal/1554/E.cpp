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

// #define TASK "magic"

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
    int t;
    cin >> t;
    while (t --> 0) {
        solve();
    }
}

constexpr int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> order;
    order.reserve(n);
    vector<vector<int>> ch(n);
    {
        vector<pii> st;
        st.emplace_back(0, -1);
        while (len(st)) {
            auto [v, p] = st.back();
            order.pb(v);
            st.kek();
            for (auto& u : g[v]) {
                if (u == p) continue;
                st.emplace_back(u, v);
                ch[v].pb(u);
            }
        }
        reverse(all(order));
    }
    vector<int> dp(n);
    vector<int> ans(n + 1, 0);
    ans[1] = bpow(2, n - 1, mod);

    auto check = [&order, &ch, &dp, &g](int k) {
        for (auto& v : order) {
            int deg = len(g[v]);
            for (auto& u : ch[v]) {
                deg -= dp[u];
            }
            deg %= k;
            if (deg <= 1) {
                dp[v] = 1 - deg;
            } else {
                return 0;
            }
        }
        return dp[0];
    };

    for (int i = 2; i <= n; ++i) {
        if ((n - 1) % i) continue;
        ans[i] = check(i);
    }
    for (int i = n; i > 0; --i) {
        for (int j = 2 * i; j <= n; j += i) {
            ans[i] -= ans[j];
        }
    }
    ans.erase(ans.begin());
    for (auto& x : ans) {
        cout << x << " ";
    }
    cout << endl;
}