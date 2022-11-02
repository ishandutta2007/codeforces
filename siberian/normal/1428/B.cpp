#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(a) a.begin(), a.end()

using namespace std;

template<typename T1, typename T2> inline void chkmin(T1& x, const T2& y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1& x, const T2& y) {if (x < y) x = y;}

int n;
string s;

void solve() {
    cin >> n >> s;
    int have1 = false, have2 = false;
    for (auto i : s) {
        have1 |= i == '<';
        have2 |= i == '>'; 
    }
    if (!have1 || !have2) {
        cout << n << "\n";
        return;
    }
    vector<bool> good(n);
    for (int i = 0; i < n; ++i) {
        if (s[i] != '-') continue;
        good[i] = true;
        good[(i + 1) % n] = true;
    }
    int ans = 0;
    for (auto i : good) {
        ans += i;
    }
    cout << ans << "\n";
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