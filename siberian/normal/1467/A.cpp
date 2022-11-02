#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

void solve() {
    int n;
    cin >> n;
    if (n <= 2) {
        int num = 9;
        for (int i = 0; i < n; ++i) {
            cout << num;
            --num;
            if (num == -1) {
                num = 9;
            }
        }
        cout << '\n';
    } else {
        cout << "98";
        int num = 9;
        for (int i = 0; i < n - 2; ++i) {
            cout << num;
            ++num;
            if (num == 10) {
                num = 0;
            }
        }
        cout << '\n';
    }
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