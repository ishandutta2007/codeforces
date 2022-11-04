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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& x : a) {
        cin >> x;
    }
    map<int, int> cnt;
    for (auto x : a) {
        ++cnt[x];
    }
    vector<pii> comp(all(cnt));
    int l = 0, r = 0, sm = 0;
    int ansl = -INF, ansr = INF;
    while (l < len(comp)) {
        bool stop = false;
        while (sm < n - sm + k) {
            if (r == len(comp)) {
                stop = true;
                break;
            }
            sm += comp[r++].second;
        }
        if (stop) break;
        if (comp[r - 1].first - comp[l].first < ansr - ansl) {
            ansr = comp[r - 1].first;
            ansl = comp[l].first;
        }
        sm -= comp[l++].second;
    }
    cout << ansl << " " << ansr << '\n';
    vector<char> taken(n);
    for (int i = 0; i < n; ++i) {
        taken[i] = (a[i] >= ansl && a[i] <= ansr);
    }
    vector<pii> ans;
    int start = 0;
    while (start < n) {
        int cur = start;
        int balance = 0;
        while (cur < n && balance <= 0) {
            if (taken[cur++]) ++balance;
            else --balance;
        }
        ans.pb({start, cur});
        start = cur;
    }
    while (len(ans) > k) {
        auto [l1, r1] = ans.back();
        ans.kek();
        auto [l2, r2] = ans.back();
        ans.kek();
        ans.pb({l2, r1});
    }
    for (auto& [l, r] : ans) {
        cout << l + 1 << " " << r << '\n';
    }
}