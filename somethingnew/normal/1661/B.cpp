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
#define int long long
vector<int> dp(32768, 1e9);
int md = 32768;
void solve() {
    int x;
    cin >> x;
    cout << dp[x] << ' ';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    dp[0] = 0;
    for (int i = 0; i < 40; ++i) {
        for (int j = 0; j < 32768; ++j) {
            dp[j] = min(dp[j], dp[(j+1)%md]+1);
            dp[j] = min(dp[j], dp[(j*2)%md]+1);
        }
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}