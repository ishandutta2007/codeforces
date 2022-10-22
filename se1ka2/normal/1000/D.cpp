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
    vector<ll> fmemo;
    vector<ll> imemo;
    vector<ll> ifmemo;
    
    Combination(int maxn) : maxn(maxn){
        fmemo.resize(maxn + 1);
        imemo.resize(maxn + 1);
        ifmemo.resize(maxn + 1);
        for(ll i = 1; i <= maxn; i++){
            imemo[i] = modpow(i, MOD - 2);
        }
    }

    ll fact(ll n){
        if(n == 0) return 1;
        if(fmemo[n]) return fmemo[n];
        return fmemo[n] = n * fact(n - 1) % MOD;
    }

    ll ifact(ll n){
        if(n == 0) return 1;
        if(ifmemo[n]) return ifmemo[n];
        return ifmemo[n] = imemo[n] * ifact(n - 1) % MOD;
    }

    ll com(ll n, ll k){
        if(k > n) return 0;
        if(k == n || k == 0) return 1;
        return (fact(n) * ifact(k) % MOD) * ifact(n - k) % MOD;
    }
};

int main()
{
    ll n;
    cin >> n;
    ll a[1002];
    for(int i = 0; i < n; i++) cin >> a[i];
    ll dp[1002];
    dp[n] = 0;
    Combination com(10000);
    for(int i = n - 1; i >= 0; i--){
        dp[i] = dp[i + 1];
        if(a[i] > 0){
            for(int j = i + a[i]; j < n; j++){
                dp[i] = (dp[i] + com.com(j - i - 1, a[i] - 1) * (dp[j + 1] + 1)) % MOD;
            }
        }
    }
    cout << dp[0] << endl;
}