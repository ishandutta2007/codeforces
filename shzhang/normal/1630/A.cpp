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

bool used[100000];

void work()
{
    int n, k; scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) used[i] = false;
    if (n == 4 && k == 3) {
        printf("-1\n"); return;
    }
    if (k < n - 1) {
        if (k != 0) {
            printf("%d %d\n", 0, n - 1 - k);
            printf("%d %d\n", k, n - 1);
            used[0] = used[n - 1 - k] = true;
            used[k] = used[n - 1] = true;
        }
    } else {
        printf("%d %d\n", 0, n / 2);
        printf("%d %d\n", 1, n / 2 - 1);
        printf("%d %d\n", n - 2, n - 1);
        used[0] = used[1] = used[n/2 - 1] = used[n/2] =
            used[n-2] = used[n-1] = true;
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            printf("%d %d\n", i, n - 1 - i);
            used[i] = used[n-1-i] = true;
        }
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}