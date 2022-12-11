#include <cstdio>
#include <iostream>
int m, n, a[567][567], b[123956], len, x, mn = 1234567890, t;
bool u[124567];
int main() {
    //freopen("a.in", "r", stdin);
    for (long long i = 2; i < 123456; i++)
        if (!u[i]) {
            for (long long j = i * i; j < 123456; j += i)
                u[j] = true;
            b[len++] = i;
        }
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
        scanf("%d", &x);
        a[i][j] = *std::lower_bound(b, b + len, x) - x;
    }
    for (int i = 0; i < n; i++) {
        t = 0;
        for (int j = 0; j < m; j++) t += a[i][j];
        if (t < mn) mn = t;
    }
    for (int i = 0; i < m; i++) {
        t = 0;
        for (int j = 0; j < n; j++) t += a[j][i];
        if (t < mn) mn = t;
    }
    printf("%d\n", mn);
}