#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

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
    int n, k;
    cin >> n >> k;
    P p[300005];
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        p[i] = P(l, r);
    }
    sort(p, p + n);
    priority_queue<int, vector<int>, greater<int>> que;
    Combination com(n);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        while(!que.empty() && que.top() < p[i].first) que.pop();
        ans = (ans + com.com((int)que.size(), k - 1)) % MOD;
        que.push(p[i].second);
    }
    cout << ans << endl;
}