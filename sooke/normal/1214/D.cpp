#include <bits/stdc++.h>

inline int read() {
    char c; for (c = getchar(); c != '.' && c != '#'; c = getchar()); return c;
}

int n, m, mod;
std::vector<std::vector<char>> a;
std::vector<std::vector<long long>> f1, g1, f2, g2, f3, g3;

bool check() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) { continue; }
            if (i == n && j == m) { continue; }
            if (f1[i][j] * g1[i][j] % 998244353 != f1[n][m]) { continue; }
            if (f2[i][j] * g2[i][j] % 998244853 != f2[n][m]) { continue; }
            if (f3[i][j] * g3[i][j] % mod != f3[n][m]) { continue; }
            return true;
        }
    } return false;
}

int main() {
    srand(time(0)); mod = ((long long) (rand() << 15) & 32767) ^ rand();
    scanf("%d%d", &n, &m);
    a.resize(n + 2);
    f1.resize(n + 2);
    g1.resize(n + 2);
    f2.resize(n + 2);
    g2.resize(n + 2);
    f3.resize(n + 2);
    g3.resize(n + 2);
    for (int i = 0; i <= n + 1; i++) {
        a[i].resize(m + 2);
        f1[i].resize(m + 2);
        g1[i].resize(m + 2);
        f2[i].resize(m + 2);
        g2[i].resize(m + 2);
        f3[i].resize(m + 2);
        g3[i].resize(m + 2);
    }
    f1[1][1] = 1;
    g1[n][m] = 1;
    f2[1][1] = 1;
    g2[n][m] = 1;
    f3[1][1] = 1;
    g3[n][m] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) { a[i][j] = read(); }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if ((i != 1 || j != 1) && a[i][j] == '.') {
                f1[i][j] = (f1[i - 1][j] + f1[i][j - 1]) % 998244353;
                f2[i][j] = (f2[i - 1][j] + f2[i][j - 1]) % 998244853;
                f3[i][j] = (f3[i - 1][j] + f3[i][j - 1]) % mod;
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            if ((i != n || j != m) && a[i][j] == '.') {
                g1[i][j] = (g1[i + 1][j] + g1[i][j + 1]) % 998244353;
                g2[i][j] = (g2[i + 1][j] + g2[i][j + 1]) % 998244853;
                g3[i][j] = (g3[i + 1][j] + g3[i][j + 1]) % mod;
            }
        }
    }
    if (f1[n][m] == 0 && f2[n][m] == 0 && f3[n][m] == 0 && g1[1][1] == 0 && g2[1][1] == 0 && g3[1][1] == 0) {
        printf("0\n"); return 0;
    }
    printf("%d\n", check() ? 1 : 2);
    return 0;
} //