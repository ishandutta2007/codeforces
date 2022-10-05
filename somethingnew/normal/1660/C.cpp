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
#include "queue"
#define all(x) x.begin(), x.end()
using namespace std;

void solve() {
    int n;
    string a;
    cin >> a;
    n = a.size();
    map<int, int> lstind;
    vector<int> dp(n + 1);
    for (int i = 0; i < n; ++i) {
        dp[i + 1] = dp[i];
        if (lstind[a[i]] != 0) {
            dp[i+1] = max(dp[i+1], 1 + dp[lstind[a[i]] - 1]);
        }
        lstind[a[i]] = i + 1;
    }
    cout << n - 2 * dp.back() << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
/*

 */