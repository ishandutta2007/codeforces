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

ll a[20];

void work()
{
    int n; scanf("%d", &n);
    ll cnt = 0;
    ll maxv = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
        while (a[i] % 2 == 0) {
            a[i] /= 2;
            cnt++;
        }
        maxv = max(maxv, a[i]);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == maxv) {
            ans += a[i] << cnt;
            maxv = 0;
        } else {
            ans += a[i];
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