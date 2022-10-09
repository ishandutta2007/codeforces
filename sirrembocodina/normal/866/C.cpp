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

int n, r;
int f[60], s[60];
ld p[60];
ld d[60][5010];

ld ans(ld e) {
    forn (i, r + 1) {
        d[n][i] = 0;
    }
    for (int i = n - 1; i >= 0; --i) {
        forn (j, r + 1) {
            if (i) {
                d[i][j] = e;
            } else {
                d[i][j] = 1e100;
            }
            ld a = e, b = e;
            if (j - f[i] >= 0) {
                a = d[i + 1][j - f[i]];
            }
            if (j - s[i] >= 0) {
                b = d[i + 1][j - s[i]];
            }
            d[i][j] = min(d[i][j], p[i] * (f[i] + a) + (1 - p[i]) * (s[i] + b));
        }
    }
    return d[0][r];
}

int main() {
    cin >> n >> r;
    forn (i, n) {
        int tmp;
        cin >> f[i] >> s[i] >> tmp;
        p[i] = tmp * ld(0.01);
//        cerr << double(p[i]) << endl;
    }
    ld l = 0, r = 1e10;
    forn (q, 100) {
        ld m = (l + r) / 2;
//            cerr << double(ans(m)) << endl;
        if (ans(m) > m) {
            l = m;
        } else {
            r = m;
        }
    }
    cout.precision(16);
    cout << fixed << double(ans(l)) << endl;
    return 0;
}