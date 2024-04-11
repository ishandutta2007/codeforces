#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cstring>
#include <memory>
#include <string>
#include <vector>
#include <cstdio>
#include <ctime>
#include <set>
#include <iostream>

using namespace std;

#define fs first
#define sc second
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair

typedef long long ll;

const int mod = 1000000007;

ll c[5][200100];
ll fact[200100];
ll ifact[200100];

ll power(ll a, int n) {
    ll res = 1, sq = a;
    while (n) {
        if (n % 2) {
            res *= sq;
            res %= mod;
        }
        sq *= sq;
        sq %= mod;
        n /= 2;
    }
    return res;
}

ll inv(ll a) {
    return power(a, mod - 2);
}

ll C(int n, int k) {
    ll res = fact[n] * ifact[k];
    res %= mod;
    res *= ifact[n - k];
    return res % mod;
}

int main() {
    ios::sync_with_stdio(false);
    fact[0] = 1;
    forn (i, 200010) {
        fact[i + 1] = (fact[i] * (i + 1)) % mod;
        ifact[i] = inv(fact[i]);
    }
    int n;
    cin >> n;
    c[0][0] = 1;
    int sgn = 1;
    if (n % 4 < 2) {
        sgn = -1;
    }
    int r = (n - 1) % 4;
    int len = (n - 1) - r;
    forn (i, len + 1) {
        c[0][i] = i % 2 ? 0 : C(len / 2, i / 2);
    }
    forn (i, r) {
        for (int j = len + i; j >= 0; --j) {
            c[i + 1][j] += c[i][j];
            c[i + 1][j] %= mod;
            c[i + 1][j + 1] += c[i][j] * sgn + mod;
            c[i + 1][j + 1] %= mod;
            sgn *= -1;
        }
    }
    ll ans = 0;
    forn (i, len + r + 1) {
        int x;
        cin >> x;
        ans += c[r][i] * x;
        ans %= mod;
//        cerr << c[r][i] << " ";
    }
//    cerr << endl;
    cout << ans << endl;
/*    forn (i, n) {
        if (i % 4 == 0) {
            cerr << i << ": ";
            forn (j, i + 1) {
                if (j % 2 == 0) {
                    cerr << c[i][j] - C(i / 2, j / 2) << " ";
                }
            }
            cerr << endl;
        }
        for (int j = i; j >= 0; --j) {
            c[i + 1][j] += c[i][j];
            c[i + 1][j + 1] += c[i][j] * sgn;
            sgn *= -1;
        }
    }*/
    return 0;
}