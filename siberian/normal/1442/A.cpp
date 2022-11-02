#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

#define int ll

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    auto fans = a;
    int now = 0;
    for (int i = n - 2; i >= 0; --i) {
        int d = a[i + 1] - a[i];
        if (d < 0) {
            now += abs(d);
        }
        fans[i] -= now;
    }
    if (*min_element(all(fans)) < 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
    /*auto ans = a;
    int now = 1e9;
    for (int i = 0; i < n; ++i) {
        chkmin(now, a[i]);
        ans[i] -= now;
    }
    now = 1e9;
    for (int i = n - 1; i >= 0; --i) {
        chkmin(now, a[i]);
        ans[i] -= now;
    }
    if (*max_element(all(ans)) > 0){
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }*/
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