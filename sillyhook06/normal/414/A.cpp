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

int n, m, k, a[100005];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    n = read(), k = read(), m = 1000000000;
    if (n / 2 > k || n == 1 && k) return puts("-1"), 0;
    for (int i = 0; i < n / 2; ++i)
    {
        if (i + 1 == n / 2) a[i * 2] = k, a[i * 2 + 1] = 2 * k;
        else a[i * 2] = m--, a[i * 2 + 1] = m--, --k;
    }
    if (n & 1) a[n - 1] = m;
    rep(i, n) printf("%d ", a[i]);
    return 0;
}