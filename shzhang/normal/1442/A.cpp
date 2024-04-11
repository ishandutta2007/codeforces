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

int a[30005];
int minv[30005];

void work()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    int minsub = 0;
    for (int i = 2; i <= n; i++) {
        int subamt = max(max(minsub, a[i] - a[i - 1]), 0);
        a[i] -= subamt; minsub = max(minsub, subamt);
        if (a[i] < 0) {
            printf("NO\n"); return;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (a[i-1] < a[i]) {
            printf("NO\n"); return;
        }
    }
    printf("YES\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}