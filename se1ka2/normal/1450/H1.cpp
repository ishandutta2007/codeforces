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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++){
        if(i % 2){
            if(s[i] == 'b') s[i] = 'w';
            else if(s[i] == 'w') s[i] = 'b';
        }
    }
    int b = 0;
    int q = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'b') b++;
        else if(s[i] == 'w') b--;
        else q++;
    }
    Combination com(n);
    ll ans = 0;
    if((b + q) % 4 == 0){
        for(int i = q; i >= 0; i -= 2){
            ans = (ans + com.com(q, i) * abs(b + i - (q - i)) / 4) % MOD;
        }
    }
    else{
        for(int i = q - 1; i >= 0; i -= 2){
            ans = (ans + com.com(q, i) * abs(b + i - (q - i)) / 4) % MOD;
        }
    }
    ll p = 1;
    for(int i = 0; i < q - 1; i++) p = p * 2 % MOD;
    cout << ans * modpow(p, MOD - 2) % MOD << endl;
}