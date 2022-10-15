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
    int n, k; scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    int inc = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i] > a[i-1]) inc++;
    }
    if (k == 1) {
        printf("%d\n", inc == 0 ? 1 : -1);
    } else {
        printf("%d\n", max((inc / (k-1)) + (inc % (k - 1) ? 1 : 0), 1));
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}