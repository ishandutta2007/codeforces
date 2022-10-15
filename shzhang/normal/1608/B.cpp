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

int ans[100005];

void work()
{
    int n, a, b; scanf("%d%d%d", &n, &a, &b);
    if (a + b > n - 2 || a - b < -1 || a - b > 1) {
        printf("-1\n"); return;
    }
    if (a == b) {
        for (int i = 1; i <= a + b + 2; i += 2) {
            ans[i] = (i + 1) / 2;
        }
        for (int i = 2; i <= a + b + 2; i += 2) {
            ans[i] = a + b + 3 - i / 2;
        }
        for (int i = a + b + 3; i <= n; i++) ans[i] = i;
    } else {
        bool flip = false;
        if (a > b) {
            swap(a, b); flip = true;
        }
        for (int i = 1; i <= a + b + 2; i += 2) {
            ans[i] = a + b + 2 - (i - 1) / 2;
        }
        for (int i = 2; i <= a + b + 2; i += 2) {
            ans[i] = i / 2;
        }
        for (int i = a + b + 3; i <= n; i++) ans[i] = i;
        if (flip) {
            for (int i = 1; i <= n; i++) {
                ans[i] = n - ans[i] + 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}