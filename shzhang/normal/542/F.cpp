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

int f[1005][1100][2];

int n, T;

pair<int, int> a[1005];

int main()
{
    scanf("%d%d", &n, &T);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &(a[i].first), &(a[i].second));
    }
    sort(a + 1, a + n + 1);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < (1 << 10); j++) {
            for (int k = 0; k < 2; k++) {
                f[i][j][k] = -1000000000;
            }
        }
    }
    f[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << 10); j++) {
            for (int k = 0; k < 2; k++) {
                int shiftbits = min(a[i+1].first - a[i].first, 15);
                int nxtj = (j >> shiftbits);
                int nxtk = (k | ((j & (1 << (shiftbits - 1))) ? 1 : 0));
                f[i+1][nxtj][nxtk] = max(f[i+1][nxtj][nxtk], f[i][j][k]);
                f[i+1][nxtj + 1][nxtk] = max(f[i+1][nxtj + 1][nxtk], f[i][j][k] + a[i+1].second);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < (1 << 10); i++) {
        for (int k = 0; k < 2; k++) {
            int highbit = -1;
            for (int j = 0; j < 10; j++) {
                if (i & (1 << j)) highbit = j;
            }
            if (a[n].first + highbit < T || (a[n].first + highbit == T && i == (1 << highbit) && k == 0)) {
                /*if (f[n][i][k] == 12) {
                    printf("%d %d\n", i, k);
                }*/
                ans = max(ans, f[n][i][k]);
            }
        }
    }
    printf("%d", ans);
    return 0;
}