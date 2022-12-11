#include <cassert>
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

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb(i) push_back(i)
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 1e-8;
const ldb PI = acos(-1.0);
const int MAXN = 510;

pair<int, int> c[MAXN][MAXN];
int ans[MAXN][MAXN];

int main() {
#ifdef LOCAL
    freopen("b.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    forn(i, n) {
        forn(j, m) {
            c[i][j] = {i, j};
            ans[i][j] = 0;
        }
    }
    forn(i, q) {
        int tp;
        scanf("%d", &tp);
        if (tp == 1) {
            int r;
            scanf("%d", &r);
            r--;
            pair<int, int> t = c[r][0];
            forn(j, m - 1) {
                c[r][j] = c[r][j + 1];
            }
            c[r][m - 1] = t;
        } else if (tp == 2) {
            int col;
            scanf("%d", &col);
            col--;
            pair<int, int> t = c[0][col];
            forn(j, n - 1) {
                c[j][col] = c[j + 1][col];
            }
            c[n - 1][col] = t;
        } else {
            int x, y, val;
            scanf("%d%d%d", &x, &y, &val);
            x--, y--;
            int nx = c[x][y].first;
            int ny = c[x][y].second;
            ans[nx][ny] = val;
        }
        /*
        forn(i, n) {
            forn(j, m) {
                cerr << c[i][j].first << ',' << c[i][j].second << ' ';
            }
            cerr << '\n';
        }*/
    }
    forn(i, n) {
        forn(j, m) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}