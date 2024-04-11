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
    vector<vector<int>> a(3, vector<int>(n, 0));
    for (auto& i : a) {
        for (auto &j : i) {
            cin >> j;
        }
    }
    
    vector<int> ans;
    ans.push_back(a[0][0]);
    for (int i = 1; i + 1 < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (ans.back() == a[j][i]) {
                continue;
            }
            ans.push_back(a[j][i]);
            break;
        }
    }
    for (int j = 0; j < 3; ++j) {
        if (ans.back() == a[j][n - 1]) continue;
        if (ans[0] == a[j][n - 1]) continue;
        ans.push_back(a[j][n - 1]);
        break;
    }
    assert(!ans.empty());
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << "\n";
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