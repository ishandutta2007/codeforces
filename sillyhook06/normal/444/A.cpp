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

int n, m, x, y, z, a[1005];
double ans;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    n = read(), m = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
    for (int i = 1; i <= m; ++i)
    {
        x = read(), y = read(), z = read();
        ans = max(ans, (a[x] + a[y] + 0.) / z);
    }
    printf("%.15lf\n", ans);
    return 0;
}