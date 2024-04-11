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

const int INF = 1e8;
const ldb EPS = 1e-8;
const ldb PI = acos(-1.0);
const int MAXN = 1100;

char t[MAXN][MAXN];
int d[3][MAXN][MAXN];
bool used[MAXN][MAXN];

const int dx[4] = {1, 0 , -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m;
bool good(pair<int, int> p) {
    return p.first >= 0 && p.first < n && p.second >= 0 && p.second < m ;
}
void bfs(int k) {
    queue<pair<int, int>> q;
    FOR(i, n)
        FOR(j, m) {
            d[k][i][j] = INF;
            if (t[i][j] - '1' == k) {
                d[k][i][j] = 0;
                q.push({i, j});
            }
        }
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        FOR(i, 4) {
            pair<int, int> dest = {cur.first + dx[i], cur.second + dy[i]};
            if (good(dest) && t[dest.first][dest.second] == '.'&& d[k][dest.first][dest.second] >= INF) {
                d[k][dest.first][dest.second] = d[k][cur.first][cur.second] + 1;
                q.push(dest);
            }
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("c.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    scanf("%d%d", &n, &m);
    FOR(i, n)
        FOR(j, m) {
            scanf(" %c", &t[i][j]);
        }
    FOR(k, 3)
        bfs(k);
    FOR(k, 3)
        FOR(k1, 3) {
            if (k == k1)
                continue;
            int dist = INF;
            FOR(i, n) {
                FOR(j, m) {
                    if (t[i][j] - '1' != k)
                        continue;
                    FOR(g, 4) {
                        int nx = i + dx[g];
                        int ny = j + dy[g];
                        if (good({nx, ny})) {
                            dist = min(dist, d[k1][nx][ny]);
                        }
                    }
                }
            }
            FOR(i, n) {
                FOR(j, m) {
                    if (t[i][j] - '1' != k)
                        continue;
                    d[k1][i][j] = dist;
                }
            }
        }
    int ans = INF;
    FOR(i, n) {
        FOR(j, m) {
            int na = d[0][i][j] + d[1][i][j] + d[2][i][j];
            if (t[i][j] == '.')
                na -= 2;
            ans = min(ans, na);
        }
    }
    if (ans >= INF)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
    return 0;
}