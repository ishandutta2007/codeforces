#include <bits/stdc++.h>
using namespace std;

#define N 100100
int n;
typedef long long ll;
ll mod, p;
ll q, phi;
int al;

map <ll, bool> mp;

ll big_rand(ll m) {
    return 1ll * rand() * rand() % m;
}
ll multi(ll x, ll y, ll m, int d = 1) {
    if (!x || !y) return 0;
    return (((x & ((1ll << d) - 1)) * y) % m + (multi(x >> d, y, m, d) << d) % m) %m;
}
ll modmul(ll x, ll y, ll m) {
    int d = 63 - __builtin_clzll(m) + 1;
    return d <= 31 ? x * y % m : multi(x, y, m, 63 - d);
}
ll powmod(ll x, ll y, ll m) {
    ll rlt = 1;
    while (y) {
        if (y & 1) rlt = modmul(rlt, x, m);
        x = modmul(x, x, m), y >>= 1;
    }
    return rlt;
}
bool Miller_Rabbin(ll n) {
    if (n == 2) return 1;
    if (n < 2 || !(n & 1)) return 0;
    int k = __builtin_ctzll(n - 1);
    ll m = n >> k;
    int step = 7;
    for (int i = 0, j; i < step; i ++) {
        ll x = big_rand(n - 2) + 2;
        x = powmod(x, m, n);
        if (x == 1) continue;
        for (j = 0; j < k; j ++) {
            if (x == n - 1) break;
            x = modmul(x, x, n);
        }
        if (j >= k) return 0;
    }
    return 1;
}
ll gcd(ll x, ll y) {
    while (y) {
        ll z = x % y;
        x = y, y = z;
    }
    return x;
}
ll func(ll x, ll m) {
    return (modmul(x, x, m) + 1) % m;
}
ll Pollard(ll n) {
    if (Miller_Rabbin(n)) return n;
    if (!(n & 1)) return 2;
    for (ll i = 1; ; i ++) {
        ll x = i, y = func(x, n), rlt = gcd(y - x, n);
        while (rlt == 1) {
            x = func(x, n);
            y = func(func(y, n), n);
            rlt = gcd((y - x + n) % n, n) % n;
        }
        if (rlt > 0 && rlt < n) return rlt;
    }
}
vector <ll> pf;
void go(ll x) {
    ll y = Pollard(x);
    if (y == x) {
        pf.push_back(y);
        return;
    }
    go(y), go(x / y);
}
ll a[33];
int b[33], cnt;
vector <ll> ddd;
void prime_factorization(ll m) {
    pf.clear();
    go(m);
    sort(pf.begin(), pf.end());
    cnt = 0;
    for (int i = 0; i < pf.size(); i ++) {
        if (!i || pf[i] != pf[i - 1]) a[++cnt] = pf[i], b[cnt] = 1;
        else b[cnt] ++;
    }
}


bool check(ll x, ll y, ll p) {
    if (x == 1) return 0;
    while (1) {
        if (powmod(x, y, mod) != 1) return 1;
        if (y == 1) return 0;
        ll lst;
        while (y > 1 && powmod(x, y, mod) == 1) y >>= 1, lst = p, p = modmul(p, p, mod);
        x = modmul(x, lst, mod);
    }
    return 0;
}

int main() {
    scanf("%d %I64d %I64d", &n, &mod, &p);
    for (q = 2; q <= 1000000; q ++) if (mod % q == 0) break;
    if (q <= 1000000) {
        al = 0;
        ll x = mod;
        while (x % q == 0) x /= q, al ++;
    }
    else {
        q = sqrt(mod) - 5;
        while (q * q < mod) q ++;
        if (q * q == mod) al = 2;
        else q = mod, al = 1;
    }
    phi = mod / q * (q - 1);
    if (p % q == 0) {
        if (phi - 1 < n) puts("-1");
        else {
            ll x = 2;
            while (n --) {
                if (x % q == 0) x ++;
                printf("%I64d ", x);
                x ++;
            }
        }
        return 0;
    }
    ll y = 1;
    if (q > 2) prime_factorization(q - 1);
    if (al > 1) a[++cnt] = q, b[cnt] = al - 1;
    ddd.push_back(1);
    for (int i = 1; i <= cnt; i ++) {
        for (int j = ddd.size() - 1; j >= 0; j --) {
            ll x = ddd[j];
            for (int k = 0; k < b[i]; k ++) {
                x *= a[i];
                ddd.push_back(x);
            }
        }
    }
    int sz = ddd.size();
    sort(ddd.begin(), ddd.end());
    for (int i = 0; i < sz; i ++) {
        if (powmod(p, ddd[i], mod) == 1) {
            y = ddd[i]; break;
        }
    }
    if (phi - y < n) return puts("-1"), 0;
    if (y < 500000) {
        ll k = 1;
        for (int i = 0; i < y; i ++) mp[k] = 1, k = modmul(k, p, mod);
        assert(k == 1), k = 1;
        while (n --) {
            while (k % q == 0 || mp[k]) k ++;
            printf("%I64d ", k);
            k ++;
        }
        return 0;
    }
    ll rt = 2;
    if (q != 2) {
        while (rt % q == 0 || powmod(rt, y, mod) == 1) rt ++;
    }
    else {
        while (rt % q == 0 || !check(rt, y, p)) rt ++;
    }
    for (int i = 0; i < n; i ++) printf("%I64d ", rt), rt = modmul(rt, p, mod);
    return 0;
}