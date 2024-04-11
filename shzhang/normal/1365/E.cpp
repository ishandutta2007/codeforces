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

ll a[505];

int main()
{
    ll ans = 0;
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = j; k <= n; k++) {
                ans = max(ans, a[i] | a[j] | a[k]);
            }
        }
    }
    printf("%lld", ans);
    return 0;
}