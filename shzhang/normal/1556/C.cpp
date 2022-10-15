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
ll a[1005];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
    }
    ll ans = 0;
    for (int i = 2; i <= n; i += 2) {
        ans += min(a[i] - 1LL, a[i-1] - 1LL);
    }
    for (int i = 1; i <= n; i++) {
        ll cur = 0, minval = 0;
        for (int j = i; j <= n; j++) {
            cur += a[j] * (ll)(j % 2 ? 1 : -1);
            minval = min(minval, cur);
            ll l = -minval;
            ll left = ((i - 1) % 2 == 0 ? 0 : a[i-1] - 1);
            ll right = ((j + 1) % 2 == 1 ? 0 : a[j+1] - 1);
            ll r = min(left, right - cur);
            //printf("%lld %lld ", l, r);
            //printf("%lld %lld\n", l, r);
            ans += max(r - l + 1, 0LL);
            //printf("%d %d %lld %lld %lld %lld %lld\n", i, j, cur, minval, l, r, max(r - l + 1, 0LL));
        }
    }
    printf("%lld", ans);
    return 0;
}