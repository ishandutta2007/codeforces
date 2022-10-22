#include <iostream>
#include <vector>
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
    int n, x, p;
    cin >> n >> x >> p;
    int left = 0, right = n;
    int l = 0, h = 0;
    while(left < right){
        int mid = (right + left) / 2;
        if(mid > p){
            right = mid;
            if(mid != p) h++;
        }
        else{
            left = mid + 1;
            if(mid != p) l++;
        }
    }
    Combination com(n);
    if(n - x - h < 0 || x - 1 - l < 0) cout << 0 << endl;
    else cout << (com.fact[n - x] * com.ifact[n - x - h] % MOD) * (com.fact[x - 1] * com.ifact[x - 1 - l] % MOD) % MOD * com.fact[n - h - l - 1] % MOD << endl;
}