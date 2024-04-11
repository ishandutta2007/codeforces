#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std;
int mod = 1e9 + 7;
void md(int &a) {
    if (a >= mod)
        a -= mod;
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(m + 1));
    for (int i = 2; i <= m; ++i) {
        dp[0][i] = 1;
    }
    for (int i = 1; i < n; ++i) {
        int sum1 = 0;
        int sumres = 0;
        for (int j = 2; j <= m; ++j) {
            sum1 += dp[i-1][j];
            md(sum1);
            sumres += sum1;
            md(sumres);
            dp[i][j] = sumres + 1;
        }
    }
    int res = 0;
    for (int k = 0; k < n; ++k) {
        for (int len = 2; len <= m; ++len) {
            if (k == 0) {
                res += dp[n - 1][len] * (m - len + 1) % mod;
                md(res);
            } else {
                res += dp[n - k - 1][len] * (dp[k][len] - dp[k-1][len] + mod) % mod * (m - len + 1) % mod;
                md(res);
            }
        }
    }
    cout << res;
}