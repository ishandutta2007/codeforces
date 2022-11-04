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


constexpr int mod = 998'244'353;
vector<int> fact, rev, rfact;
vector<vector<int>> powers;

void init(int n) {
    ++n;
    powers.resize(n, vector<int>(n, 0));
    for (int i = 1; i < n; ++i) {
        powers[i][0] = 1;
        for (int j = 1; j < n; ++j) {
            powers[i][j] = int(1ll * powers[i][j - 1] * i % mod);
        }
    }
    fact.resize(n, 1);
    rfact.resize(n, 1);
    rev.resize(n, 1);
    rev[0] = 0;

    for (int i = 2; i < n; ++i) {
        fact[i] = int(1ll * i * fact[i - 1] % mod);
        rev[i] = mod - int(1ll * (mod / i) * rev[mod % i] % mod);
        rfact[i] = int(1ll * rev[i] * rfact[i - 1] % mod);
    }
}

int C(int n, int k) {
    int denom = int(1ll * rfact[k] * rfact[n - k] % mod);
    return int(1ll * fact[n] * denom % mod);
}

void run() {
    int n, x;
    cin >> n >> x;
    init(n);
    vector<vector<int>> dp(n, vector<int>(x, 0));
    for (int i = 0; i < x; ++i) {
        dp[0][i] = i + 1;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < x; ++j) {
            if (i > j) continue;
            for (int die = 0; die <= i; ++die) {
                int mul = int(1ll * powers[i][die] * C(i + 1, die) % mod);
                dp[i][j] += int(1ll * mul * dp[i - die][j - i] % mod);
                if (dp[i][j] >= mod) {
                    dp[i][j] -= mod;
                }
            }
        }
    }
    int ans = bpow(x, n, mod) - dp.back().back();
    if (ans < 0) {
        ans += mod;
    }
    cout << ans << endl;
}