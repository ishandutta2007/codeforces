#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

int n;
ll r1, r2, r3, d;
ll a[1000005];
ll cost[1000005][2];
ll f[1000005][4][2];

int main()
{
    scanf("%d%lld%lld%lld%lld", &n, &r1, &r2, &r3, &d);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 2; k++) {
                f[i][j][k] = 1000000000000000000LL;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cost[i][0] = min(r1, r3) * a[i] + r3;
        cost[i][1] = min(r2, min(r1, r3) * a[i] + min(r1, r2)) + min(r1, min(r2, r3));
    }
    // SUBTRACT D?
    f[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 2; k++) {
                //printf("%d %d %d: %lld\n", i, j, k, f[i][j][k]);
                for (int nxtj = 0; nxtj < 4; nxtj++) {
                    if ((j == 1 || j == 3) && (nxtj != 1 && nxtj != 3)) continue;
                    if (k && (((j+2) / 2) + ((nxtj + 1) / 2)) < 2) continue;
                    for (int nxtk = 0; nxtk < 2; nxtk++) {
                        ll& nxtf = f[i+1][nxtj][nxtk];
                        nxtf = min(nxtf, f[i][j][k] + cost[i+1][nxtk] + (nxtj + 1) * d);
                    }
                }
            }
        }
    }
    ll ans = 1000000000000000000LL;
    for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 2; k++) {
            if (k && j < 2) continue;
            ans = min(ans, f[n][j][k]);
        }
    }
    printf("%lld", ans - d);
    return 0;
}