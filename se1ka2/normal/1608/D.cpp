#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

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
    string s[100005];
    for(int i = 0; i < n; i++) cin >> s[i];
    int b[2]{0}, w[2]{0};
    for(int i = 0; i < n; i++){
        if(s[i][0] == 'W') w[0]++;
        if(s[i][0] == 'B') b[0]++;
        if(s[i][1] == 'W') w[1]++;
        if(s[i][1] == 'B') b[1]++;
    }
    ll ans = 0;
    Combination com(n);
    for(int i = 0; i <= n; i++){
        if(w[0] > i || w[1] > n - i || b[0] > n - i || b[1] > i) continue;
        ans = (ans + com.com(n - w[0] - b[0], i - w[0]) * com.com(n - w[1] - b[1], i - b[1])) % MOD;
    }
    ll c = 1;
    bool bw = true, wb = true;
    for(int i = 0; i < n; i++){
        int k;
        if(s[i] == "BB" || s[i] == "WW") k = 0;
        else if(s[i] == "??") k = 2;
        else k = 1;
        if(s[i][0] == 'B' || s[i][1] == 'W') wb = false;
        if(s[i][0] == 'W' || s[i][1] == 'B') bw = false;
        c = c * k % MOD;
    }
    ans = (ans + MOD - (c - bw - wb)) % MOD;
    cout << ans << endl;
}