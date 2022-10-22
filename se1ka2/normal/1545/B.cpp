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
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        int j = n - 1;
        for(int i = n - 1; i >= 0; i--){
            j = min(j, i);
            if(s[i] == '1'){
                while(j >= 0 && s[j] == '1') j--;
                if(j == -1) break;
                if((i - j) % 2) continue;
                swap(s[i], s[j--]);
            }
        }
        int k;
        for(k = 0; k < n; k++){
            if(s[k] == '0') break;
        }
        k /= 2;
        int l = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0') l++;
        }
        Combination com(n * 2);
        cout << com.com(k + l, l) << endl;
    }
}