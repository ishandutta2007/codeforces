#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll r, k, binom[300][300];
const ll MOD = 1e9 + 7;

ll mpow(ll b, ll e) {
    ll res = 1;
    for(ll k = 1; k <= e; k *= 2) {
        if(k & e) res = (res * b) % MOD;
        b = (b * b) % MOD;
    }
    return res;
}

ll count(ll t) {
    ll res = 0;
    for(int br = 0; br <= t; br++) {
        int bc = t - br;
        if(br > r || bc > r)
            continue;
        ll cells = (r * br + r * bc - br * bc);
        ll ways = (mpow(k - 1, cells) * mpow(k, r * r - cells)) % MOD;
        ways = (ways * binom[r][br]) % MOD;
        ways = (ways * binom[r][bc]) % MOD;
        res = (res + ways) % MOD;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int i = 0; i < 300; i++)
        binom[i][0] = 1;
    for(int i = 1; i < 300; i++)
        for(int j = 1; j <= i; j++)
            binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % MOD;

    cin >> r >> k;
    ll tot = 0;
    for(int i = 1; i <= r + r; i++) {
        ll amt = count(i);
        if(i % 2)
            tot = (tot + amt) % MOD;
        else
            tot = (tot - amt) % MOD;
    }
    ll res = (mpow(k, r*r) - tot) % MOD;
    cout << (res + MOD) % MOD << '\n';
}