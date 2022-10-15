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

int n;
int pos1[400005], pos2[400005];

void work()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x); pos1[x] = i;
    }
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x); pos2[x] = i;
    }
    for (int i = 1; i <= n; i++) uf[i] = i;
    for (int i = 1; i <= n; i++) {
        un(pos1[i], pos2[i]);
    }
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        if (fin(i) == i) {
            ans *= 2;
            ans %= 1000000007;
        }
    }
    printf("%d\n", ans);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}