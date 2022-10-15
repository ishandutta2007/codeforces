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

int a[2005], b[2005], c[2005], d[2005];
int minsafe[1000005];

int main()
{
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d%d", a + i, b + i);
    for (int i = 1; i <= m; i++) scanf("%d%d", c + i, d + i);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!(a[i] <= c[j] && b[i] <= d[j])) continue;
            int r = c[j] - a[i];
            int y = d[j] - b[i];
            //printf("pair %d %d\n", i, j);
            minsafe[r] = max(minsafe[r], y + 1);
            //for (int x = 1; x <= 10; x++) printf("%d ", minsafe[x]);
            //printf("\n");
        }
    }
    for (int i = 1000001; i >= 0; i--) {
        minsafe[i] = max(minsafe[i], minsafe[i+1]);

    }
    int ans = 1000000000;
    for (int i = 0; i <= 1000001; i++) {
        ans = min(ans, i + minsafe[i]);
        //if (i <= 10) printf("%d ",minsafe[i]);
    }
    printf("%d", ans);
    return 0;
}