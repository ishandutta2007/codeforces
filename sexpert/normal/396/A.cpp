#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 5e4;
const ll MOD = 1e9 + 7;
int prime[MAX];
ll fac[MAX], ifac[MAX];

ll inv(ll b) {
    ll e = MOD - 2, res = 1;
    for(ll k = 1; k <= e; k *= 2) {
        if(k & e) res = (res * b) % MOD;
        b = (b * b) % MOD;
    }
    return res;
}

void sieve() {
    for(int p = 2; p < MAX; p++) {
        if(prime[p])
            continue;
        for(int q = p; q < MAX; q += p)
            prime[q] = p;
    }
}

ll binom(ll n, ll k) {
    if(n < k)
        return 0;
    ll res = (ifac[k] * ifac[n - k]) % MOD;
    return (res * fac[n]) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fac[0] = 1;
    for(int i = 1; i < MAX; i++)
        fac[i] = (i * fac[i - 1]) % MOD;
    ifac[MAX - 1] = inv(fac[MAX - 1]);
    for(int i = MAX - 1; i >= 1; i--)
        ifac[i - 1] = (i * ifac[i]) % MOD;
    sieve();
    int n;
    cin >> n;
    map<int, int> cnt;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        for(int p = 2; p < MAX; p++) {
            if(a % p)
                continue;
            while(a % p == 0) {
                cnt[p]++;
                a /= p;
            }
        }
        if(a > 1)
            cnt[a]++;
    }
    ll res = 1;
    for(auto p : cnt) {
        int x = p.second;
        res = (res * binom(x + n - 1, x)) % MOD;
    }
    cout << res << '\n';
}