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

constexpr int mod = 1e9 + 7;
constexpr int r2 = mod - mod / 2;

vector<int> fact, rev, rfact;

void init(int n) {
    ++n;
    fact.resize(n, 1);
    rfact.resize(n, 1);
    rev.resize(n, 1);
    rev[0] = 0;

    for (int i = 2; i < n; ++i) {
        fact[i] = int(1ll * fact[i - 1] * i % mod);
        rev[i] = mod - int(1ll * (mod / i) * rev[mod % i] % mod);
        rfact[i] = int(1ll * rfact[i - 1] * rev[i] % mod);
    }
}

int C(int n, int k) {
    int denom = int(1ll * rfact[k] * rfact[n - k] % mod);
    return int(1ll * fact[n] * denom % mod);
}

void run() {
    init(1e6 + 1);
    int n;
    cin >> n;
    while (n --> 0) {
        solve();
    }
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if (m == 0) {
        cout << 0 << '\n';
        return;
    }
    if (n == m) {
        cout << 1ll * m * k % mod << '\n';
        return;
    }
    ll sum = 0;
    for (int i = 0; i <= m; ++i) {
        sum += 1ll * C(n - i - 1, m - i) * bpow(r2, n - i, mod) % mod * i;
        if (sum >= 1ll * mod * mod) {
            sum %= mod;
        }
    }
    sum %= mod;
    cout << sum * k % mod << endl;
}