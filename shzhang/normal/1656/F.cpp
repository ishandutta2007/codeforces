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

ll a[200005];
ll psum[200005];
ll ssum[200005];

void work()
{
    int n; scanf("%d", &n);
    ll tot = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a + i); tot += a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        psum[i] = psum[i-1] + a[i];
        ssum[i] = tot - psum[i-1];
    }
    bool haspos = (a[n] * (ll)(n-1) + psum[n-1] >= 0);
    bool hasneg = (a[1] * (ll)(n-1) + ssum[2] <= 0);
    if (!(haspos && hasneg)) {
        printf("INF\n");
        for (int i = 0; i <= n + 3; i++) {
            a[i] = 0;
            psum[i] = 0;
            ssum[i] = 0;
        }
        return;
    }
    ll ans = -9000000000000000000LL;
    for (int i = 1; i <= n; i++) {
        ans = max(ans,
        (a[1] - a[i]) * (ssum[i+1] - (ll)(n - i) * a[i]) +
        (a[n] - a[i]) * (psum[i-1] - (ll)(i - 1) * a[i]) -
            (a[1] - a[i]) * (a[n] - a[i])
        - a[i] * a[i] * (ll)(n-1));
    }
    printf("%lld\n", ans);
    for (int i = 0; i <= n + 3; i++) {
        a[i] = 0;
        psum[i] = 0;
        ssum[i] = 0;
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}