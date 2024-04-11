#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll dp[22][1002];

int main()
{
    ll n, m;
    cin >> n >> m;
    dp[0][0] = 1;
    for(int i = 1; i <= m * 2; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k <= j; k++) dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
        }
    }
    ll ans = 0;
    for(int j = 0; j < n; j++) ans += dp[m * 2][j];
    cout << ans % MOD << endl;
}