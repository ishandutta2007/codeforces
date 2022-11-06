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

int n, m, ans;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    n = read();
    if (n & 1)
    {
        --n, m = n / 2;
        for (int i = 1; i < m; ++i) printf("%d %d %d\n", i, i + 1, (m - i) * 2 - (i + 1 < m));
        for (int i = 1; i <= m; ++i) printf("%d %d %d\n", i, i + m, 1);
        printf("%d %d %d\n", n, n + 1, 1);
        for (int i = 1; i < m; ++i) printf("%d %d\n", m + i, m + i + 1);
        printf("%d %d\n", n - 1, n + 1);
    }
    else
    {
        m = n / 2;
        for (int i = 1; i < m; ++i) printf("%d %d %d\n", i, i + 1, (m - i) * 2 - 1);
        for (int i = 1; i <= m; ++i) printf("%d %d %d\n", i, i + m, 1);
        for (int i = 1; i < m; ++i) printf("%d %d\n", m + i, m + i + 1);
        printf("%d %d\n", n - 2, n);
    }
    return 0;
}