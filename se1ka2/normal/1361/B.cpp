#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll modpow(ll x, ll n){
    ll res = 1, r = x;
    while(n){
        if(n % 2) res = res * r % MOD;
        r = r * r % MOD;
        n /= 2;
    }
    return res;
}

ll k[1000006];

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll n, p;
        scanf("%lld %lld", &n, &p);
        for(int i = 0; i < n; i++) scanf("%lld", &k[i]);
        if(p == 1){
            printf("%lld\n", n % 2);
            continue;
        }
        sort(k, k + n, greater<ll>());
        ll d = 1;
        bool f = false;
        for(int i = 1; i < n; i++){
            if(f){
                d = d * modpow(p, k[i - 1] - k[i]) % MOD;
            }
            else if(d != 0){
                ll s = k[i - 1] - k[i];
                for(; s > 0; s--){
                    if(d > n){
                        d %= MOD;
                        f = true;
                        break;
                    }
                    d = d * p;
                }
                if(d > n){
                    f = true;
                }
                d = d * modpow(p, s) % MOD;
            }
            if(!f && d == 0) d = 1;
            else d = (d + MOD - 1) % MOD;
        }
        printf("%lld\n", d * modpow(p, k[n - 1]) % MOD);
    }
}