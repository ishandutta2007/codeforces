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
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> fld(n);
    for (auto& x : fld) {
        cin >> x;
    }
    vector<vector<char>> painted(n, vector<char>(m, 0));
    for (int i = n - 1; i > -1; --i) {
        for (int j = 0; j < m; ++j) {
            if (fld[i][j] == '.') continue;
            int s = min(min(i, j), m - j - 1);
            if (s < k) {
                continue;
            }
            int b = 1;
            while (b <= s && fld[i - b][j - b] == '*' && fld[i - b][j + b] == '*') ++b;
            if (b <= k) {
                continue;
            }
            painted[i][j] = 1;
            for (int l = 1; l < b; ++l) {
                painted[i - l][j + l] = painted[i - l][j - l] = 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (fld[i][j] == '*' && !painted[i][j]) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}