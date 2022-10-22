#include <iostream>
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

int main()
{
    ll n, m, a;
    cin >> n >> m >> a;
    ll b[200005];
    b[0] = 0;
    ll ans = 1;
    ll h = modpow(2, MOD - 2);
    for(int i = 1; i <= m; i++){
        cin >> b[i];
        ll r = modpow(a, b[i] - b[i - 1]);
        ans = ans * r % MOD * (r + 1) % MOD * h % MOD;
    }
    ans = ans * modpow(a, n - b[m] * 2) % MOD;
    cout << ans << endl;
}