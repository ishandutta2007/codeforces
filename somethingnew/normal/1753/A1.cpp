//        
//   @roadfromroi 
//        
#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            ans.push_back({i + 1, i + 1});
            continue;
        }
        int nxt = i + 1;
        while (nxt != n and a[nxt] == 0)
            nxt++;
        if (nxt == n) {
            cout << "-1\n";
            return;
        }
        if (a[i] != a[nxt]) {
            for (int j = i; j <= nxt; ++j) {
                ans.push_back({j + 1, j + 1});
            }
        } else {
            for (int j = i; j < nxt - 1; ++j) {
                ans.push_back({j + 1, j + 1});
            }
            ans.push_back({nxt, nxt + 1});
        }
        i = nxt;
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }

}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}