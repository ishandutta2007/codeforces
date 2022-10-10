#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e9 + 10;
const int MAXN = 1e7 + 10;
int sqf[MAXN], cnt[MAXN];
bitset<MAXN> prime;

ll po(ll b, ll e) {
    ll res = 1;
    for(ll k = 1; k <= e; k *= 2) {
        if(k & e) res *= b;
        b *= b;
        res = min(res, INF);
        b = min(b, INF);
    }
    return res;
}

void sieve() {
    for(int p = 2; p < MAXN; p++) {
        if(prime[p])
            continue;
        for(int q = p; q < MAXN; q += p) {
            prime[q] = 1;
            int n = q;
            while(n % p == 0 && (n / p) % p == 0) {
                n /= p;
                n /= p;
            }
            if(n % p == 0)
                sqf[q] *= p;
        }
    }
}

int main() {
    fill(sqf, sqf + MAXN, 1);
    sieve();
    ll n, l, r;
    cin >> n >> l >> r;
    if(n == 1) {
        cout << r - l + 1 << '\n';
        return 0;
    }
    if(n == 2) {
        cout << (r - l + 1)*(r - l) << '\n';
        return 0;
    }
    if(n == 3) {
        ll ans = 0;
        for(int i = l; i <= r; i++) {
            ans += cnt[sqf[i]];
            cnt[sqf[i]]++;
        }
        cout << 2*ans << '\n';
        return 0;
    }
    if(n >= 25) {
        cout << "0\n";
        return 0;
    }
    ll ans = 0;
    for(ll q = 1;;q++) {
        ll den = po(q, n - 1);
        if(den > r)
            break;
        for(ll p = q + 1;;p++) {
            ll num = po(p, n - 1);
            if(__gcd(p, q) > 1)
                continue;
            if(l * po(p / q, n - 1) > r)
                break;
            ll mx = (r * den) / num;
            if(mx < l)
                break;
            ans += (mx/den - (l - 1)/den);
        }
    }
    cout << 2 * ans << '\n';
}