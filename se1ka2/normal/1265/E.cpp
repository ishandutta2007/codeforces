#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll modpow(ll x, ll n){
    ll res = 1;
    ll mul = x;
    while(n){
        if(n % 2) res = res * mul % MOD;
        mul = mul * mul % MOD;
        n /= 2;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    ll p[200005];
    for(int i = 0; i < n; i++) cin >> p[i];
    ll dp[200005];
    dp[0] = 0;
    for(int i = 1; i <= n; i++) dp[i] = (dp[i - 1] + 1) * 100 % MOD * modpow(p[i - 1], MOD - 2) % MOD;
    cout << dp[n] << endl;
}