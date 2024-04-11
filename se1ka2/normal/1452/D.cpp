#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

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
    int n;
    cin >> n;
    ll dp[200005];
    dp[0] = 0, dp[1] = 1;
    for(int i = 2; i <= n; i++) dp[i] = (dp[i - 2] + dp[i - 1]) % MOD;
    ll p = modpow(2, n);
    cout << dp[n] * modpow(p, MOD - 2) % MOD << endl;
}