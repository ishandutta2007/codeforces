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
    int n;
    cin >> n;
    while (n --> 0) {
        solve();
    }
}

inline int divup(int a, int b) {
    return (a + b - 1) / b;
}

vector<int> GetRations(int n) {
    vector<int> res;
    for (int i = 1; (i - 1) * (i - 1) <= n && i <= n; ++i) {
        res.pb(divup(n, i));
        res.pb(i);
    }
    sort(all(res));
    res.resize(unique(all(res)) - res.begin());
    return res;
}

void solve() {
    constexpr int mod = 998'244'353;
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
    }
    vector<int> cur_rats = GetRations(a[0]);
    vector<ll> cur_dp(len(cur_rats)), next_dp;
    for (int i = 0; i < len(cur_rats); ++i) {
        cur_dp[i] = cur_rats[i] - 1;
    }
    ll ans = cur_dp[0];
    for (int i = 1; i < n; ++i) {
        vector<int> prev_rats(move(cur_rats));
        cur_rats = GetRations(a[i]);
        next_dp.resize(len(cur_rats));
        fill(all(next_dp), 0);
        int idx = 0;
        for (int j = 0; j < len(cur_rats); ++j) {
            int denom = cur_rats[j];
            int val = a[i] / denom;
            int rat = divup(a[i - 1], val);
            while (prev_rats[idx] < rat) {
                ++idx;
            }
            next_dp[j] = cur_dp[idx];
            next_dp[j] += 1ll * (cur_rats[j] - 1) * (i + 1);
            next_dp[j] %= mod;
        }
        ans += next_dp[0];
        swap(next_dp, cur_dp);
    }
    cout << ans % mod << endl;
}