#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& i : a) {
        cin >> i;
    }
    sort(all(a));
    a.resize(unique(all(a)) - a.begin());
    if (a.size() > 1 && k == 1) {
        cout << -1 << "\n";
        return;
    }
    if (k >= a.size()) {
        cout << 1 << "\n";
        return;
    }
    /*cout << "a = " << endl;
    for (auto i : a) {
        cout << i << " ";
    } 
    cout << endl;*/
    assert(k >= 2);
    int ans = (a.size() - k + (k - 2)) / (k - 1) + 1;
    cout << ans << "\n";
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