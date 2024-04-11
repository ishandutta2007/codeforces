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

int a[50005][10];

void work()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 5; j++) {
            scanf("%d", &(a[i][j]));
        }
    }
    int best = 1;
    for (int i = 2; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= 5; j++) {
            if (a[i][j] < a[best][j]) cnt++;
        }
        if (cnt >= 3) best = i;
    }
    bool good = true;
    for (int i = 1; i <= n; i++) {
        if (i == best) continue;
        int cnt = 0;
        for (int j = 1; j <= 5; j++) {
            if (a[best][j] < a[i][j]) cnt++;
        }
        if (cnt < 3) good = false;
    }
    if (good) {
        printf("%d\n", best);
    } else {
        printf("-1\n");
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}