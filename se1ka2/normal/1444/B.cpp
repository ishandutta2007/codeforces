#include <algorithm>
#include <iostream>
#include <vector>
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

struct Combination
{
    int maxn;
    vector<ll> fact;
    vector<ll> ifact;
    
    Combination(int maxn) : maxn(maxn){
        fact.resize(maxn + 1);
        ifact.resize(maxn + 1);
        fact[0] = 1;
        for(int i = 1; i <= maxn; i++) fact[i] = fact[i - 1] * i % MOD;
        ifact[maxn] = modpow(fact[maxn], MOD - 2);
        for(int i = maxn - 1; i >= 0; i--) ifact[i] = ifact[i + 1] * (i + 1) % MOD;
    }

    ll com(ll n, ll k){
        if(k > n || k < 0) return 0;
        if(k == n || k == 0) return 1;
        return (fact[n] * ifact[k] % MOD) * ifact[n - k] % MOD;
    }
};

int main()
{
    int n;
    cin >> n;
    ll a[300005];
    for(int i = 0; i < n * 2; i++) cin >> a[i];
    sort(a, a + n * 2);
    Combination com(n * 2);
    ll p = com.com(n * 2, n);
    ll ans = 0;
    for(int i = 0; i < n; i++) ans = (ans + MOD - a[i] * p % MOD) % MOD;
    for(int i = n; i < n * 2; i++) ans = (ans + a[i] * p % MOD) % MOD;
    cout << ans << endl;
}