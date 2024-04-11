// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

const int M = 1000000007;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    int iM = (M + 1) / 2;
    for (int _ = 0; _ < T; ++_) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1));
        for (int i = 0; i < n + 1; ++i) {
            for (int j = 0; j < m + 1 && j <= i; ++j) {
                if (j == 0) {
                    dp[i][j] = 0;
                }
                else if (j == i) {
                    dp[i][j] = i;
                }
                else {
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) * iM % M;
                }
            }
        }
        cout << dp[n][m] * k % M << '\n';

    }

    return 0;
}