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

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        ll n; scanf("%lld", &n);
        ll oldn = n;
        ll twocnt = 0;
        while (n % 2LL == 0) {
            n /= 2LL; twocnt++;
        }
        if (n == 1) {
            printf("-1\n"); continue;
        }
        ll pwr2 = (1LL << (twocnt + 1LL));
        if (pwr2 <= (1LL << 31LL) && (pwr2 * (pwr2 + 1LL)) / 2LL <= oldn) {
            printf("%lld\n", pwr2);
        } else {
            printf("%lld\n", n);
        }
    }
    return 0;
}