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

#define int ll

const int N = 5010;
int n;
int a[N];

ll solve(int pos) {
    ll ans = 0;
    ll last = 0;
    for (int i = pos - 1; i >= 0; --i) {
        ll cnt = last / a[i] + 1;
        last = cnt * a[i];
        ans += cnt;
    }
    last = 0;
    for (int i = pos + 1; i < n; ++i) {
        ll cnt = last / a[i] + 1;
        last = cnt * a[i];
        ans += cnt;    
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll ans = LONG_LONG_MAX;
    for (int pos = 0; pos <= n; ++pos) {
        chkmin(ans, solve(pos));
    }
    cout << ans << endl;
    return 0;
}