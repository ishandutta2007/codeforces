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

void work()
{
    int n, k; scanf("%d%d", &n, &k);
    if ((n + 1) / 2 < k) {
        printf("-1\n");
    } else {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j && i % 2 == 1 && (i + 1) / 2 <= k) {
                    printf("R");
                } else {
                    printf(".");
                }
            }
            printf("\n");
        }
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}