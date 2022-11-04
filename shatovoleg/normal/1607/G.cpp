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
    int n;
    cin >> n;
    while (n --> 0) {
        solve();
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pii> dishes(n);
    vector<pii> segs;
    segs.reserve(n);
    ll totl = 0, totr = 0;
    for (auto& [a, b] : dishes) {
        cin >> a >> b;

        int al = a - m, bl = b;
        if (al < 0) {
            bl += al;
            al = 0;
        }
        int l = al - bl;

        int ar = a, br = b - m;
        if (br < 0) {
            ar += br;
            br = 0;
        }
        int r = ar - br;
        assert(r >= l);
        segs.emplace_back(l, r);
        totl += l;
        totr += r;
    }
    vector<int> ans(n, 0);
    for (int i = 0; i < n; ++i) {
        auto [l, r] = segs[i];
        if (totl >= 0 || totr <= 0) {
            if (totl >= 0) {
                ans[i] = l;
            }
            if (totr <= 0) {
                ans[i] = r;
            }
            totl -= l;
            totr -= r;
            totl += ans[i];
            totr += ans[i];
        } else {
            totl -= l;
            totr -= r;
            auto [l1, r1] = segs[i];
            ll l2 = totl;
            ll r2 = totr;
            int l = l1;
            cmax(l, -r2);
            int r = r1;
            cmin(r, -l2);
            if ((l - l1) % 2 != 0) {
                ++l;
            }
            if ((r1 - r) % 2 != 0) {
                --r;
            }
            ans[i] = l;
            totl += ans[i];
            totr += ans[i];
        }
    }
    ll balance = accumulate(all(ans), 0ll);
    for (int i = 0; i < n; ++i) {
        int x = dishes[i].first - dishes[i].second + m - ans[i];
        x /= 2;
        dishes[i].first = x;
        dishes[i].second = m - x;
    }
    cout << abs(balance) << '\n';
    for (auto& [x, y] : dishes) {
        cout << x << ' ' << y << '\n';
    }
}