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
    int mx0 = 0, mx1 = 0;
    vector<int> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    sort(all(a));
    for (auto i : a) {
        if (i == mx0) {
            mx0++;
        } else if (i == mx1) {
            mx1++;
        }
    }
    cout << mx0 + mx1 << "\n";
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