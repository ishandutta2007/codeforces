#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

const int N = 2e5 + 10;
int n;
ll a[N];
ll sum;

ll calc(ll x, ll y, int pos) {
    ll haveVal = a[pos];
    ll haveSum = sum - haveVal;
    return max(0LL, x - haveVal) + max(0LL, y - haveSum);
}

void solve() {
    ll x, y;
    cin >> x >> y;
    int pos = lower_bound(a, a + n, x) - a;
    ll ans = LONG_LONG_MAX;
    for (int i = max(0, pos - 2); i < min(n, pos + 2); ++i) {
        chkmin(ans, calc(x, y, i));
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n;
    sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}