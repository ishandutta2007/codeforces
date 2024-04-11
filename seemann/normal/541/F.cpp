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

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 1e-8;
const ldb PI = acos(-1.0);
const int MAXN = 1e5;
const int MAXT = 110;

vector<int> a[MAXT];
int dp[2][MAXT][1 << 14];

int main() {
#ifdef LOCAL
    freopen("f.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n, T;
    scanf("%d%d", &n, &T);
    FOR(i, n) {
        int t, q;
        scanf("%d%d", &t, &q);
        a[t].push_back(q);
    }
    FOR(t, T + 1) {
        sort(a[t].begin(), a[t].end());
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 0;
    dp[1][0][0] = 0;
    int m = 1 << 13;
    FOR(t, T) {
        FOR(msk, m) {
            if (dp[0][t][msk] == -1)
                continue;
           // cerr << "0: " << t << ' ' << msk << ' ' << dp[0][t][msk] << '\n';
            //cerr << "1: " << t << ' ' << msk << ' ' << dp[1][t][msk] << '\n';
            int sum = 0;
            int c = 0;
            for (int i = a[t].size() - 1; i >= -1; --i) { 
                dp[0][t + 1][(msk + c) >> 1] = max(dp[0][t + 1][(msk + c) >> 1], dp[0][t][msk] + sum);
                if ((msk + c) % 2 == 0)
                    dp[1][t + 1][(msk + c) >> 1] = max(dp[1][t + 1][(msk + c) >> 1], dp[1][t][msk] + sum);

                c++;
                if (i == -1)
                    break;
                sum += a[t][i];
            }
        }
    }
//    cerr << dp[1][6][0] << '\n';
    if (a[T].size() > 0)
        dp[1][T][1] = max(dp[1][T][1], a[T][a[T].size() - 1]);
    int ans = dp[1][T][1];
    ans = max(ans, dp[0][T][0]);
    cout << ans << '\n';
    return 0;
}