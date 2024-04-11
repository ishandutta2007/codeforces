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
ll a[5005];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    ll ans = 9000000000000000000LL;
    for (int zpos = 1; zpos <= n; zpos++) {
        ll cur = 0;
        ll val = 0;
        for (int i = zpos - 1; i >= 1; i--) {
            ll needed = (val / a[i]) + 1;
            cur += needed;
            val = needed * a[i];
        }
        val = 0;
        for (int i = zpos + 1; i <= n; i++) {
            ll needed = (val / a[i]) + 1;
            cur += needed;
            val = needed * a[i];
        }
        ans = min(ans, cur);
    }
    printf("%lld", ans);
    return 0;
}