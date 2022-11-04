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

struct SparseTable {
    SparseTable(const vector<ll>& v): lg(len(v) + 1, -1) {
        table.emplace_back(v);
        for (int lvl = 1; (1 << lvl) <= len(v); ++lvl) {
            table.emplace_back(len(v) - (1 << lvl) + 1);
            for (int j = 0; j < len(table.back()); ++j) {
                table.back()[j] = min(table[lvl - 1][j], table[lvl - 1][j + (1 << (lvl - 1))]);
            }
        }
        for (int i = 1; i < len(lg); ++i) {
            lg[i] = lg[i >> 1] + 1;
        }
    }

    ll query(int l, int r) const {
        const int ln = lg[r - l];
        return min(table[ln][l], table[ln][r - (1 << ln)]);
    }

private:
    vector<vector<ll>> table;
    vector<int> lg;
};

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
    }
    vector<ll> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }
    SparseTable t(pref);
    int L = 0, R = 0;
    for (int i = 0; i < n; ++i) {
        int l = i, r = n + 2;
        while (r - l > 1) {
            int c = (r + l) >> 1;
            if (t.query(i, c) >= pref[i] - s) {
                l = c;
            } else {
                r = c;
            }
        }
        --l;
        if (l - i > R - L) {
            tie(R, L) = mp(l, i);
        }
    }
    if (R == 0) {
        cout << "-1\n";
        return;
    }
    cout << L + 1 << " " << R << endl;
}