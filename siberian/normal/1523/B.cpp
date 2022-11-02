#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()
#define mp make_pair

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    cout << 6 * n / 2 << '\n';
    for (int i = 0; i < n; i += 2) {
        cout << 1 << " " << i + 1 << " " << i + 2 << '\n';
        cout << 2 << " " << i + 1 << " " << i + 2 << '\n';
        cout << 1 << " " << i + 1 << " " << i + 2 << '\n';
        cout << 1 << " " << i + 1 << " " << i + 2 << '\n';
        cout << 2 << " " << i + 1 << " " << i + 2 << '\n';
        cout << 1 << " " << i + 1 << " " << i + 2 << '\n';   
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