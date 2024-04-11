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

int T, n;
int a[200005];
ll k;

int main()
{
    scanf("%d", &T);
    for (int d = 1; d <= T; d++) {
        scanf("%d%lld", &n, &k);
        int maxv = -1000000000, minv = 1000000000;
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
            maxv = max(maxv, a[i]);
            minv = min(minv, a[i]);
        }
        if (k % 2 == 1) {
            for (int i = 1; i <= n; i++) {
                printf("%d ", maxv - a[i]);
            }
        } else {
            for (int i = 1; i <= n; i++) {
                printf("%d ", a[i] - minv);
            }
        }
        printf("\n");
    }
    return 0;
}