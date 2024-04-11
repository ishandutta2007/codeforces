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

int k[300005], c[300005];

void work()
{
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", k + i);
    sort(k + 1, k + n + 1);
    ll curans = 0; int nxt = n;
    ll best = 0;
    for (int i = 1; i <= m; i++) {
        scanf("%d", c + i);
    }
    for (int i = 1; i <= n; i++) curans += c[k[i]];
    best = curans;
    for (int i = 1; i <= m; i++) {
        if (nxt >= 1 && k[nxt] >= i) {
            curans -= c[k[nxt]];
            curans += c[i];
            nxt--;
            best = min(best, curans);
        }
    }
    printf("%lld\n", best);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}