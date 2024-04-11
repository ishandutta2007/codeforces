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

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> n2;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '2') {
            n2.pb(i);
        }
    }
    if (len(n2) == 1 || len(n2) == 2) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES\n";
    vector<string> ans(n, string(n, '='));
    for (int i = 0; i < len(n2); ++i) {
        int cur = n2[i], nxt = n2[(i + 1) % len(n2)];
        ans[cur][nxt] = '+';
        ans[nxt][cur] = '-';
    }
    for (int i = 0; i < n; ++i) {
        ans[i][i] = 'X';
        cout << ans[i] << '\n';
    }
}