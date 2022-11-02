#include <bits/stdc++.h>
using namespace std;

#define N 200200
#define K 20

int n, m, q, p[N], a[N], cur[N], prv_p[N], prv[N][K], Prv[N], mx[N][K];

void build(int *a, int n) {
    for (int i = 1; i <= n; i ++) mx[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; j ++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i ++)
            mx[i][j] = max(mx[i][j - 1], mx[i + (1 << j - 1)][j - 1]);
    }
}
int query(int l, int r) {
    int d = 31 - __builtin_clz(r - l + 1);
    return max(mx[l][d], mx[r - (1 << d) + 1][d]);
}

int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i ++) scanf("%d", &p[i]);
    p[0] = p[n];
    for (int i = 1; i <= n; i ++) prv_p[p[i]] = p[i-1];
    for (int i = 1; i <= m; i ++) {
        scanf("%d", &a[i]);
        int k = cur[prv_p[a[i]]];
        prv[i][0] = k;
        cur[a[i]] = i;
    }
    for (int k = 1; k < K; k ++) {
        for (int i = 1; i <= m; i ++) prv[i][k] = prv[prv[i][k-1]][k-1];
    }
    for (int i = 1; i <= m; i ++) {
        int x = n - 1, j = i;
        for (int k = 0; k < K; k ++) if (x >> k & 1) j = prv[j][k];
        Prv[i] = j;
    }
    build(Prv, m);
    while (q --) {
        int l, r;
        scanf("%d %d", &l, &r);
        if (query(l, r) >= l) putchar('1');
        else putchar('0');
    }
}