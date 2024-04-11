#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll modpow(ll x, ll n){
    ll res = 1, r = x;
    while(n){
        if(n & 1) res = res * r % MOD;
        r = r * r % MOD;
        n >>= 1;
    }
    return res;
}

int d[500004][20];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> d[j][i];
    }
    ll ans = 0;
    for(int j = 0; j < m; j++){
        sort(d[j], d[j] + n);
        ll s = 1;
        for(int i = 0; i < n; i++){
            s = s * (d[j][i] - (i + 1)) % MOD * modpow(n - i, MOD - 2) % MOD;
        }
        ans = (ans + (1 + MOD - s)) % MOD;
    }
    cout << ans << endl;
}