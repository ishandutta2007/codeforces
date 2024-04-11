#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = (int)1e5 + 50, mod = (int)1e9 + 7;

int n, m;
ll dp[2][N];

int main() {
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = dp[0][1] = 1;
    for(int i = 1; i < N; i++) {
        dp[0][i] = (dp[1][i-1] + dp[1][i-2]) % mod;
        dp[1][i] = (dp[0][i-1] + dp[0][i-2]) % mod;
    }
    cin >> n >> m;
    ll res = (dp[0][n] + dp[1][n] - 2) + (dp[0][m] + dp[1][m]);
    res = (res % mod + mod) % mod;
    cout << res << endl;
}