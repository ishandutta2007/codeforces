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

ll absolute(ll x)
{
    return x < 0 ? -x : x;
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        ll x1, y1, x2, y2; scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
        ll dist = absolute(x2 - x1) + absolute(y2 - y1);
        if (x1 == x2 || y1 == y2) {

        } else {
            dist += 2LL;
        }
        printf("%lld\n", dist);
    }
    return 0;
}