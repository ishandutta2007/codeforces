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

optional<vector<pii>> solve();

void run() {
    int n;
    cin >> n;
    while (n --> 0) {
        auto res = solve();
        if (!res) {
            cout << "-1\n";
            continue;
        }
        int sm = 0;
        for (auto [x, y] : res.value()) {
            cout << x << " " << y << '\n';
            sm += (x & y);
        }
    }
}

optional<vector<pii>> solve() {
    int n, k;
    cin >> n >> k;
    auto inv = [n](int x) {
        return ((n - 1) ^ x);
    };
    vector<pii> ans;
    ans.reserve(n >> 1);
    if (k == 0) {
        for (int i = 0; i < (n >> 1); ++i) {
            ans.emplace_back(i, inv(i));
        }
        return ans;
    }
    if (k != n - 1) {
        int i = k, j = n - 1;
        ans.emplace_back(i, j);
        ans.emplace_back(inv(i), inv(j));
        for (int a = 0; a < (n >> 1); ++a) {
            if (a != i && a != j && a != inv(i) && a != inv(j)) {
                ans.emplace_back(a, inv(a));
            }
        }
        return ans;
    }
    if (n == 4) {
        return {};
    }
    int a = n - 2, b = n - 1;
    int c = n - (n >> 1) - 1, d = inv(c) ^ 1;
    ans.emplace_back(a, b);
    ans.emplace_back(inv(a), inv(b));
    ans.emplace_back(c, d);
    ans.emplace_back(inv(c), inv(d));
    for (int i = 0; i < (n >> 1); ++i) {
        if (i != a && i != b && i != c && i != d && i != inv(a) && i != inv(b) && i != inv(c) && i != inv(d)) {
            ans.emplace_back(i, inv(i));
        }
    }
    return ans;
}