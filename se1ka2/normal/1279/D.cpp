#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll modpow(ll x, ll n){
    ll res = 1;
    ll r = x;
    while(n){
        if(n % 2) res = res * r % MOD;
        r = r * r % MOD;
        n /= 2;
    }
    return res;
}

int b[1000002];
vector<int> v[1000002];

int main()
{
    ll n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        v[i].resize(k);
        for(int j = 0; j < k; j++){
            cin >> v[i][j];
            b[v[i][j]]++;
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll r = modpow(n, MOD - 2) * modpow(n, MOD - 2) % MOD * modpow((ll)v[i].size(), MOD - 2) % MOD;
        for(int x : v[i]) ans = (ans + b[x] * r % MOD) % MOD;
    }
    cout << ans << endl;
}