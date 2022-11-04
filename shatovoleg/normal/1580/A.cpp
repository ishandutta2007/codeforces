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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> fld(n);
    for (auto& x : fld) {
        cin >> x;
    }
    vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            pref[i + 1][j + 1] = pref[i + 1][j] + fld[i][j] - '0';
        }
    }
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            pref[i + 1][j + 1] += pref[i][j + 1];
        }
    }
    auto get_sum = [&pref](int l1, int r1, int l2, int r2) {
        return pref[r1][r2] - pref[l1][r2] - pref[r1][l2] + pref[l1][l2];
    };
    int ans = INF;
    for (int top = 0; top < n; ++top) {
        for (int bot = top + 4; bot < n; ++bot) {
            vector<int> add(m), sub(m);
            for (int i = 0; i < m; ++i) {
                add[i] = (i - get_sum(top, top + 1, 0, i)) + (i - get_sum(bot, bot + 1, 0, i))
                       + get_sum(top + 1, bot, 0, i) + (bot - top - 1 - get_sum(top + 1, bot, i, i + 1));
                sub[i] = (i + 1 - get_sum(top, top + 1, 0, i + 1)) + (i + 1 - get_sum(bot, bot + 1, 0, i + 1))
                       + get_sum(top + 1, bot, 0, i + 1) - (bot - top - 1 - get_sum(top + 1, bot, i, i + 1));
            }
            for (int i = 1; i < m; ++i) {
                cmax(sub[i], sub[i - 1]);
            }
            for (int i = 3; i < m; ++i) {
                cmin(ans, add[i] - sub[i - 3]);
            }
        }
    }
    cout << ans << endl;
}