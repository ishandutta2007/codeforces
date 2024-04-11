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
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    vector<int> b;
    vector<int> l(n);
    for (auto& i : l) {
        cin >> i;
    }
    for (int i = 0; i < n; ++i) {
        if (l[i]) continue;
        b.push_back(a[i]);
    }
    sort(all(b));
    for (int i = 0; i < n; ++i) {
        if (l[i]) continue;
        a[i] = b.back();
        b.pop_back();
    }
    for (auto i : a) {
        cout << i << " ";
    }
    cout << endl;
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