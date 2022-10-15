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

int a[100005];

void work(void)
{
    int n, x; scanf("%d%d", &n, &x);
    int total = 0; bool good = false;
    int min_good_pos = 100000000;
    int max_good_pos = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        total += a[i];
        if (a[i] % x) {
            good = true; min_good_pos = min(min_good_pos, i);
            max_good_pos = max(max_good_pos, i);
        }
    }
    if (!good) {
        printf("-1\n"); return;
    }
    if (total % x) {
        printf("%d\n", n); return;
    }
    printf("%d\n", max(n - min_good_pos, max_good_pos - 1));
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}