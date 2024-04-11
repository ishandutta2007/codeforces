#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()

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

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    if (n == 1 || b == 1) {
        cout << "Yes\n";
        return;
    }
    if (n % b == 1) {
        cout << "Yes\n";
        return;
    }
    if (a == 1) {
        cout << "No\n";
        return;
    }
    ll x = 1;
    while (x <= n) {
        // cerr << "x = " << x << " ";
        // cerr << "(n - x) = " << (n - x) << " (n - x) % b = " << (n - x) % b << " (n - x) / b = " << (n - x) / b << " (n - x) / b \% a = " << (n - x) / b % a << endl;
        if ((n - x) % b == 0) {
            cout << "Yes\n";
            return;
        }
        x *= a;
    }
    cout << "No\n";
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