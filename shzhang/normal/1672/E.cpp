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

int query(int x)
{
    if (x == 0) return 0;
    printf("? %d\n", x);
    fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}

int main()
{
    int n; scanf("%d", &n);
    int l = 1; int r = 10000000;
    while (l < r) {
        int mid = (l + r) / 2;
        if (query(mid) == 1) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    int s = l;
    int ans = s;
    for (int k = 1; k <= n; k++) {
        int queryres = query(s / k);
        if (queryres) {
            ans = min(ans, queryres * (s / k));
        }
    }
    printf("! %d", ans);
    return 0;
}