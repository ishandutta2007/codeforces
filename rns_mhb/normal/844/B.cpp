#include <bits/stdc++.h>
using namespace std;

#define N 55

typedef long long ll;
int n, m;
int a[N][N];
ll ans;
ll e[N];
int c[4];

int main() {
    e[0] = 1;
    for (int i = 1; i < N; i ++) e[i] = 2 * e[i-1];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i ++)
    for (int j = 0; j < m; j ++) scanf("%d", &a[i][j]);
    for (int i = 0; i < n; i ++) {
        c[0] = c[1] = 0;
        for (int j = 0; j < m; j ++) c[a[i][j]] ++;
        if (c[0]) ans += e[c[0]] - 1;
        if (c[1]) ans += e[c[1]] - 1;
    }
    for (int j = 0; j < m; j ++) {
        c[0] = c[1] = 0;
        for (int i = 0; i < n; i ++) c[a[i][j]] ++;
        if (c[0]) ans += e[c[0]] - 1;
        if (c[1]) ans += e[c[1]] - 1;
    }
    ans -= 1ll * n * m;
    printf("%I64d\n", ans);
    return 0;
}