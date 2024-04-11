#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

void solve() {
    string s;
    cin >> s;
    int bal1 = 0, bal2 = 0, ans = 0;
    for (auto i : s) {
        if (i == '(') {
            bal1++;
        } else if (i == ')') {
            if (bal1 > 0) {
                bal1--;
                ans++;
            }
        } else if (i == '[') {
            bal2++;
        } else {
            if (bal2 > 0) {
                bal2--;
                ans++;
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}