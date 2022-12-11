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
const int MAXN = 151;
const int MAXM = MAXN * (MAXN - 1) / 2 + MAXN;

int dp[MAXN][MAXM];
int q[MAXN];

int main() {
#ifdef LOCAL
    freopen("d.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n, k, s;
    scanf("%d%d%d", &n, &k, &s);
    FOR(i, n) {
        scanf("%d", &q[i]);
    }
    s += k * (k - 1) - k * (k - 1) / 2;
    int t = 0;
    FOR(i, k)
        t += n - i - 1;
    s = min(s, t);
    FOR(i, n + 1)
        FOR(j, MAXM)
            dp[i][j] = INF;
//    cerr << s << '\n';
    dp[0][0] = 0;
    FOR(i, n) {
  //      cerr << "st: " << i <<  ' ' << q[i] << '\n';
        for (int j = min(k - 1, i); j >= 0; --j) {
            FOR(k, s + 1) {
//                cerr << j << ' ' << k << ' ' << dp[j][k] << '\n';
                dp[j + 1][k + i] = min(dp[j + 1][k + i], dp[j][k] + q[i]);
            }
        }
    }
    int ans = INF;
    FOR(i, s + 1) {
        ans = min(ans, dp[k][i]);
    }
    cout << ans << '\n';

                
    
    return 0;
}