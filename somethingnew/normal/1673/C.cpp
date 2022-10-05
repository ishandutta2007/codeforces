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
vector<int> dp(4e4 + 1);
void solve() {
    int x;
    cin >> x;
    cout << dp[x] << '\n';
}
int md = 1e9 + 7;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    dp[0] = 1;
    for (int i = 1; i < 4e4 + 1; ++i) {
        string s = to_string(i), s2 = s;
        reverse(all(s));
        if (s == s2) {
            for (int j = 0; j + i < dp.size(); ++j) {
                dp[j + i] += dp[j];
                if (dp[j + i] >= md)
                    dp[j + i] -= md;
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}