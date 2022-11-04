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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto& x : a) {
        for (auto& y : x) {
            cin >> y;
        }
    }
    vector<vector<int>> pref_min(a), pref_max(a), suff_min(a), suff_max(a);
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            cmin(pref_min[i][j], pref_min[i][j - 1]);
            cmax(pref_max[i][j], pref_max[i][j - 1]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = m - 2; j > -1; --j) {
            cmin(suff_min[i][j], suff_min[i][j + 1]);
            cmax(suff_max[i][j], suff_max[i][j + 1]);
        }
    }
    vector<array<int, 3>> lsegs;
    lsegs.reserve(n);
    vector<int> mins_suff_min(n);
    vector<char> color(n);
    auto print_ans = [&color](int col) {
        cout << "YES\n";
        for (auto& x : color) {
            if (x) {
                cout << 'B';
            } else {
                cout << 'R';
            }
        }
        cout << ' ' << col + 1 << '\n';
    };
    for (int col = 0; col < m - 1; ++col) {
        fill(all(color), 0);
        lsegs.clear();
        for (int row = 0; row < n; ++row) {
            lsegs.pb({pref_min[row][col], pref_max[row][col], row});
        }
        sort(all(lsegs), [](const array<int, 3>& a, const array<int, 3>& b) {
            return a[1] < b[1];
        });
        for (int i = 0; i < n; ++i) {
            mins_suff_min[i] = lsegs[i][0];
        }
        for (int i = n - 2; i > -1; --i) {
            cmin(mins_suff_min[i], mins_suff_min[i + 1]);
        }
        multiset<int> rmins, rmaxes;
        for (int row = 0; row < n; ++row) {
            rmins.insert(suff_max[row][col + 1]);
        }
        for (int i = 0; i + 1 < n; ++i) {
            const int row = lsegs[i][2];
            color[row] = 1;
            rmins.erase(rmins.find(suff_max[row][col + 1]));
            rmaxes.insert(suff_min[row][col + 1]);
            if (mins_suff_min[i + 1] <= lsegs[i][1]) continue;
            if (*rmins.rbegin() < *rmaxes.begin()) {
                print_ans(col);
                return;
            }
        }
    }
    cout << "NO\n";
}