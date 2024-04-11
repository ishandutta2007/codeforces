#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <cassert>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sqr(a) ((a) * (a))
#define all(a) a.begin(), a.end()

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;

const ld pi = 3.1415926535897932384626433832795l;

const ll mod = 1000000007;

int d[2][5010], s[5010];

int main() {
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    --a;
    --b;
    forn (i, n) {
        d[0][i] = 0;
    }
    d[0][a] = 1;
    forn (q, k) {
        s[0] = 0;
        forn (i, n) {
            s[i + 1] = (s[i] + d[q & 1][i]) % mod;
        }
        forn (i, n) {
            int res = 0;
            if (i < b) {
                res = (s[i + ((b - i + 1) >> 1)] - d[q & 1][i] + mod) % mod;
            } else if (i > b) {
                res = (s[n] - s[b + ((i - b) >> 1) + 1] + mod) % mod;
                res = (res - d[q & 1][i] + mod) % mod;
            }
            d[(q + 1) & 1][i] = res;
        }
    }
    int ans = 0;
    forn (i, n) {
        ans += d[k & 1][i];
        ans %= mod;
    }
    cout << ans;
    return 0;
}