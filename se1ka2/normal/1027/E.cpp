#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll dp[2][502][502];
ll l[502];

ll modpow(ll x, ll n){
    ll res = 1, r = x;
    while(n){
        if(n & 1) res = res * r % MOD;
        r = r * r % MOD;
        n >>= 1;
    }
    return res;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    dp[1][1][1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            dp[i & 1][j][1] = 0;
            for(int k = 1; k <= j; k++){
                dp[i & 1][j][1] = (dp[i & 1][j][1] + dp[(i - 1) & 1][j][k]) % MOD;
            }
            for(int k = 2; k <= j; k++){
                dp[i & 1][j][k] = dp[(i - 1) & 1][j][k - 1];
            }
            if(j >= 2) dp[i & 1][j][j] = (dp[i & 1][j][j] + dp[(i - 1) & 1][j - 1][j - 1]) % MOD;
        }
    }
    for(int j = 1; j <= n; j++){
        for(int k = 1; k <= j; k++) l[j] = (l[j] + dp[n & 1][j][k]) % MOD;
    }
    int j = 0;
    ll s = 0;
    ll ans = 0;
    for(int r = n; r >= 1; r--){
        while(r * (j + 1) < m && j < n) s = (s + l[++j]) % MOD;
        ans = (ans + s * l[r] % MOD) % MOD;
    }
    cout << ans * 2 % MOD << endl;
}