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
    int n, m;
    cin >> n >> m;
    vector<int> expected(n);
    for (auto& x : expected) {
        cin >> x;
    }
    vector<string> results(n);
    for (auto& x : results) {
        cin >> x;
    }
    vector<pii> balance(m);
    ll best = -1;
    vector<int> p(m), candidate(m);
    for (int msk = 0; msk < (1 << n); ++msk) {
        for (int i = 0; i < m; ++i) {
            balance[i] = {0, i};
        }
        for (int i = 0; i < n; ++i) {
            int flag = !!(msk & (1 << i));
            for (int j = 0; j < m; ++j) {
                balance[j].first += (results[i][j] - '0') * (flag * 2 - 1);
            }
        }
        sort(all(balance));
        for (int i = 0; i < m; ++i) {
            candidate[balance[i].second] = i + 1;
        }
        ll divergance = 0;
        for (int i = 0; i < n; ++i) {
            int cur_score = 0;
            for (int j = 0; j < m; ++j) {
                cur_score += candidate[j] * (results[i][j] - '0');
            }
            divergance += abs(cur_score - expected[i]);
        }
        if (cmax(best, divergance)) {
            swap(p, candidate);
        }
    }
    for (auto& x : p) {
        cout << x << " ";
    }
    cout << '\n';
}