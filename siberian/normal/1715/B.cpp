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

void solve() {
    ll n, k, b, s;
    cin >> n >> k >> b >> s;
    if ((k - 1) * n + b * k < s || b * k > s) {
        cout << "-1\n";
    } else {
        s -= b * k;
        ll add = min(k - 1, s);
        s -= add;
        cout << b * k + add;
        for (int i = 1; i < n; ++i) {
            ll add = min(k - 1, s);
            s -= add;
            cout << ' ' << add;       
        }
        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}