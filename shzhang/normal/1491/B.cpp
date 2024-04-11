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

int absolute(int x)
{
    return x < 0 ? -x : x;
}

void work()
{
    int n, u, v; scanf("%d%d%d", &n, &u, &v);
    bool equal = true; bool ans0 = false;
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        if (i > 1 && a[i] != a[i-1]) equal = false;
        if (i > 1 && absolute(a[i] - a[i-1]) > 1) {
            ans0 = true;
        }
    }
    if (ans0) {
        printf("0\n"); return;
    }
    if (equal) {
        printf("%d\n", v + min(u, v));
    } else {
        printf("%d\n", min(u, v));
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}