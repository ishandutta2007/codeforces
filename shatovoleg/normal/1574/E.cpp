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

// #define TASK "recovery"

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

void run() {
    int n, m, k;
    cin >> n >> m >> k;

    map<pii, char> fld;

    int chess[2] = {0, 0};
    vector<vector<int>> cnt_col(m, vector<int>(2, 0)), cnt_row(n, vector<int>(2, 0));
    int bad_cols = 0, locked_cols = 0, bad_rows = 0, locked_rows = 0;

    auto clear = [&](int i, int j) {
        if (auto it = fld.find({i, j}); it != fld.end()) {
            --chess[(it->second + i + j) & 1];
            if (--cnt_col[j][(it->second + i) & 1] == 0) {
                if (cnt_col[j][(it->second + i + 1) & 1]) {
                    --bad_cols;
                } else {
                    --locked_cols;
                }
            }
            if (--cnt_row[i][(it->second + j) & 1] == 0) {
                if (cnt_row[i][(it->second + j + 1) & 1]) {
                    --bad_rows;
                } else {
                    --locked_rows;
                }
            }
            fld.erase(it);
        }
    };

    auto place = [&](int i, int j, char val) {
        ++chess[(val + i + j) & 1];
        if (cnt_col[j][(val + i) & 1]++ == 0) {
            if (cnt_col[j][(val + i + 1) & 1]) {
                ++bad_cols;
            } else {
                ++locked_cols;
            }
        }
        if (cnt_row[i][(val + j) & 1]++ == 0) {
            if (cnt_row[i][(val + j + 1) & 1]) {
                ++bad_rows;
            } else {
                ++locked_rows;
            }
        }
        fld[{i, j}] = val;
    };

    auto get_ans = [&]() {
        int ans = 0;
        for (int i = 0; i < 2; ++i) {
            if (!chess[i]) {
                --ans;
            }
        }
        if (!bad_cols) {
            ans += bpow(2, m - locked_cols, mod);
        }
        if (!bad_rows) {
            ans += bpow(2, n - locked_rows, mod);
        }
        if (ans >= mod) {
            ans -= mod;
        }
        return ans;
    };

    for (int i = 0; i < k; ++i) {
        int x, y, val;
        cin >> x >> y >> val;
        --x, --y;
        clear(x, y);
        if (val != -1) {
            place(x, y, char(val));
        }
        cout << get_ans() << '\n';
    }
}