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
    while(t--){
        ll n, l, r;
        cin >> n >> l >> r;
        Combination com(n);
        if(n % 2){
            ll ans = (com.com(n, n / 2) + com.com(n, (n + 1) / 2)) * min(r - n, 1 - l) % MOD;
            for(ll i = min(r - n, 1 - l) + 1;; i++){
                ll m = n - max(0ll, i + n - r) - max(0ll, i + l - 1);
                ll k = n / 2 - max(0ll, i + n - r);
                ans = (ans + com.com(m, k) + com.com(m, k + 1)) % MOD;
                if(m <= 0) break;
            }
            cout << ans << endl;
        }
        else{
            ll ans = com.com(n, n / 2) * min(r - n, 1 - l) % MOD;
            for(ll i = min(r - n, 1 - l) + 1;; i++){
                ll m = n - max(0ll, i + n - r) - max(0ll, i + l - 1);
                ll k = n / 2 - max(0ll, i + n - r);
                ans = (ans + com.com(m, k)) % MOD;
                if(m <= 0) break;
            }
            cout << ans << endl;
        }
    }
}