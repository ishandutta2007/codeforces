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

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int n, m;
        scanf("%d%d", &n, &m);
        int ans = 2;
        if (n == 1) ans--;
        if (m == 1) ans--;
        printf("%d\n", ans);
    }
    return 0;
}