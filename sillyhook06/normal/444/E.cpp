#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
inline int	read()
{
    int x = 0;
    char ch = getchar();
    bool positive = 1;
    for (; ch < '0' || ch > '9'; ch = getchar())	if (ch == '-')  positive = 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar())	x = x * 10 + ch - '0';
    return positive ? x : -x;
}
#define link Link
#define next Next
#define elif else if
#define rep(i,n) for (int i=1;i<=n;++i)

const int N = 3005 * 4, inf = 1 << 28;
int n, l, S = 0, T = 1, p[N], c[N], x[N], y[N], z[N], xx[N], yy[N], ed[N * 8], data[N * 8], next[N * 8], son[N], d[N], f[N];
bool cmp(const int i, const int j)
{
    return z[i] < z[j];
}
void add(int x, int y, int z)
{
    ed[++l] = y, data[l] = z, next[l] = son[x], son[x] = l;
    ed[++l] = x, data[l] = 0, next[l] = son[y], son[y] = l;
}
int get(int x)
{
    return f[x] == x ? x : f[x] = get(f[x]);
}
bool build()
{
    int h = 0, t = 1;
    memset(d, -1, sizeof(d)), d[f[1] = S] = 0;
    while (h < t)
    {
        int x = f[++h];
        for (int y, p = son[x]; p; p = next[p]) if (data[p])
            {
                if (d[y = ed[p]] < 0) d[y] = d[x] + 1, f[++t] = y;
                if (y == T) return 1;
            }
    }
    return 0;
}
int dinic(int x, int low)
{
    if (x == T) return low;
    int w = 0, res;
    for (int y, p = son[x]; p; p = next[p]) if (data[p] && d[y = ed[p]] == d[x] + 1)
            if (res = dinic(y, min(low - w, data[p]))) data[p] -= res, data[p ^ 1] += res, w += res;
    if (!w) d[x] = -1;
    return w;
}
int work()
{
    int Z = n, ans = 0;
    memset(son, 0, sizeof(son)), l = 1;
    rep(i, n) add(S, i * 2, 1), add(i * 2 + 1, T, c[i]), f[i] = i;
    rep(i, n - 1)
    {
        int X = get(x[p[i]]), Y = get(y[p[i]]);
        f[++Z] = Z , xx[i] = X, yy[i] = Y;
        f[X] = Z, f[Y] = Z;
        add(X * 2, Z * 2, inf), add(Y * 2, Z * 2, inf);
        add(Z * 2 + 1, X * 2 + 1, inf), add(Z * 2 + 1, Y * 2 + 1, inf);
    }
    for (int i = n - 1; i; --i)
    {
        int X = xx[i], Y = yy[i];
        add(X * 2, Y * 2 + 1, inf), add(Y * 2, X * 2 + 1, inf);
        while (build()) ans += dinic(S, inf);
        if (ans == n) return z[p[i]];
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    n = read();
    if (n == 1)
    {
        printf("%d\n", 0);
        return 0;
    }
    rep(i, n - 1) x[i] = read(), y[i] = read(), z[i] = read(), p[i] = i;
    rep(i, n) c[i] = read();
    sort(p + 1, p + n, cmp);
    printf("%d\n", work());
    return 0;
}