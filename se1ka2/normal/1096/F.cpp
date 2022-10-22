#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll modpow(ll x, ll n){
    ll res = 1, r = x;
    while(n){
        if(n % 2) res = res * r % MOD;
        r = r * r % MOD;
        n /= 2;
    }
    return res;
}

template <typename T>
struct BIT
{
    int n;
    vector<T> bit;
    
    BIT(){}
    
    BIT(int n) : n(n){
        bit.resize(n + 1);
    }
    
    T sum(int i){
        i++;
        T res = 0;
        while(i){
            res += bit[i];
            i -= (i & -i);
        }
        return res;
    }
    
    void add(int i, T x){
        i++;
        while(i <= n){
            bit[i] += x;
            i += (i & -i);
        }
    }
};

int main()
{
    ll n;
    cin >> n;
    ll r = 1;
    for(int i = 1; i <= n; i++) r = r * modpow(i, MOD - 2) % MOD;
    int p[200002];
    int q[200002];
    fill(q, q + n, -1);
    for(int i = 0; i < n; i++){
        cin >> p[i];
        p[i]--;
        if(p[i] >= 0) q[p[i]] = i;
    }
    ll ls[200002];
    ls[0] = 0;
    for(int i = 1; i <= n; i++){
        ls[i] = ls[i - 1];
        if(p[i - 1] == -2) ls[i]++;
    }
    BIT<ll> bit(n);
    ll ans = 0;
    ll s = 0;
    ll w = 0;
    for(ll i = n - 1; i >= 0; i--){
        if(q[i] != -1){
            ans = (ans + bit.sum(q[i] - 1) + ls[q[i]] * modpow(ls[n], MOD - 2) % MOD * w) % MOD;
            bit.add(q[i], 1);
            s = (s + ls[n] - ls[q[i]]) % MOD;
        }
        else{
            ans = (ans + s * modpow(ls[n], MOD - 2) % MOD + w * modpow(2, MOD - 2) % MOD) % MOD;
            w++;
        }
    }
    cout << ans << endl;
}