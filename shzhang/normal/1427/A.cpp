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

int a[55];

void work()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += a[i];
    if (sum == 0) {
        printf("NO\n"); return;
    } else {
        printf("YES\n");
        if (sum < 0) {
            for (int i = 1; i <= n; i++) {
                if (a[i] < 0) printf("%d ", a[i]);
            }
            for (int i = 1; i <= n; i++) {
                if (a[i] >= 0) printf("%d ", a[i]);
            }
        } else {
            for (int i = 1; i <= n; i++) {
                if (a[i] > 0) printf("%d ", a[i]);
            }
            for (int i = 1; i <= n; i++) {
                if (a[i] <= 0) printf("%d ", a[i]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}