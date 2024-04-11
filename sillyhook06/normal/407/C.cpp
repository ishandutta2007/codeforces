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
const int N = 101005, M = 105, P = 1000000007;
int n, m, Q , a[N] , f[N][M], c[N][M];
void add(int &x, int y)
{
    x += y;
    if (x >= P) x -= P;
    if (x < 0) x += P;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    n = read(), Q = read(), m = 101;
    rep(i, n) a[i] = read();
    rep(i, n + m) rep(j, min(i + 1, m)) c[i][j] = i && j ? (c[i - 1][j] + c[i - 1][j - 1]) % P : 1;
    while (Q--)
    {
        int l = read() - 1, r = read(), k = read();
        rep(i, k + 1) add(f[l + i][i], c[k][i]), add(f[r][i], -c[k + r - l - 1 - i][k - i]); //,printf("%d\n",-c[k+r-l-1-i][k-i]);
    }
    rep(i, n)
    {
        for (int j = m; j; --j) add(f[i][j - 1], f[i][j]);
        add(a[i], f[i][0]);
        rep(j, m) add(f[i + 1][j], f[i][j]);
    }
    rep(i, n) printf("%d ", a[i]);
    return 0;
}