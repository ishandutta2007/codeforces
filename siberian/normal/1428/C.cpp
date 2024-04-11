#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(a) a.begin(), a.end()

using namespace std;

template<typename T1, typename T2> inline void chkmin(T1& x, const T2& y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1& x, const T2& y) {if (x < y) x = y;}

void solve() {
    string s;
    cin >> s;
    int bal = 0;
    int cntB = 0;
    for (auto i : s) {
        if (i == 'A') {
            bal++;
        } else {
            if (bal > 0) {
                bal--;
            } else {
                cntB++;
            }
        }
    }
    cout << bal + cntB % 2 << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.setf(ios::fixed), cout.precision(20);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}