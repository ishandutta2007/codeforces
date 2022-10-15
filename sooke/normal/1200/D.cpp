#include <bits/stdc++.h>

inline char read() {
    char c; for (c = getchar(); !isalpha(c); c = getchar()); return c;
}

const int N = 2e3 + 5;

int n, m, ans, f[N][N], ar1[N][N], ac1[N][N], ar2[N][N], ac2[N][N], ar[N][N], ac[N][N];
int allr[N], allc[N];
char c[N][N];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            c[i][j] = read();
        }
    }
    for (int i = 1; i <= n; i++) {
        ar1[i][0] = 1;
        for (int j = 1; j <= n; j++) {
            ar1[i][j] = ar1[i][j - 1] && (c[i][j] == 'W');
        }
        allr[i] = ar1[i][n];
        ar2[i][n + 1] = 1;
        for (int j = n; j >= 1; j--) {
            ar2[i][j] = ar2[i][j + 1] && (c[i][j] == 'W');
        }
    }
    for (int j = 1; j <= n; j++) {
        ac1[0][j] = 1;
        for (int i = 1; i <= n; i++) {
            ac1[i][j] = ac1[i - 1][j] && (c[i][j] == 'W');
        }
        allc[j] = ac1[n][j];
        ac2[n + 1][j] = 1;
        for (int i = n; i >= 1; i--) {
            ac2[i][j] = ac2[i + 1][j] && (c[i][j] == 'W');
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j + m <= n + 1) { ar[i][j] = ar1[i][j - 1] && ar2[i][j + m]; }
            if (i + m <= n + 1) { ac[i][j] = ac1[i - 1][j] && ac2[i + m][j]; }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ar[i][j] += ar[i - 1][j];
            ac[i][j] += ac[i][j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        allr[i] += allr[i - 1];
        allc[i] += allc[i - 1];
    }
    for (int i = 1; i <= n - m + 1; i++) {
        for (int j = 1; j <= n - m + 1; j++) {
            f[i][j] += ac[i][j + m - 1] - ac[i][j - 1];
            f[i][j] += ar[i + m - 1][j] - ar[i - 1][j];
            f[i][j] += allr[n] - (allr[i + m - 1] - allr[i - 1]);
            f[i][j] += allc[n] - (allc[j + m - 1] - allc[j - 1]);
        }
    }
    for (int i = 1; i <= n - m + 1; i++) {
        for (int j = 1; j <= n - m + 1; j++) {
            ans = std::max(ans, f[i][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}