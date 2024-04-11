#include <bits/stdc++.h>

const int mod = 10007;

inline int add(int x, int y) {
    return x + y >= mod ? x + y - mod : x + y;
}

const int S = 402;

int s;

struct Matrix {
    int a[S][S];
};

Matrix operator *(const Matrix &f, const Matrix &g) {
    static Matrix res;
    for (int i = 0; i < s; i++) {
        for (int j = i; j < s; j++) {
            res.a[i][j] = 0;
            for (int k = i; k <= j; k++) {
                res.a[i][j] = (res.a[i][j] + 1ll * f.a[i][k] * g.a[k][j]) % mod;
            }
        }
    }
    return res;
}
Matrix operator ^(Matrix f, int x) {
    static Matrix res;
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            res.a[i][j] = i == j;
        }
    }
    for (; x; x >>= 1, f = f * f) {
        if (x & 1) { res = res * f; }
    }
    return res;
}

const int N = 205;

int n, m, q, l[N], r[N], dp[2][N][N][N];
char str[N];
Matrix f, g, h;

int main() {
    scanf("%s%d", str + 1, &m);
    n = strlen(str + 1); m += n;
    for (int i = 1; i <= n; i++) {
        dp[0][1][i][i] = 1;
    }
    f.a[0][0] = 26;
    for (int k = 1; k <= n + 1; k++) {
        l[k] = std::max(0, n - k * 2);
        r[k] = n + 1 - k * 2;
        if (l[k] > r[k]) { q = k; break; }
        f.a[k][k] = 25;
        f.a[k - 1][k] = 1;
        for (int len = 2; len <= n; len++) {
            for (int i = 1; i <= n + 1 - len; i++) {
                int j = i + len - 1;
                if (str[i] == str[j]) {
                    dp[0][k][i][j] = dp[0][k - 1][i + 1][j - 1];
                    if (k == 1 && len == 2) {
                        dp[1][k][i][j] = 1;
                    } else {
                        dp[1][k][i][j] = dp[1][k - 1][i + 1][j - 1];
                    }
                } else {
                    dp[0][k][i][j] = add(dp[0][k][i + 1][j], dp[0][k][i][j - 1]);
                    dp[1][k][i][j] = add(dp[1][k][i + 1][j], dp[1][k][i][j - 1]);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (i < n - 1) { f.a[q + i][q + i] = 24; }
        if (i > 0) { f.a[q + i - 1][q + i] = 1; }
    }
    g = f;
    for (int i = 1; i < q; i++) {
        f.a[i][q + n - 1 - r[i]] = dp[0][i][1][n];
        if (l[i] == r[i]) { continue; }
        g.a[i][q + n - 1 - l[i]] = dp[1][i][1][n];
    }
    s = q + n;
    f = f ^ ((m + 3) / 2);
    h = g; h.a[0][1] = 0;
    g = g ^ (m / 2 + 1);
    if (m & 1) { g = h * g; }
    printf("%d\n", add(f.a[0][s - 1], g.a[0][s - 1]));
    return 0;
}