#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

ll mod = 1000000007;

ll pw(ll a, ll n) {
    ll res = 1, sq = a % mod;
    while (n) {
        if (n & 1) {
            res *= sq;
            res %= mod;
        }
        sq = (sq * sq) % mod;
        n /= 2;
    }
    return res;
}

ll inv(ll x) {
    return pw(x, mod - 2);
}

ll a[10100];
ll pa[10100];
ll pb[10100];
ll pab[10100];
ll ipa[10100];
ll ipb[10100];
ll ipab[10100];
ll d[1010][1010];
ll S[1010][1010];

int main() {
    ios::sync_with_stdio(false);
    ll k, a, b;
    cin >> k >> a >> b;
    ll is = inv(a + b);
    a = ll(a) * is % mod;
    b = ll(b) * is % mod;
    pa[0] = pb[0] = pab[0] = 1;
    forn (i, 10099) {
        pa[i + 1] = (ll(pa[i]) * a) % mod;
        pb[i + 1] = (ll(pb[i]) * b) % mod;
//        pab[i + 1] = (ll(pab[i]) * (a + b)) % mod;
    }
/*    forn (i, 10100) {
        ipa[i] = inv(pa[i]);
        ipb[i] = inv(pb[i]);
        ipab[i] = inv(pab[i]);
    }*/
    d[0][0] = 1;
//    S[0][0] = ;
    for (ll s = 1; s < k; ++s) {
        forn (a, s + 1) {
            if (a == 0) {
                continue;
            }
            ll cur = S[s - a][a];
            if (a == s) {
                cur = d[0][0] * pa[s - 1] % mod;
            }
/*            forn (x, a + 1) {
                cur += d[s - a][a - x] * ll(pa[x]);
                cur %= mod;
            }*/
            cur *= b;
            d[s][a] = cur % mod;
            S[s][a] = (S[s][a - 1] * pa[1] + d[s][a]) % mod;
//            S[s][a + 1] = S[s][a + 1] * pa[1] % mod;
        }
        for (int i = s + 1; i < 1010; ++i) {
            S[s][i] = S[s][i - 1] * pa[1] % mod;
        }
    }
    ll ans = 0;
//    cerr << d[3][1] << endl;
    forn (s, k) {
        forn (x, s + 1) {
//            cerr << s << " " << x << " " << d[s][x] << endl;
            ll pre = max(0ll, k - s - x);
            ll pos = max(k, s + x);
//            cerr << pre << " " << pos << endl;
            ll cur = pos;
            cur += ll(a) * inv(b);
            cur %= mod;
//            cur *= inv(b);
//            cur %= mod;
            cur *= pa[pre];
            cur %= mod;
            if (x == 0 && s == 0) {
//            if (pre) {
                cur *= inv(a);
                cur %= mod;
            }
//            cerr << cur << endl;
            ans += cur * d[s][x] % mod;
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}