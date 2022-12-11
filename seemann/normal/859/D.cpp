#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <bitset>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb push_back
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-8;
const ld PI = acos(-1.0L);
const int MAXN = 1e5;

int main() {
#ifdef LOCAL
    freopen("d.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n;
//    n = 6;
    cin >> n;
    int m = 1 << n;
    vector<vector<ld>> p(m, vector<ld>(m));
    forn(i, m) {
        forn(j, m) {
            int x;
//            x = (i > j ? 100 : 0);
            cin >> x;
            p[i][j] = ((ld)x) / 100;
        }
    }
    vector<vector<ld>> dpp(n + 1, vector<ld>(m));
    vector<vector<ld>> dpe(n + 1, vector<ld>(m));
    forn(i, m) {
        dpp[0][i] = 1;
        dpe[0][i] = 0;
    }
    forn(i, n) {
        forn(j, (1 << (n - i - 1))) {
            forn(k, 2) {
                forn(fs, (1 << i)) {
                    int f = (j << (i + 1)) + (k << i) + fs;
                    dpp[i + 1][f] = 0;
                    dpe[i + 1][f] = dpe[i][f];

                    ld mxs = 0;
                    forn(ss, (1 << i)) {
                        int s = (j << (i + 1)) + ((1 - k) << i) + ss;
                        mxs = max(mxs, dpe[i][s]);
                        dpp[i + 1][f] += dpp[i][s] * p[f][s];
                        dpe[i + 1][f] += (1 << i) * dpp[i][f] * dpp[i][s] * p[f][s];
                    }
                    dpe[i + 1][f] += mxs;
                    dpp[i + 1][f] *= dpp[i][f];
                }
            }
        }
    }
    ld ans = 0;
    forn(i, m) {
        ans = max(ans, dpe[n][i]);
    }
    cout << fixed << setprecision(20) << ans << '\n';
    
    return 0;
}