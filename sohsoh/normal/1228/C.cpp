#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

bool is_prime(ll x) {
    if (x == 1) return false;
    ll sq = sqrt(x);
    for (int i = 2; i <= sq; i++) if (x % i == 0) return false;
    return true;
}

int main() {
    ll x, n;
    cin >> x >> n;
    ll sq = sqrt(x);
    vector<ll> v;
    for (int i = 1; i <= sq; i++) {
        if (x % i == 0) {
            if (is_prime(i)) v.push_back(i);
            if (i != x / i && is_prime(x / i)) v.push_back(x / i);
        }
    }

    ll ans = 1;
    for (ll e : v) {
        ll p = e;
        while (p <= n) {
            if ((p * e) / e != p) { // preventing overflow :)
                ans *= poww(p % MOD, n / p, MOD);
                ans %= MOD;
                break;
            }

            ll cnt = n / p - n / (p * e);
            ans *= poww(p % MOD, cnt, MOD);
            ans %= MOD;
            p *= e;
        }
    }

    cout << ans << endl;
    return 0;
}