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
    vector<vector<int>> c(2 * n, vector<int>(2 * n));
    for (auto& line : c) {
        for (auto& x : line) {
            cin >> x;
        }
    }
    ll sm = 0;
    for (int i = n; i < 2 * n; ++i) {
        for (int j = n; j < 2 * n; ++j) {
            sm += c[i][j];
        }
    }
    int mn = INF;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if ((i + j) % 2 == 0) continue;
            int dx = n * i, dy = n * j;
            for (int mx = 0; mx < 2; ++mx) {
                for (int my = 0; my < 2; ++my) {
                    cmin(mn, c[dx + mx * (n - 1)][dy + my * (n - 1)]);
                }
            }
        }
    }
    cout << sm + mn << endl;
}