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


const int INF = (is_same<int, ll>::value ? 1e18l + 666 : 1e9 + 666);
const ll INFll = 1e18 + 666;
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

signed main() {
    // freopen("mining.in", "r", stdin);
    // freopen("mining.out", "w", stdout);
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

constexpr int mod = 998'244'353;

int fact(int n, int skip = -1) {
    int res = 1;
    for (int i = 1; i <= n; ++i) {
        if (i == skip) continue;
        res = int(1ll * res * i % mod);
    }
    return res;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> x(n);
    for (auto& x : x) { // I love C++
        cin >> x;
    }

    vector<int> y(m);
    for (auto& y : y) {
        cin >> y;
    }

    vector<int> cntx(n + 1, 0), cnty(m + 1, 0);
    vector<map<int, int>> map_cntx(n + 1), map_cnty(m + 1);
    ll ans = 0;

    for (int i = 0; i < k; ++i) {
        int X, Y;
        cin >> X >> Y;
        int xidx = (int)(lower_bound(all(x), X) - x.begin());
        int yidx = (int)(lower_bound(all(y), Y) - y.begin());
        bool onx = (xidx < len(x) && x[xidx] == X);
        bool ony = (yidx < len(y) && y[yidx] == Y);
        if (onx && ony) continue;
        if (onx) {
            ans += cnty[yidx]++;
            ans -= map_cnty[yidx][X]++;
        }
        if (ony) {
            ans += cntx[xidx]++;
            ans -= map_cntx[xidx][Y]++;
        }
    }
    cout << ans << endl;
}