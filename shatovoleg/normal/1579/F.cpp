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

int solve_single(const vector<int>& v) {
    int max_ln = 0, cur_ln = 0;
    for (int i = 0; i < 2; ++i) {
        for (auto& x : v) {
            ++cur_ln;
            if (x == 0) {
                cur_ln = 0;
            } else {
                cmax(max_ln, cur_ln);
            }
        }
    }
    if (cur_ln > len(v)) {
        return -1;
    }
    return max_ln;
}

void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
    }
    int g = gcd(n, d);
    int ln = n / g;
    int ans = -1;
    for (int i = 0; i < g; ++i) {
        vector<int> cur;
        cur.reserve(ln);
        int pos = i;
        for (int j = 0; j < ln; ++j) {
            cur.pb(v[pos]);
            pos += d;
            if (pos >= n) {
                pos -= n;
            }
        }
        int ret = solve_single(cur);
        if (ret == -1) {
            cout << -1 << '\n';
            return;
        }
        cmax(ans, ret);
    }
    cout << ans << '\n';
}