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

#define sq(x) ((x) * (x))

ll x[5005], y[5005];
bool used[5005];

int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld", x + i, y + i);
    }
    int cur = 1; used[1] = true;
    for (int idx = 1; idx <= n; idx++) {
        printf("%d ", cur);
        if (idx == n) continue;
        ll maxdist = 0; int maxpt = 0;
        for (int j = 1; j <= n; j++) {
            if (used[j]) continue;
            ll dis = sq(x[j] - x[cur]) + sq(y[j] - y[cur]);
            if (dis >= maxdist) {
                maxdist = dis; maxpt = j;
            }
        }
        cur = maxpt; used[maxpt] = true;
    }
    return 0;
}