#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long double ld;

int d[82][82][82][82]; // l r m k
vector<pair<int, int> > g[82];

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    forn (i, n + 1) {
        forn (j, n + 1) {
            forn (k, n + 1) {
                forn (l, n + 1) {
                    d[i][j][k][l] = 2000000000;
                }
            }
        }
    }
    int K, m;
    cin >> K >> m;
    forn (i, m) {
        int x, y, z;
        cin >> x >> y >> z;
        --x;
        --y;
        g[x].pb(mp(y, z));
    }
    forn (i, n) {
        d[0][n][i][1] = 0;
    }
    for (int k = 1; k < K; ++k) {
        forn (l, n) {
            for (int r = 1; r <= n; ++r) {
                for (int m = l; m < r; ++m) {
                    forn (i, g[m].size()) {
                        int v = g[m][i].fs, len = g[m][i].sc;
                        if (v < l || v >= r || v == m) {
                            continue;
                        }
                        if (v < m) {
                            d[l][m][v][k + 1] = min(d[l][m][v][k + 1], d[l][r][m][k] + len);
                        } else {
                            d[m + 1][r][v][k + 1] = min(d[m + 1][r][v][k + 1], d[l][r][m][k] + len);
                        }
                    }
                }
            }
        }
    }
    int ans = 2000000000;
    forn (i, n + 1) {
        forn (j, n + 1) {
            forn (l, n + 1) {
                ans = min(ans, d[i][j][l][K]);
            }
        }
    }
    if (ans == 2000000000) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}