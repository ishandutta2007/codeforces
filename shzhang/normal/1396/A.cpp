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

ll a[100005];

int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    if (n == 1) {
        printf("1 1\n%lld\n1 1\n0\n1 1\n0", -a[1]); return 0;
    }
    printf("1 %d\n", n - 1);
    for (int i = 1; i < n; i++) {
        printf("%lld ", (ll)(((a[i] % n) + n) % n) * (ll)(n - 1));
        a[i] += (ll)(((a[i] % n) + n) % n) * (ll)(n - 1);
    }
    printf("\n2 %d\n", n);
    for (int i = 2; i <= n; i++) {
        printf("%lld ", (ll)(((a[i] % n) + n) % n) * (ll)(n - 1));
        a[i] += (ll)(((a[i] % n) + n) % n) * (ll)(n - 1);
    }
    printf("\n1 %d\n", n);
    for (int i = 1; i <= n; i++) {
        printf("%lld ", -a[i]);
    }
    return 0;
}