#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;
ll ifac[MAXN], fac[MAXN];
int cnt_n, cnt_p;
const ll MOD = 1e9 + 7;

ll inv(ll b) {
    ll e = MOD - 2, res = 1;
    for(ll k = 1; k <= e; k *= 2) {
        if(k & e) res = (res * b) % MOD;
        b = (b * b) % MOD;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fac[0] = 1;
    for(ll i = 1; i < MAXN; i++)
        fac[i] = (i * fac[i - 1]) % MOD;

    ifac[MAXN - 1] = inv(fac[MAXN - 1]);
    for(ll i = MAXN - 1; i >= 1; i--)
        ifac[i - 1] = (i * ifac[i]) % MOD;

    int n;
    cin >> n;
    vector<ll> v(n);
    ll sum = 0;
    for(auto &x : v) {
        cin >> x;
        sum += x;
    }
    if(sum % n) {
        cout << "0\n";
        return 0;
    }
    ll tar = sum / n;
    map<ll, int> cnt;
    for(auto &x : v) {
        x -= tar;
        if(x != 0)
            cnt[x]++;
        if(x < 0)
            cnt_n++;
        if(x > 0)
            cnt_p++;
    }

    if(cnt_n == 0 || cnt_p == 0) {
        cout << "1\n";
        return 0;
    }

    if(cnt_n == 1 || cnt_p == 1) {
        ll base = fac[n];
        for(auto &[x, c] : cnt)
            base = (base * ifac[c]) % MOD;
        ll c0 = n - cnt_n - cnt_p;
        base = (base * ifac[c0]) % MOD;
        cout << base << '\n';
        return 0;
    }

    ll base = (2LL * fac[cnt_n] * fac[cnt_p]) % MOD;
    for(auto &[x, c] : cnt)
        base = (base * ifac[c]) % MOD;
    ll x = cnt_n + cnt_p;
    base = (base * fac[n] % MOD);
    base = (base * ifac[x] % MOD);
    base = (base * ifac[n - x] % MOD);

    cout << base << '\n';
}