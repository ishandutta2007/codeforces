#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

ll mexp(ll b, ll e) {
    if(e == 0) return 1;
    if(e % 2) return (b * mexp(b, e - 1)) % MOD;
    ll p = mexp(b, e / 2);
    return (p * p) % MOD;
}

ll inv(ll b) {
    return mexp(b, MOD - 2);
}

int n, m, sw, tl, sl, wl, wh, like[55], cur;
ll w[55], res[55];
ll mem[55][55][55][55];

ll dp(ll rem, ll w, ll wlo, ll who) {
    if(mem[rem][w][wlo][who] != -1) return mem[rem][w][wlo][who];
    if(rem == 0) return mem[rem][w][wlo][who] = w;
    ll rl = wl + wlo;
    ll rh = wh - who;
    ll sig = w + rl + rh;
    ll den = inv(sig);
    ll res = 0;
    if(like[cur]) {
        res = (((w * den)%MOD) * dp(rem - 1, w + 1, wlo, who)) % MOD;
        res = (res + ((rl*den)%MOD)*dp(rem - 1, w, wlo + 1, who)) % MOD;
        if(rh)
            res = (res + ((rh*den)%MOD)*dp(rem - 1, w, wlo, who + 1)) % MOD;
    }
    else {
        if(w) res = (((w * den)%MOD) * dp(rem - 1, w - 1, wlo, who)) % MOD;
        res = (res + ((rl*den)%MOD)*dp(rem - 1, w, wlo + 1, who)) % MOD;
        if(rh)
            res = (res + ((rh*den)%MOD)*dp(rem - 1, w, wlo, who + 1)) % MOD;
    }
    return mem[rem][w][wlo][who] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> like[i];
    for(int i = 0; i < n; i++)
        cin >> w[i];
    for(int i = 0; i < n; i++)
        sw += w[i];
    for(int i = 0; i < n; i++)
        tl += like[i];
    for(int i = 0; i < n; i++)
        if(like[i]) sl += w[i];

    for(int i = 0; i < n; i++) {
        memset(mem, -1, sizeof mem);
        cur = i;
        wl = 0;
        wh = 0;
        for(int j = 0; j < n; j++) {
            if(j == i) continue;
            if(like[j])
                wl += w[j];
            else
                wh += w[j];
        }
        cout << dp(m, w[i], 0, 0) << '\n';
    }
}