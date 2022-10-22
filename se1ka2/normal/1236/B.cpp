#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

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
    ll n, m;
    cin >> n >> m;
    ll p = (modpow(2, m) + MOD - 1) % MOD;
    cout << modpow(p, n) << endl;
}