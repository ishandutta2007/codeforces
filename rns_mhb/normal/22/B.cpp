#include <bits/stdc++.h>
using namespace std;

#define N 40

template <class T> bool chkmax(T &a, T b) { return a < b ? a = b, 1 : 0; }
int n, m, ans;
char s[N][N];

int main() {
    scanf("%d %d ", &n, &m);
    for (int i = 0; i < n; i ++) gets(s[i]);
    for (int xl = 0; xl < n; xl ++)
    for (int xr = xl; xr < n; xr ++)
    for (int yl = 0; yl < m; yl ++)
    for (int yr = yl; yr < m; yr ++) {
        bool fg = 0;
        for (int xm = xl; xm <= xr && !fg; xm ++)
        for (int ym = yl; ym <= yr && !fg; ym ++) if (s[xm][ym] == '1') fg = 1;
        if (!fg) chkmax(ans, 2 * (xr - xl + 1 + yr - yl + 1));
    }
    printf("%d\n", ans);
    return 0;
}