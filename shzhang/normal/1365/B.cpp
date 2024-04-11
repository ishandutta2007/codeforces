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
int a[505];
int b[505];

void work(void)
{
    /* solve problem here */
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    int total = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", b + i); total += b[i];
    }
    if (total != 0 && total != n) {
        printf("Yes\n"); return;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i-1] > a[i]) {
            printf("No\n"); return;
        }
    }
    printf("Yes\n");
    /* remember to clean up any global variables if needed */
}

int main()
{
    int T; scanf("%d", &T);
    for (int i = 1; i <= T; i++) work();
    return 0;
}