#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const int MD = 1000000007;

#define ll long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(x) (int)((x).size())
#define FOR(i, a, b) for (int _tmp = (b), i = (a); i <= _tmp; ++i)

typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef pair < long double, long double > pdd;

int n, m, r;
int g[65][65][65];
int f[65][65][65];
int dp[65][65][65];

int main()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> r;
    FOR(it, 1, m) {
        FOR(i, 1, n) {
            FOR(j, 1, n) {
                cin >> g[it][i][j];
                f[it][i][j] = g[it][i][j];
            }
        }
        FOR(k, 1, n) {
            FOR(i, 1, n) {
                FOR(j, 1, n) {
                    f[it][i][j] = min(f[it][i][j], f[it][i][k] + f[it][k][j]);
                }
            }
        }
    }
    FOR(p, 0, 62) {
        FOR(s, 1, n) {
            FOR(t, 1, n) {
                dp[p][s][t] = p == 0 && s == t ? 0 : MD;
                FOR(k, 1, m) {
                    if (p == 0) {
                        dp[p][s][t] = min(dp[p][s][t], f[k][s][t]);
                    }
                }
            }
        }
    }
    FOR(p, 0, 62) {
        FOR(s, 1, n) {
            FOR(t, 1, n) {
                if (dp[p][s][t] < MD) {
                    FOR(nx, 1, n) {
                        dp[p + 1][s][nx] = min(dp[p + 1][s][nx], dp[p][s][t] + dp[0][t][nx]);
                    }
                }
            }
        }
    }
    FOR(rr, 1, r) {
        int s, t, k;
        cin >> s >> t >> k;
        int ans = MD;
        FOR(i, 0, min(k, 60)) {
            ans = min(ans, dp[i][s][t]);
        }
        cout << ans << endl;
    }
    return 0;
}