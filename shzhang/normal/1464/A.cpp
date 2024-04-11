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

int t;

int uf[500005];

int fin(int a)
{
    if (uf[a] == a) return a;
    return uf[a] = fin(uf[a]);
}

void un(int a, int b)
{
    a = fin(a); b = fin(b);
    if (a == b) return;
    uf[a] = b;
}

void work(void)
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) uf[i] = i;
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        if (x == y) continue;
        if (fin(x) == fin(y)) {
            ans += 2;
        } else {
            ans += 1;
        }
        un(x, y);
    }
    printf("%d\n", ans);
}

int main()
{
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}