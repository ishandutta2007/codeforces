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

#define int ll

void solve() {
    int n;
    vector<int> x, y;
    cin >> n;
    for (int i = 0; i < 2 * n; ++i) {
        int myX, myY;
        cin >> myX >> myY;
        if (myX == 0) {
            y.push_back(myY * myY);
        } else {
            x.push_back(myX * myX);
        }
    }
    // sort(x, x + n);
    // sort(y, y + n);
    // reverse(y, y + n);
    sort(all(x));
    sort(all(y));
    // reverse(all(y));
    // cerr << "x = ";
    // for (auto i : x) cerr << i << " ";
    // cerr << endl;
    // cerr << "y = ";
    // for (auto i : y) cerr << i << " ";
    // cerr << endl;
    ld ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += sqrt(x[i] + y[i]);
    }
    cout << ans << "\n";
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