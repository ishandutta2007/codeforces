#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int mod = 1e9 + 7;

inline int add(int x, int y) {
    return x + y >= mod ? x + y - mod : x + y;
}
inline int sub(int x, int y) {
    return x - y >= 0 ? x - y : x - y + mod;
}

const int N = 2e3 + 5;

int n, m, sr[N][N], sc[N][N], fr[N][N], fc[N][N];
char c[N][N];

int main() {
    n = read(); m = read();
    if (n == 1 && m == 1) { printf("1\n"); return 0; }
    for (int i = 1; i <= n; i++) { scanf("%s", c[i] + 1); }
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            sr[i][j] = sr[i][j + 1] + (c[i][j] == 'R');
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = n; i >= 1; i--) {
            sc[i][j] = sc[i + 1][j] + (c[i][j] == 'R');
        }
    }
    fr[1][1] = fc[1][1] = 1; fr[1][2] = fc[2][1] = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            fr[i][j] = add(fr[i][j], fr[i][j - 1]);
            fc[i][j] = add(fc[i][j], fc[i - 1][j]);
            if (i < n) {
                fc[i + 1][j] = add(fc[i + 1][j], fr[i][j]);
                fc[n + 1 - sc[i + 1][j]][j] = sub(fc[n + 1 - sc[i + 1][j]][j], fr[i][j]);
            }
            if (j < m) {
                fr[i][j + 1] = add(fr[i][j + 1], fc[i][j]);
                fr[i][m + 1 - sr[i][j + 1]] = sub(fr[i][m + 1 - sr[i][j + 1]], fc[i][j]);
            }
        }
    }
    printf("%d\n", add(fr[n][m], fc[n][m]));
    return 0;
}