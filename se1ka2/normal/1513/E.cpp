#include <iostream>
#include <vector>
#include <map>
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
    int n;
    cin >> n;
    ll a[100005];
    map<ll, ll> mp;
    ll s = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
        s += a[i];
    }
    if(s % n){
        cout << 0 << endl;
        return 0;
    }
    ll m = s / n;
    ll c[3]{0};
    for(int i = 0; i < n; i++){
        if(a[i] > m) c[0]++;
        if(a[i] < m) c[1]++;
        if(a[i] == m) c[2]++;
    }
    Combination com(n);
    if(c[0] <= 1 || c[1] <= 1){
        ll ans = com.fact[n];
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            ans = ans * modpow(com.fact[itr->second], MOD - 2) % MOD;
        }
        cout << ans << endl;
    }
    else{
        ll t[2];
        t[0] = com.fact[c[0]];
        t[1] = com.fact[c[1]];
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            if(itr->first > m) t[0] = t[0] * modpow(com.fact[itr->second], MOD - 2) % MOD;
            if(itr->first < m) t[1] = t[1] * modpow(com.fact[itr->second], MOD - 2) % MOD;
        }
        cout << t[0] * t[1] * 2 % MOD * com.com(n, c[2]) % MOD << endl;
    }
}