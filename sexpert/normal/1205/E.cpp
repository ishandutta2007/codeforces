#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

const int MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;
int prime[MAXN];
ll phis[MAXN], powk[MAXN];

ll mpow(ll b, ll e) {
    ll res = 1;
    for(ll k = 1; k <= e; k *= 2) {
        if(k & e) res = (res * b) % MOD;
        b = (b * b) % MOD;
    }
    return res;
}

ll inv(ll b) {
    return mpow(b, MOD - 2);
}

vi prod(vi a, int x) {
    vi res = a;
    for(auto y : a)
        res.push_back(x * y);
    return res;
}

ll f(int y, int n) {
    if(n == 0)
        return 0;
    int x = y;
    vi facs = {1};
    while(x > 1) {
        int p = prime[x];
        facs = prod(facs, -p);
        while(x % p == 0)
            x /= p;
    }
    int res = 0;
    for(auto f : facs) {
        int k = n/abs(f);
        if(f > 0)
            res += k;
        else
            res -= k;
    }
    return res;
}

void sieve() {
    for(int p = 2; p < MAXN; p++) {
        if(prime[p]) continue;
        for(int q = p; q < MAXN; q += p)
            prime[q] = p;
    }
}

ll n, k;

ll calc(ll s, ll d) {
    if(s <= n - 1)
        return f(s/d, s/d - 1) * powk[max(s - n, d)];
    else
        return (f(s/d, (n - 1)/d) - f(s/d, (s - n)/d)) * powk[max(s - n, d)];

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    sieve();
    ll ans = 0;
    cin >> n >> k;
    powk[0] = 1;
    for(int i = 1; i < MAXN; i++)
        powk[i] = (k * powk[i - 1]) % MOD;

    for(ll d = 1; d <= 2*n - 2; d++) {
        for(ll s = d; s <= 2*n - 2; s += d) {
            ans = (ans + calc(s, d)) % MOD;
        }
    }
    ans = (ans * inv(powk[n])) % MOD;
    cout << ans << '\n';
}