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
int a[100005];

void work()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    bool hasbig = false;
    ll tot = 0; ll odds = 0;
    for (int i = 2; i < n; i++) {
        if (a[i] > 1) hasbig = true;
        tot += a[i];
        if (a[i] % 2) odds++;
    }
    if (!hasbig || (n == 3 && a[2] % 2)) {
        printf("-1\n"); return;
    }
    printf("%lld\n", (tot + odds) / 2LL);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}