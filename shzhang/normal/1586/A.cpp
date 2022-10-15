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

int a[105];

void work()
{
    int n; scanf("%d", &n);
    int s = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i); s += a[i];
    }
    bool prime = true;
    for (int i = 2; i < s; i++) {
        if (s % i == 0) prime = false;
    }
    if (!prime) {
        printf("%d\n", n);
        for (int i = 1; i <= n; i++) printf("%d ", i);
    } else {
        int exclude = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] % 2 == 1) exclude = i;
        }
        printf("%d\n", n - 1);
        for (int i = 1; i <= n; i++) {
            if (i != exclude)
                printf("%d ", i);
        }
    }
    printf("\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}