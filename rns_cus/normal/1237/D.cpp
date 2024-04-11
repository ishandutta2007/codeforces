#include <bits/stdc++.h>
using namespace std;

#define N 400200

int n, a[N], m, x[N], f[N], prv[N], c[N];

void upd(int x, int y) {
    for (; x; x -= x & -x) f[x] = max(f[x], y);
}

int que(int x) {
    int rlt = 0;
    for (; x <= m; x += x & -x) rlt = max(rlt, f[x]);
    return rlt;
}

const int inf = 1e9;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), a[2*n+i] = a[n+i] = a[i], x[++m] = a[i], x[++m] = 2 * a[i] + 1;
    sort(x + 1, x + m + 1);
    m = unique(x + 1, x + m + 1) - x - 1;
    for (int i = 1; i <= 3 * n; i ++) {
        prv[i] = que(lower_bound(x + 1, x + m + 1, 2 * a[i] + 1) - x);
        upd(lower_bound(x + 1, x + m + 1, a[i]) - x, i);
    }
    for (int i = 1; i <= 3 * n; i ++) c[i] = inf;
    for (int i = 1; i <= 3 * n; i ++) if (prv[i]) c[prv[i]] = min(c[prv[i]], i);
    for (int i = 3 * n - 1; i; i --) c[i] = min(c[i], c[i+1]);
    for (int i = 1; i <= n; i ++) {
        int r = c[i];
        if (r == inf) r = i - 1;
        printf("%d%c", r - i, " \n"[i==n]);
    }

    return 0;
}