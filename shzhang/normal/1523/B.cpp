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

int a[1005];

void work()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    printf("%d\n", 3 * n);
    for (int i = 1; i <= n; i += 2) {
        printf("2 %d %d\n", i, i + 1);
        printf("1 %d %d\n", i, i + 1);
        printf("2 %d %d\n", i, i + 1);
        printf("2 %d %d\n", i, i + 1);
        printf("1 %d %d\n", i, i + 1);
        printf("2 %d %d\n", i, i + 1);
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}