#include <bits/stdc++.h>
using namespace std;

#define N 100100
#define M 11

int n, m, a[M][N], id[M][N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i ++)
        for (int j = 1; j <= n; j ++)
            scanf("%d", &a[i][j]), id[i][a[i][j]] = j;
    long long rlt = 0;
    for (int i = 1, j; i <= n; ) {
        for (j = i + 1; j <= n; j ++) {
            bool fg = 0;
            for (int i = 1; i < m; i ++) {
                if (id[i][a[0][j]] != id[i][a[0][j-1]] + 1) {
                    fg = 1; break;
                }
            }
            if (fg) break;
        }
        rlt += 1ll * (j - i) * (j - i + 1) / 2;
        i = j;
    }
    printf("%lld\n", rlt);
}