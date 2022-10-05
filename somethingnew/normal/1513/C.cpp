#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "numeric"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()

using namespace std;
long long mod = 1e9 + 7;
vector<vector<long long>> makedp(int n, int m) {
    vector<vector<long long>> dp(m + 1, vector<long long>(10));
    dp[0][n]++;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < 9; ++j) {
            dp[i + 1][j + 1] += dp[i][j];
            if (dp[i + 1][j + 1] >= mod)
                dp[i + 1][j + 1] -= mod;
        }
        dp[i + 1][0] += dp[i][9];
        dp[i + 1][1] += dp[i][9];
        if (dp[i + 1][0] >= mod)
            dp[i + 1][0] -= mod;
        if (dp[i + 1][1] >= mod)
            dp[i + 1][1] -= mod;
    }
    return dp;
}
vector<vector<vector<long long>>> dpp;
vector<vector<long long>> dp;
void solve(){
    string s;
    int m;
    cin >> s >> m;
    long long val = 0;
    vector<long long> vv(10);
    for (auto i : s)
        vv[i-'0']++;
    for (int j = 0; j < 10; ++j) {
        val += vv[j] * dp[j][m];
        val %= mod;
    }
    cout << val << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    dpp.assign(10, {});
    dp.assign(10, vector<long long>(2e5 + 10));
    for (int j = 0; j < 10; ++j) {
        dpp[j] = makedp(j, 2e5 + 30);
        for (int i = 0; i < dp[j].size(); ++i) {
            dp[j][i] = accumulate(all(dpp[j][i]), 0ll);
        }
    }
    for (int i = 0; i < n; ++i) {
        solve();
    }
}