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
#define rep(i,n) for (int i=0;i<n;++i)

const int N = 1005;
int n, m, x, y, ans, a[N], p[N];
bool b[N][N], c[N];
bool cmp(const int i, const int j)
{
    return a[i] > a[j];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    n = read(), m = read();
    rep(i, n) a[i] = read(), p[i] = i;
    sort(p, p + n, cmp);
    rep(i, m) x = read() - 1, y = read() - 1, b[x][y] = b[y][x] = 1;
    rep(k, n)
    {
        int i = p[k];
        c[i] = 1;
        rep(j, n) if (!c[j] && b[i][j]) ans += a[j];
    }
    printf("%d\n", ans);
    return 0;
}