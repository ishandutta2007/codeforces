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

int r, n;
int t[100005], x[100005], y[100005];
int f[100005];

static inline int absolute(int X)
{
    return X > 0 ? X : -X;
}

int main()
{
    scanf("%d%d", &r, &n);
    t[0] = 0; x[0] = 1; y[0] = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", t + i, x + i, y + i);
    }
    int maxv = -100000000;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = maxv + 1;
        for (int j = i - 1; j >= max(i - 2 * r, 0); j--) {
            int dis = absolute(x[i] - x[j]) + absolute(y[i] - y[j]);
            if (dis <= t[i] - t[j]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }

        if (i - 2 * r >= 0) {
            maxv = max(maxv, f[i - 2 * r]);
        }

        ans = max(ans, f[i]);
    }
    printf("%d", ans);
    return 0;
}