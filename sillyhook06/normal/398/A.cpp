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

LL n, m, s, x, y, ans , res;
LL get(LL m, LL i)
{
    LL x = m / i, y = m % i;
    return x * x * (i - y) + (x + 1) * (x + 1) * y;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    n = read() , m = read(), ans = -1LL << 60;
    if (!n)
    {
        printf("%I64d\n", -m * m);
        rep(i, m) printf("x");
        puts("");
        return 0;
    }
    rep(i, n)
    {
        res = (n - i) * (n - i) + i - get(m, i + 2);
        if (res > ans) ans = res, s = i;
    }
    res = n - get(m, n + 1);
    if (res > ans)
    {
        printf("%I64d\n", res);
        s = n + 1, x = m / s, y = m % s;
        rep(i, s)
        {
            if (i) printf("o");
            rep(j, x) printf("x");
            if (i < y) printf("x");
        }
        puts("");
        return 0;
    }
    printf("%I64d\n", ans);
    s += 2, x = m / s, y = m % s;
    rep(i, s)
    {
        if (i) if (i > 1) printf("o");
            else rep(i, n - s + 2) printf("o");
        rep(j, x) printf("x");
        if (i < y) printf("x");
    }
    puts("");
    return 0;
}