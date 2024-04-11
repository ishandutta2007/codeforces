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
        int n, m;
        cin >> n >> m;
        string s, t;
        cin >> s >> t;
        bool ok = true;

        for (int i = 0; i < m - 1; ++i) {
            ok &= s[n - 1 - i] == t[m - 1 - i];
        }

        if (!ok) {
            cout << "NO\n";
            continue;
        }
        ok = false;
        for (int i = 0; i < n - m + 1; ++i) {
            ok |= s[i] == t[0];
        }
        if (ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }   
    return 0;
}