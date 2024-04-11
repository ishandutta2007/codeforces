#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;

int mod = 1000000007;

int power(long long a, long long b) {
    long long res = 1;
    long long sq = a % mod;
    while (b) {
        if (b & 1) {
            res *= sq;
            res %= mod;
        }
        sq *= sq;
        sq %= mod;
        b >>= 1;
    }
    return res;
}

int INV[100];

int inv(long long a) {
    if (a < 100) {
        if (INV[a] == 0) {
            INV[a] = power(a, mod - 2);
        }
        return INV[a];
    }
    return power(a, mod - 2);
}

int d[10100][60];

int main() {
    ios::sync_with_stdio(0);
    long long n;
    int k;
    cin >> n >> k;
    vector<int> a, p;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i) {
            continue;
        }
        int x = 0;
        while (n % i == 0) {
            n /= i;
            x++;
        }
        a.pb(i);
        p.pb(x);
    }
    if (n > 1) {
        a.pb(n % mod);
        p.pb(1);
    }
    forn (i, a.size()) {
//        cerr << a[i] <<" " << p[i] << endl;
    }
    long long ans = 1;
    forn (i, a.size()) {
        a[i] %= mod;
        forn (l, k + 1) {
            forn (j, p[i] + 1) { 
                d[l][j] = 0;
            }
        }
        d[0][p[i]] = 1;
        forn (j, k) {
            forn (l, p[i] + 1) {
                forn (m, l + 1) {
                    d[j + 1][m] += (d[j][l] * 1ll * inv(l + 1)) % mod;
                    if (d[j][l]) { 
//                        cerr << (d[j][l] * 1ll * inv(l + 1)) % mod << " !"<< endl;
                    }
                    d[j + 1][m] %= mod;
                }
            }
        }
        int sum = 0;
        int cp = 1;
        forn (j, p[i] + 1) {
            sum += (d[k][j] * 1ll * cp) % mod;
            cp = (cp * 1ll * a[i]) % mod;
            sum %= mod;
        }
        ans *= sum;
//        cerr << sum << endl;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}