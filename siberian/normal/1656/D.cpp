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
    ll n;
    cin >> n;
    if (n & 1) {
        cout << "2\n";
        return;
    }
    for (int bit = 1; bit < 31; ++bit) {
        ll k = 1LL << bit;
        // cerr << k * (k + 1) / 2 << endl;
        if (n - (k * (k + 1)) / 2 >= 0 && (n - k * (k + 1) / 2) % k == 0) {
            cout << k << '\n';
            return;
        }
    }
    while ((n & 1) == 0) n >>= 1;
    if (n > 1) {
        cout << n << '\n';
    } else {
        cout << "-1\n";
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