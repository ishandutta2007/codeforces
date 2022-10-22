#include <algorithm>
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
        int n, k;
        cin >> n;
        k = 2;
        int a[200005];
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        Combination com(n);
        ll ans = 0;
        for(ll i = 0; i < n; i++){
            ll j = upper_bound(a, a + n, a[i] + k) - a - 1;
            ans += (j - i) * (j - i - 1) / 2;
        }
        cout << ans << endl;
    }
}