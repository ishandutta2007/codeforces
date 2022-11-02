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

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        ll a, b, c;
        cin >> a >> b >> c;
        bool ok = false;
        // c *= m
        {
            ll d = b - a;
            ll need = d + b;
            if (need <= 0 || need % c != 0) {
                // nothing
            } else {
                ok = true;
            }
        }
        // b *= m
        if (abs(a - c) % 2 == 0) {
            ll need = (c - a) / 2 + a;
            if (need <= 0 || need % b != 0) {
                // nothing
            } else {
                ok = true;
            }
        }
        // a *= m
        {
            ll d = c - b;
            ll need = b - d;
            if (need <= 0 || need % a != 0) {
                // nothing
            } else {
                ok = true;
            }
        }
        if (ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}