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

int a[200005];
int used[40];

int work(int l, int r, int bit)
{
    //printf("%d %d %d\n", l, r, bit);
    if (l == r) {
        return 1;
    }
    int bound = 0;
    for (int i = l; i <= r; i++) {
        if (a[i] & (1 << bit)) {
            bound = i; break;
        }
    }
    if (bound == 0 || bound == l) {
        return work(l, r, bit - 1);
    } else {
        return max(work(l, bound - 1, bit - 1) + 1, work(bound, r, bit - 1) + 1);
    }
}

int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    sort(a + 1, a + n + 1);
    printf("%d", n - work(1, n, 30));
    return 0;
}