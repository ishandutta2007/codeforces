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
int a[105], b[105];
bool f[105][10005];

void work()
{
    scanf("%d", &n);
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i); tot += a[i];
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", b + i); tot += b[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 100 * i; j++) f[i][j] = false;
    }
    f[0][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 100 * i; j++) {
            if ((j >= a[i] && f[i-1][j-a[i]]) ||
                (j >= b[i] && f[i-1][j-b[i]])) f[i][j] = true;
        }
    }
    int bestdiff = 100000000, bestsum = 0;
    for (int i = 0; i <= 100 * n; i++) {
        if (f[n][i]) {
            int newdiff = max(2 * i - tot, tot - 2 * i);
            if (newdiff < bestdiff) {
                bestdiff = newdiff; bestsum = i;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (n - 1) * (a[i] * a[i] + b[i] * b[i]);
        ans -= a[i] * (a[i] - 1);
        ans -= b[i] * (b[i] - 1);
    }
    ans += bestsum * (bestsum - 1);
    ans += (tot - bestsum) * (tot - bestsum - 1);
    printf("%d\n", ans);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}