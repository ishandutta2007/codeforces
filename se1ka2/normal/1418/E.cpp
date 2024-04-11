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

int main()
{
    int n, m;
    cin >> n >> m;
    ll d[200005];
    for(int i = 0; i < n; i++) cin >> d[i];
    sort(d, d + n);
    ll s[200005];
    s[0] = 0;
    for(int i = 1; i <= n; i++) s[i] = (s[i - 1] + d[i - 1]) % MOD;
    while(m--){
        int a;
        ll b;
        cin >> a >> b;
        int k = lower_bound(d, d + n, b) - d;
        int l = n - k;
        ll ans = 0;
        if(l > a){
            ans = (ans + (s[n] - s[k]) * (l - a) % MOD * modpow(l, MOD - 2)) % MOD;
        }
        if(l >= a){
            ans = (ans + s[k] * (l - a + 1) % MOD * modpow(l + 1, MOD - 2)) % MOD;
        }
        cout << ans << endl;
    }
}