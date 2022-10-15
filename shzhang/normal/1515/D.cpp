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

int a[200005], b[200005];

void work()
{
    int n, l, r; scanf("%d%d%d", &n, &l, &r);
    for (int i = 1; i <= n; i++) a[i] = b[i] = 0;
    for (int i = 1; i <= n; i++) {
        int c; scanf("%d", &c);
        if (i <= l) a[c]++;
        else b[c]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        //printf("%d %d\n", a[i], b[i]);
        while (l - r > 1 && a[i] > b[i] + 1) {
            a[i]--; b[i]++; l--; r++; ans++;
        }
        while (l - r < -1 && a[i] + 1 < b[i]) {
            a[i]++; b[i]--; l++; r--; ans++;
        }
    }
    for (int i = 1; i <= n; i++) {
        //printf("%d %d\n", a[i], b[i]);
        while (l - r > 1 && a[i] > b[i]) {
            a[i]--; b[i]++; l--; r++; ans++;
        }
        while (l - r < -1 && a[i] < b[i]) {
            a[i]++; b[i]--; l++; r--; ans++;
        }
    }
    int x = 0;
    for (int i = 1; i <= n; i++) {
        //printf("%d %d\n", a[i], b[i]);
        x += max(a[i] - b[i], b[i] - a[i]);
    }
    printf("%d\n", ans + x / 2);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}