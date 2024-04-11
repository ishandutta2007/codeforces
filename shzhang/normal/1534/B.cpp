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
ll a[400005];

void work()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    a[0] = a[n+1] = 0;
    ll ans = 0;
    for (int i = 1; i <= n + 1; i++) {
        ans += max(a[i] - a[i-1], a[i-1] - a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] > a[i-1] && a[i] > a[i+1]) {
            ans -= min(a[i] - a[i-1], a[i] - a[i+1]);
        }
    }
    printf("%lld\n", ans);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}