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

int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    sort(a + 1, a + n + 1);
    int lcnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0 && i < n) {
            lcnt++;
        }
    }
    int cur = 1; int bcur = lcnt + 1;
    printf("%d\n", lcnt);
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0 && i < n) {
            printf("%d ", a[cur]); cur++;
        } else {
            printf("%d ", a[bcur]); bcur++;
        }
    }
    return 0;
}