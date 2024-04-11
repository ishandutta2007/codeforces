#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll memo[300][300];
ll dp[300][300];
ll powkn[300];
ll powk[300];

ll com(ll n, ll k){
    if(k == 0 || k == n) return 1;
    if(memo[n][k]) return memo[n][k];
    return memo[n][k] = (com(n - 1, k - 1) + com(n - 1, k)) % MOD;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    powkn[0] = 1;
    powk[0] = 1;
    for(int i = 1; i < 300; i++){
        powkn[i] = (powkn[i - 1] * (k - 1)) % MOD;
        powk[i] = (powk[i - 1] * k) % MOD;
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n; j++){
            for(int l = 0; l < j; l++){
                dp[i][j] = (dp[i][j] + ((dp[i - 1][l] * com(n - l, j - l) % MOD) * powkn[n - j] % MOD) * powk[l] % MOD) % MOD;
            }
            dp[i][j] = (dp[i][j] + ((dp[i - 1][j] * powkn[n - j] % MOD) * ((powk[j] + MOD - powkn[j]) % MOD)) % MOD) % MOD;
        }
    }
    cout << dp[n][n] << endl;
}