#include <bits/stdc++.h>
using namespace std;
#define M 11111
typedef long long ll;
const ll mod = 1000000007;

ll n, m;
map<ll, ll> mp[M];
vector<ll> v[M];

ll POW(ll a, ll n) {
    ll s = 1;
    while (n) {
        if (n & 1) s = 1ll * s * a % mod;
        n >>= 1;
        a = 1ll * a * a % mod;
    }
    return s;
}

int main() {
    scanf("%d %d", &n, &m);
    if (m == 1) {
        puts("1");
        return 0;
    }
    for (ll i = 1; i <= m; i++) for (ll j = 1; j <= m; j++) {
        if (i != j) {
            mp[i][j] = mp[j][i] = mod - 1;
        } else {
            mp[i][i] = m - 1;
        }
        if (i > j) {
            v[i].push_back(j);
        }
    }
    for (ll i = m + 1; i <= n; i++) {
        mp[i][i] = m;
        for (ll x, j = 1; j <= m; j++) {
            scanf("%I64d", &x);
            mp[i][x] = mod - 1;
            mp[x][i] = mod - 1;
            mp[x][x] ++;
            v[i].push_back(x);
        }
    }

    ll rlt = 1;
    for (ll i = n - 1; i >= 1; i--) {
        ll c = mp[i][i];
        rlt = 1ll * rlt * c % mod;
        if (!c) {
            puts("0");
            return 0;
        }
        c = POW(c, mod - 2);
        if (i == 1) { break; }
        for (ll j, r = 0; r < v[i].size(); r++) {
            j = v[i][r];
            mp[i][j] = 1ll * c * mp[i][j] % mod;
        }
        for (ll j, r = 0; r < v[i].size(); r++) {
            j = v[i][r];
            ll t = mp[j][i];
            for (ll k, s = 0; s < v[i].size(); s++) {
                k = v[i][s];
                ll w = mp[j][k];
                w -= 1ll * mp[i][k] * t % mod;
                if (w < 0) w += mod;
                mp[j][k] = w;
            }
        }
    }
    printf("%I64d\n", rlt);
    return 0;
}