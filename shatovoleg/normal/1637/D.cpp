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

template<class T>
istream& operator>>(istream& in, vector<T>& v) {
    for (auto& x : v) {
        in >> x;
    }
    return in;
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
    vector<int> a(n);
    cin >> a;
    vector<int> b(n);
    cin >> b;
    vector<int> diffs(n);
    for (int i = 0; i < n; ++i) {
        diffs[i] = a[i] - b[i];
    }
    constexpr int maxval = 100;
    const int m = 2 * maxval * n + 1;
    const int zero = maxval * n;
    vector<vector<char>> dp(n + 1, vector<char>(m, 0));
    vector<vector<char>> prv(n + 1, vector<char>(m, -1));
    dp[0][zero] = 1;
    for (int item = 0; item < n; ++item) {
        for (int j = 0; j < m; ++j) {
            if (!dp[item][j]) continue;
            if (j + diffs[item] >= 0 && j + diffs[item] < m) {
                dp[item + 1][j + diffs[item]] = 1;
                prv[item + 1][j + diffs[item]] = 1;
            }
            if (j - diffs[item] >= 0 && j - diffs[item] < m) {
                dp[item + 1][j - diffs[item]] = 1;
                prv[item + 1][j - diffs[item]] = 2;
            }
        }
    }
    int opt = -1;
    for (int j = 0; j < m; ++j) {
        if (!dp.back()[j]) continue;
        if (abs(j - zero) < abs(opt - zero)) {
            opt = j;
        }
    }
    for (int i = n; i > 0; --i) {
        if (prv[i][opt] == 1) {
            opt -= diffs[i - 1];
        } else {
            opt += diffs[i - 1];
            swap(a[i - 1], b[i - 1]);
        }
    }
    ll sm = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            sm += (a[i] + a[j]) * (a[i] + a[j]);
            sm += (b[i] + b[j]) * (b[i] + b[j]);
        }
    }
    cout << sm << endl;
}