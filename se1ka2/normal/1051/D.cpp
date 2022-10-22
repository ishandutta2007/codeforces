#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll dp[1002][2002][4];

int main()
{
    ll n, k;
    cin >> n >> k;
    dp[1][1][0] = 1;
    dp[1][1][3] = 1;
    dp[1][2][1] = 1;
    dp[1][2][2] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= k; j++){
            dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1] + dp[i - 1][j][2] + dp[i - 1][j - 1][3]) % MOD;
            if(j > 1) dp[i][j][1] = (dp[i - 1][j - 1][0] + dp[i - 1][j][1] + dp[i - 1][j - 2][2] + dp[i - 1][j - 1][3]) % MOD;
            if(j > 1) dp[i][j][2] = (dp[i - 1][j - 1][0] + dp[i - 1][j - 2][1] + dp[i - 1][j][2] + dp[i - 1][j - 1][3]) % MOD;
            dp[i][j][3] = (dp[i - 1][j - 1][0] + dp[i - 1][j][1] + dp[i - 1][j][2] + dp[i - 1][j][3]) % MOD;
        }
    }
    cout << (dp[n][k][0] + dp[n][k][1] + dp[n][k][2] + dp[n][k][3]) % MOD << endl;
}