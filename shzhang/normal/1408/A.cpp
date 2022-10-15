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

int a[105], b[105], c[105];
int ans[105];

void work()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) scanf("%d", b + i);
    for (int i = 1; i <= n; i++) scanf("%d", c + i);
    ans[1] = a[1];
    for (int i = 2; i < n; i++) {
        if (a[i] != ans[i-1]) {
            ans[i] = a[i];
        } else {
            ans[i] = b[i];
        }
    }
    if (a[n] != ans[n-1] && a[n] != ans[1]) {
        ans[n] = a[n];
    } else if (b[n] != ans[n-1] && b[n] != ans[1]) {
        ans[n] = b[n];
    } else {
        ans[n] = c[n];
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    printf("\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}