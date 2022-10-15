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

void work(void)
{
    ll a, b, n; scanf("%lld%lld%lld", &a, &b, &n);
    int ans = 0;
    while (a <= n && b <= n) {
        if (a < b) {
            a += b;
        } else {
            b += a;
        }
        ans++;
    }
    printf("%d\n", ans);
}

int main()
{
    int T; scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        work();
    }
    return 0;
}