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
ll a[200005];

int main()
{
    scanf("%d", &T);
    for (int d = 1; d <= T; d++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", a + i);
        }
        ll ans = 0;
        for (int i = 2; i <= n; i++) {
            if (a[i-1] > a[i]) {
                ans += a[i-1] - a[i];
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}