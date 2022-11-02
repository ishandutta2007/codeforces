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
    string a, b;
    cin >> a >> b;
    for (int len = min(a.size(), b.size()); len > 0; --len) {
        for (int i = 0; i + len - 1 < a.size(); ++i) {
            auto x = a.substr(i, len);
            for (int j = 0; j + len - 1 < b.size(); ++j) {
                auto y = b.substr(j, len);
                if (x != y) continue;
                cout << a.size() + b.size() - 2 * len << '\n';
                return;
            }
        }
    }
    cout << a.size() + b.size() << '\n';
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