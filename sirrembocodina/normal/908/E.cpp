#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

string a[100];
bool used[100100];
ll fact[100100];
ll ifact[100100];
ll d[100100];

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

int main() {
    fact[0] = 1;
    forn (i, 100099) {
        fact[i + 1] = fact[i] * (i + 1) % mod;
    }
    forn (i, 100100) {
        ifact[i] = inv(fact[i]);
    }
    d[0] = 1;
    for (int i = 1; i < 1010; ++i) {
        forn (j, i) {
            ll cur = fact[i - 1] * ifact[j] % mod;
            cur *= ifact[i - 1 - j];
            cur %= mod;
            cur *= d[j];
            d[i] += cur % mod;
            d[i] %= mod;
        }
    }
    ios::sync_with_stdio(false);
    int n, m;
    cin >> m >> n;
    forn (i, n) {
        cin >> a[i];
    }
    ll ans = 1;
    forn (j, m) {
        if (used[j]) {
            continue;
        }
        int x = 1;
        for (int k = j + 1; k < m; ++k) {
            bool ok = true;
            forn (i, n) {
                if (a[i][j] != a[i][k]) {
                    ok = false;
                }
            }
            if (ok) {
                ++x;
                used[k] = true;
            }
        }
//        cerr << x << endl;
//        cerr << fact[x] << endl;
        ans *= d[x];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}