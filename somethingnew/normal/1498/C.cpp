#include "iostream"
#include "vector"
#include "numeric"
#include "algorithm"
#include "set"
#include "list"
#include "queue"
#include "map"
#include "bitset"
using namespace std;
typedef long long ll;
#define int ll
#define all(x) (x).begin(), (x).end()
int mod = (int(1e9)) + 7;
void solve() {
    int n, k;
    cin >> n >> k;
    int sum = 1;
    vector<vector<int>> dp(2, vector<int>(n));
    dp[0][0] = 1;
    for (int ttt = 0; ttt < k - 1; ++ttt) {
        dp[1][n - 1] = 0;
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                dp[0][i] += dp[0][i - 1];
                dp[0][i] %= mod;
            }
            sum += dp[0][i];
            sum %= mod;
            if (i != 0) {
                dp[1][i - 1] = dp[0][i];
            }
        }
        reverse(all(dp[1]));
        swap(dp[0], dp[1]);
    }
    cout << sum << endl;
}
signed main() {
    int t;
    cin >> t;
    while (t--) solve();
}