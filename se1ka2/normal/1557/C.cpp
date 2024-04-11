#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

long long modpow(long long x, long long n){
    long long  res = 1;
    long long mul = x;
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
    std::vector<long long> fact;
    std::vector<long long> ifact;
    
    Combination(int maxn) : maxn(maxn){
        fact.resize(maxn + 1);
        ifact.resize(maxn + 1);
        fact[0] = 1;
        for(int i = 1; i <= maxn; i++) fact[i] = fact[i - 1] * i % MOD;
        ifact[maxn] = modpow(fact[maxn], MOD - 2);
        for(int i = maxn - 1; i >= 0; i--) ifact[i] = ifact[i + 1] * (i + 1) % MOD;
    }

    long long com(int n, int k){
        if(k > n || k < 0) return 0;
        if(k == n || k == 0) return 1;
        return (fact[n] * ifact[k] % MOD) * ifact[n - k] % MOD;
    }
};

int main()
{
    int t;
    cin >> t;
    Combination com(200005);
    while(t--){
        int n, k;
        cin >> n >> k;
        ll ans = 0;
        if(n % 2){
            ll s = 1;
            for(int i = 0; i < n; i += 2) s = (s + com.com(n, i)) % MOD;
            ans = modpow(s, k);
        }
        else{
            ll s = 0, u = 0;
            for(int i = 0; i < n; i += 2) s = (s + com.com(n, i)) % MOD;
            for(int i = 0; i <= n; i++) u = (u + com.com(n, i)) % MOD;
            ll l[200005], r[200005];
            l[0] = 1;
            for(int i = 1; i <= k; i++) l[i] = l[i - 1] * s % MOD;
            r[k] = 1;
            for(int i = k - 1; i >= 0; i--) r[i] = r[i + 1] * u % MOD;
            ans = l[k];
            for(int i = 0; i < k; i++){
                ans = (ans + l[i] * r[i + 1]) % MOD;
            }
        }
        cout << ans << endl;
    }
}