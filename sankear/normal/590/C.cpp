#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pbk pop_back
#define sz(s) ((int) (s).size())
#define len(s) ((int) (s).size())
#define all(x) (x).begin(), (x).end()
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#define cerr if (0) cerr
#endif
#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define next _next
#define prev _prev
#define link _link
#define rank _rank
#define hash _hash

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long double ld;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(1e3) + 100;

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, -1, 0, 1 };

char a[N][N];
int dp[8][N][N];
vector<pii> q[N * N];

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        scanf("%s", a[i]);
    }
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int z = 0; z < m; ++z) {
                dp[i][j][z] = inf;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] >= '1' && a[i][j] <= '3') {
                dp[(1 << (a[i][j] - '1'))][i][j] = 0;
            }
        }
    }
    for (int i = 1; i < 8; ++i) {
        for (int j = 0; j < N * N; ++j) {
            q[j].clear();
        }
        for (int j = 0; j < n; ++j) {
            for (int z = 0; z < m; ++z) {
                for (int x = 0; x < 4; ++x) {
                    int nj = j + dx[x], nz = z + dy[x];
                    if (nj < 0 || nj >= n || nz < 0 || nz >= m) {
                        continue;
                    }
                    for (int ni = i; ni > 0; ni = (ni - 1) & i) {
                        dp[i][j][z] = min(dp[i][j][z], dp[ni][j][z] + dp[(i ^ ni)][nj][nz]);
                    }
                }
                if (dp[i][j][z] < N * N) {
                    q[dp[i][j][z]].pb(mp(j, z));
                }
            }
        }
        for (int j = 0; j < N * N; ++j) {
            for (int z = 0; z < sz(q[j]); ++z) {
                int x = q[j][z].fs, y = q[j][z].sc;
                for (int h = 0; h < 4; ++h) {
                    int nx = x + dx[h], ny = y + dy[h];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] == '#') {
                        continue;
                    }
                    if (a[nx][ny] == '.' && dp[i][nx][ny] > dp[i][x][y] + 1) {
                        dp[i][nx][ny] = dp[i][x][y] + 1;
                        if (dp[i][nx][ny] < N * N) {
                            q[dp[i][nx][ny]].pb(mp(nx, ny));
                        }
                    }
                    if (a[nx][ny] != '.' && dp[i][nx][ny] > dp[i][x][y]) {
                        dp[i][nx][ny] = dp[i][x][y];
                        q[dp[i][nx][ny]].pb(mp(nx, ny));
                    }
                }
            }
        }
    }
    int ans = inf;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans = min(ans, dp[7][i][j]);
        }
    }
    if (ans == inf) {
        puts("-1");
        return 0;
    }
    cout << ans << endl;
    return 0;
}