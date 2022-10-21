#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 998244353, N = 1050;

int n,k;
ll dp[N][2*N][2][2];

int main(){
    cin >> n >> k;
    dp[0][1][0][0] = dp[0][1][1][1] = 1;
    dp[0][2][1][0] = dp[0][2][0][1] = 1;
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= k; j++){
            dp[i][j][0][1] = (dp[i-1][j][0][1] + dp[i-1][j-1][0][0] + dp[i-1][j-1][1][1] +
                    (j >= 2 ? dp[i-1][j-2][1][0] : 0)) % mod;
            dp[i][j][1][0] = ((j >= 2 ? dp[i-1][j-2][0][1] : 0) +
                    dp[i-1][j-1][0][0] + dp[i-1][j-1][1][1] + dp[i-1][j][1][0]) % mod;
            dp[i][j][0][0] = (dp[i-1][j][0][1] + dp[i-1][j][0][0] + dp[i-1][j-1][1][1] + dp[i-1][j][1][0]) % mod;
            dp[i][j][1][1] = (dp[i-1][j][0][1] + dp[i-1][j-1][0][0] + dp[i-1][j][1][1] + dp[i-1][j][1][0]) % mod;
        }
    }
    ll ans = (dp[n-1][k][0][0] + dp[n-1][k][0][1] + dp[n-1][k][1][0] + dp[n-1][k][1][1]) % mod;
    cout << ans << endl;
}