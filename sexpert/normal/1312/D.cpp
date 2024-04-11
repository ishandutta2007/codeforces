#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;
const int MAXN = 2e5 + 10;
ll fac[MAXN], ifac[MAXN], p2[MAXN];

ll inv(ll b) {
    ll e = MOD - 2, res = 1;
    for(ll k = 1; k <= e; k *= 2) {
        if(k & e) res = (res * b) % MOD;
        b = (b * b) % MOD;
    }
    return res;
}

ll binom(ll n, ll k) {
    if(k > n)
        return 0;
    ll res = (ifac[k] * ifac[n - k]) % MOD;
    return (res * fac[n]) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	fac[0] = 1;
    p2[0] = 1;
    for(int i = 1; i < MAXN; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
        p2[i] = (p2[i - 1] * 2) % MOD;
    }
    ifac[MAXN - 1] = inv(fac[MAXN - 1]);
    for(int i = MAXN - 1; i >= 1; i--)
        ifac[i - 1] = (ifac[i] * i) % MOD;
    
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    if(n == 2) {
        cout << "0\n";
        return 0;
    }
    for(int pk = 2; pk <= m; pk++) {
        ll res = (binom(pk - 2, n - 3) * p2[n - 3]) % MOD;
        res = (res * (pk - 1)) % MOD;
        ans += res;
        if(ans >= MOD)
            ans -= MOD;
    }
    cout << ans << '\n';
}