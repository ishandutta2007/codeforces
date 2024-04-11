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
const int N = 1 << 21;
int n, m, x, a[N], c[N];
LL ans, res[25][2];
void msort(int d, int l, int r)
{
    if (!d) return;
    int m = l + r >> 1;
    msort(d - 1, l, m), msort(d - 1, m, r);
    int i = l, j = m;
    for (int k = l; k < r; ++k)
    {
        if (j >= r || (i < m && a[i] < a[j])) c[k] = a[i++], res[d][0] += r - j;
        else c[k] = a[j++];
    }
    i = l, j = m;
    for (int k = l; k < r; ++k)
    {
        if (j >= r || (i < m && a[i] <= a[j])) c[k] = a[i++];
        else c[k] = a[j++], res[d][1] += m - i;
    }
    for (int k = l; k < r; ++k) a[k] = c[k];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    n = read();
    rep(i, 1 << n) a[i] = read();
    msort(n, 0, 1 << n);
    for (int i = 0; i <= n; ++i) ans += res[i][1];
    //printf("%I64d\n", ans);
    m = read();
    while (m--)
    {
        x = read();
        for (int i = 1; i <= x; ++i)
            ans -= res[i][1] - res[i][0], swap(res[i][1], res[i][0]);
        printf("%I64d\n", ans);
    }
    return 0;
}