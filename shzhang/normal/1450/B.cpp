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

int x[105], y[105];

int absolute(int X)
{
    return X > 0 ? X : -X;
}

void work()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", x + i, y + i);
    }
    for (int i = 1; i <= n; i++) {
        bool good = true;
        for (int j = 1; j <= n; j++) {
            if (absolute(x[i] - x[j]) + absolute(y[i] - y[j]) > k) good = false;
        }
        if (good) {
            printf("1\n"); return;
        }
    }
    printf("-1\n");
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}