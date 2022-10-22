#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll memo[100002];

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

ll fib(ll i){
    if(i == 0) return 1;
    if(i == 1) return 1;
    if(memo[i]) return memo[i];
    return memo[i] = (fib(i - 2) + fib(i - 1)) % MOD;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    ll ans = fib(m) * 2 - 2;
    ans = (ans + fib(n) * 2) % MOD;
    cout << ans << endl;
}