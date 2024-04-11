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
int a[5005];

ll b[5005];

void work()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            b[j] += max((ll)a[i] + i - j, 0LL);
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, b[i]);
    printf("%lld\n", ans - 1);
    for (int i = 1; i <= n; i++) b[i] = 0;
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}