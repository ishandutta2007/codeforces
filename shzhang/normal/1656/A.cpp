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

void work()
{
    int n; scanf("%d", &n);
    int minv = 1000000005; int maxv = 0;
    int minpos = 0, maxpos = 0;
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) {
        if (a[i] < minv) {
            minpos = i; minv = a[i];
        }
        if (a[i] > maxv) {
            maxpos = i; maxv = a[i];
        }
    }
    printf("%d %d\n", minpos, maxpos);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}