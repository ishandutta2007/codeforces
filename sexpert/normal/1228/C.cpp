#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x, n;
const int MAX = 1e5 + 5;
int prime[MAX];
const ll INF = 1e18 + 5;
const ll MOD = 1e9 + 7;

void sieve() {
    for(int p = 2; p < MAX; p++) {
        if(prime[p])
            continue;
        for(int q = p; q < MAX; q += p)
            prime[q] = p;
    }
}

ll mpow(ll b, ll e) {
    ll res = 1;
    for(ll k = 1; k <= e; k *= 2) {
        if(k & e) res = (res * b) % MOD;
        b = (b * b) % MOD;
    }
    return res;
}

ll h(ll p) {
    ll tot = 0, m = p;
    while(true) {
        tot += n / m;
        if(m > INF / p)
            break;
        m *= p;
    }
    return mpow(p, tot);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    sieve();
    cin >> x >> n;
    ll res = 1;

    vector<ll> primes;
    for(int p = 2; p < MAX; p++) {
        if(x % p)
            continue;
        primes.push_back(p);
        while(x % p == 0)
            x /= p;
    }
    if(x > 1)
        primes.push_back(x);
    for(auto p : primes)
        res = (res * h(p)) % MOD;
    cout << res << '\n';
}