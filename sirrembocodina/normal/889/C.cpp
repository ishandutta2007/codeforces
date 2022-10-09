#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <ctime>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;
typedef long double ld;

int mod = 1000000007;

int pw(int a, int n) {
    ll res = 1;
    ll sq = a;
    while (n) {
        if (n & 1) {
            res *= sq;
            res %= mod;
        }
        sq *= sq;
        sq %= mod;
        n /= 2;
    }
    return res;
}

int inv(int a) {
    return pw(a, mod - 2);
}

ll d[1000100];
ll s[1000100];
ll fact[1000100];

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    fact[0] = 1;
    forn (i, n) {
        fact[i + 1] = (fact[i] * (i + 1)) % mod;
    }
    for (int l = k + 1; l <= n; ++l) {
        d[l] = ((l - k - 1) + (s[l - 1] - s[l - k - 1] + mod)) % mod;
        d[l] = (d[l] * fact[l - 2]) % mod;
        s[l] = (s[l - 1] + d[l] * inv(fact[l - 1])) % mod;
    }
    ll ans = 0;
    for (int l = 1; l <= n; ++l) {
        ll cur = d[l];
        cur = (cur * fact[n - 1]) % mod;
        cur = (cur * inv(fact[l - 1])) % mod;
        ans = (ans + cur) % mod;
    }
    cout << ans << endl;
    return 0;
}