#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <utility>
#include <cstdlib>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <memory.h>
#include <ctime>
#include <cctype>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define all(a) a.begin(), a.end()
#define sqr(a) ((a) * (a))

typedef long double ld;
typedef long long ll;
typedef unsigned char uc;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ld pi = 3.141592653589793238462643l;

ll mod = 1000000007;

int a[1010];

ll ans = 0;

const int M = 10010;

ll s[2][2 * M];
ll t[2 * M];

int calc (int l, int r) {
    if (r - l < 2) {
        return a[l];
    }
    int m = (r + l) / 2;
    int S = calc(l, m) + calc(m, r);
    memset(t, 0, sizeof t);

    memset(s[0], 0, sizeof s[0]);
    s[0][M] = 1;
    for (int i = 0; i < m - l; ++i) {
        int i_ = i & 1;
        int j_ = !i_;
        int pos = m - 1 - i;
        memset(s[j_], 0, sizeof s[j_]);
        for (int j = M - S; j <= M + S; ++j) {
            if (s[i_][j]) {
                (s[j_][j - a[pos]] += s[i_][j]) %= mod;
                (s[j_][j + a[pos]] += s[i_][j]) %= mod;
            }
        }
        for (int j = M - S; j <= M + S; ++j) {
            (t[j] += s[j_][j]) %= mod;
        }
    }

    memset(s[0], 0, sizeof s[0]);
    s[0][M] = 1;
    for (int i = 0; i < r - m; ++i) {
        int i_ = i & 1;
        int j_ = !i_;
        int pos = m + i;
        memset(s[j_], 0, sizeof s[j_]);
        for (int j = M - S; j <= M + S; ++j) {
            if (s[i_][j]) {
                (s[j_][j - a[pos]] += s[i_][j]) %= mod;
                (s[j_][j + a[pos]] += s[i_][j]) %= mod;
            }
        }
        for (int j = M - S; j <= M + S; ++j) {
            (ans += t[j] * s[j_][j]) %= mod;
        }
    }
    return S;
}

int main () {
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif
    int n;
    cin >> n;
    forn (i, n) {
        cin >> a[i];
    }
    calc(0, n);
    cout << ans << endl;
    return 0;
}