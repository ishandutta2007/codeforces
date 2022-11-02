#include <bits/stdc++.h>
using namespace std;

#define N 2020

void chkmin(int &x, int y) {
    if (x > y) x = y;
}

void chkmax(int &x, int y) {
    if (x < y) x = y;
}
int n, m, x, a[N], b[N], dpa[N], dpb[N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for (int k = 1; k <= n; k ++) {
        int cur = 0;
        for (int i = 1; i <= k; i ++) cur += a[i];
        dpa[k] = cur;
        for (int i = 1; i <= n - k; i ++) {
            cur += a[k+i] - a[i];
            chkmin(dpa[k], cur);
        }
    }
    for (int i = 1; i <= m; i ++) scanf("%d", &b[i]);
    for (int k = 1; k <= m; k ++) {
        int cur = 0;
        for (int i = 1; i <= k; i ++) cur += b[i];
        dpb[k] = cur;
        for (int i = 1; i <= m - k; i ++) {
            cur += b[k+i] - b[i];
            chkmin(dpb[k], cur);
        }
    }
    scanf("%d", &x);
    int rlt = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (1ll * dpa[i] * dpb[j] <= x) chkmax(rlt, i * j);
        }
    }
    printf("%d\n", rlt);

    return 0;
}