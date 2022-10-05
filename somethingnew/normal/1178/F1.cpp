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
signed main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<int> ex(n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int mod = 998244353;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1));
    for (int len = 0; len < n; ++len) {
        for (int i = 0; i + len < n; ++i) {
            int j = i + len;
            int minp = i;
            for (int k = i; k <= j; ++k) {
                if (a[minp] > a[k])
                    minp = k;
            }
            int resl, resr = dp[minp + 1][j];
            if (minp == 0)
                resl = 1;
            else
                resl = dp[i][minp - 1];
            //cout << i << ' ' << j << ' ' << resl << ' ' << resr << endl;
            for (int k = minp - 1; k >= i; --k) {
                if (k == 0)
                    resl += dp[k][minp - 1];
                else
                    resl += dp[k][minp - 1] * dp[i][k - 1] % mod;
            }
            for (int k = minp + 1; k <= j; ++k) {
                resr += dp[minp + 1][k] * dp[k + 1][j] % mod;
            }
            resl %= mod;
            resr %= mod;
            //cout << i << ' ' << j << ' ' << resl << ' ' << resr << endl;
            dp[i][j] = resl * resr % mod;
        }
    }
    //cout << dp[0][0] << endl;
   // cout << dp[0][1] << endl;
    //cout << dp[1][2] << endl;
    cout << dp[0][n - 1];
}