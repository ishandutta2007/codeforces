#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 4e5 + 10;
const ll mod = 998244353;
int pos[MAXN], sa[MAXN], n, k;

ll fac[MAXN], ifac[MAXN];

ll binom(ll n, ll k) {
    if(k < 0 || k > n)
        return 0;
    ll res = (fac[n] * ifac[k]) % mod;
    return (res * ifac[n - k]) % mod;
}

ll modpow(ll b, ll e) {
    ll ans = 1;
    for (; e; b = b * b % mod, e /= 2)
        if (e & 1) ans = ans * b % mod;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fac[0] = 1;
    for(ll k = 1; k < MAXN; k++)
        fac[k] = (k * fac[k - 1]) % mod;

    ifac[MAXN - 1] = modpow(fac[MAXN - 1], mod - 2);
    for(ll i = MAXN - 1; i >= 1; i--)
        ifac[i - 1] = (i * ifac[i]) % mod;

    cin >> n >> k;
    int used = 0;
    for(int i = 0; i < n; i++) {
        cin >> sa[i];
        pos[sa[i]] = i;
    }
    pos[n] = -1;
    int ptr = 0;
    while(ptr < n) {
        used++;
        int cur = ptr;
        while(cur + 1 < n && pos[sa[cur] + 1] < pos[sa[cur + 1] + 1])
            cur++;
        ptr = cur + 1;
    }
    cout << binom(n + k - used, n) << '\n';
}