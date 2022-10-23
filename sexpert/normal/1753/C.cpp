#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 998244353;
const int MAX = 3e5 + 10;
ll inver[MAX], fac[MAX], ifac[MAX];

ll inv(ll b) {
    ll e = MOD - 2, res = 1;
    for(ll k = 1; k <= e; k *= 2) {
        if(k & e) res = (res * b) % MOD;
        b = (b * b) % MOD;
    }
    return res;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(auto &x : v)
        cin >> x;
    ll s = accumulate(v.begin(), v.end(), 0LL), bin = (n * (n - 1)) / 2, ans = 0, bad = 0;
    bin %= MOD;

    for(int i = 1; i <= s; i++)
        if(v[n - i] == 0)
            bad++;

    for(ll k = 1; k <= bad; k++) {
        ll tmp = bin;
        tmp = (tmp * inver[k]) % MOD;
        tmp = (tmp * inver[k]) % MOD;
        ans = (ans + tmp) % MOD;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fac[0] = 1;
    for(ll n = 1; n < MAX; n++)
        fac[n] = (n * fac[n - 1]) % MOD;

    ifac[MAX - 1] = inv(fac[MAX - 1]);
    for(ll n = MAX - 1; n >= 1; n--)
        ifac[n - 1] = (n * ifac[n]) % MOD;

    for(ll n = 1; n <= MAX - 1; n++)
        inver[n] = (ifac[n] * fac[n - 1]) % MOD;

    int t;
    cin >> t;
    while(t--)
        solve();
}