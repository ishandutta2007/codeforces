#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const ll MOD = 1e9 + 7;

ll ans(ll x) {
    if(x == 0)
        return 0;
    ll res = 0;
    ll bl = 0, odds = 0, evens = 0;
    while(x >= 1LL << bl) {
        x -= 1LL << bl;
        if(bl % 2) {
            evens += 1LL << bl;
            evens %= MOD;
        }
        else {
            odds += 1LL << bl;
            evens %= MOD;
        }
        bl++;
    }
    if(bl % 2)
        evens += x;
    else
        odds += x;

    odds %= MOD;
    evens %= MOD;
    return ((odds * odds) % MOD + (evens * (evens + 1)) % MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll l, r;
    cin >> l >> r;
    cout << ((ans(r) - ans(l - 1)) % MOD + MOD)%MOD << '\n';
}