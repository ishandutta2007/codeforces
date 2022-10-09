#include <iostream>
#include <vector>
#include <string>

const int mod = 1e9 + 7;

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<string> in(n);
    for(int i = 0; i < n; i ++) {
        cin >> in[i];
    }
    vector<vector<int>> dp(n, vector<int> (n, 0));
    vector<vector<int>> sum(n, vector<int> (n + 1, 0));
    dp[0][0] = 1;
    for(int i = 1; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            sum[i - 1][j + 1] = (sum[i - 1][j] + dp[i - 1][j]) % mod;
        }
        for(int j = 0; j < n; j ++) {
            if (in[i - 1] == "f") {
                if (j > 0) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                continue;
            }
            dp[i][j] = (sum[i - 1][n] - sum[i - 1][j] + mod) % mod;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += dp[n - 1][i];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}