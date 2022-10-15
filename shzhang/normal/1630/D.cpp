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

int n, m;

int GCD(int x, int y)
{
    if (y == 0) return x;
    return GCD(y, x % y);
}

int a[1000005];

void work()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    int g = 0;
    for (int i = 1; i <= m; i++) {
        int x; scanf("%d", &x);
        g = GCD(g, x);
    }
    ll noflip = 0, flip = 0;
    for (int i = 0; i < g; i++) {
        bool state = false;
        int minv = 1000000005;
        ll tot = 0;
        for (int j = (i == 0 ? g : i); j <= n; j += g) {
            if (a[j] < 0) state = !state;
            int absv = max(a[j], -a[j]);
            minv = min(minv, absv);
            tot += (ll)absv;
        }
        if (state) {
            noflip += tot - 2LL * minv;
            flip += tot;
        } else {
            noflip += tot;
            flip += tot - 2LL * minv;
        }
    }
    printf("%lld\n", max(noflip, flip));
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}