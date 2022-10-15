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

ll arr[1005][1005];

void work()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 1; j <= 2 * n; j++) {
            scanf("%lld", &(arr[i][j]));
        }
    }
    ll ans = 0;
    for (int i = n + 1; i <= 2 * n; i++) {
        for (int j = n + 1; j <= 2 * n; j++) {
            ans += arr[i][j];
        }
    }
    ans += min(min(min(arr[1][n+1], arr[1][2*n]),
               min(arr[n][n+1], arr[n][2*n])),
               min(min(arr[n+1][1], arr[n+1][n]),
               min(arr[2*n][1], arr[2*n][n])));
    printf("%lld\n", ans);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}