#include <bits/stdc++.h>

int mod;

inline int add(int x, int y) {
    return x + y >= mod ? x + y - mod : x + y;
}
inline int sub(int x, int y) {
    return x - y >= 0 ? x - y : x - y + mod;
}
inline int power(int x, int y) {
    int res = 1;
    for (; y; y >>= 1, x = 1ll * x * x % mod) {
        if (y & 1) { res = 1ll * res * x % mod; }
    }
    return res;
}

const int N = 205;

int n, m, num, ans, a[N][N], id[N][N];
char str[N][N];

void dfs(int i, int j, int _i, int _j) {
    if (id[i][j] > 0) { printf("0\n"); exit(0); }
    id[i][j] = num;
    if (i > 0 && j > 0 && str[i - 1][j - 1] == '\\') {
        if (i - 1 != _i || j - 1 != _j) { dfs(i - 1, j - 1, i, j); }
    }
    if (i > 0 && j < m && str[i - 1][j] == '/') {
        if (i - 1 != _i || j + 1 != _j) { dfs(i - 1, j + 1, i, j); }
    }
    if (i < n && j > 0 && str[i][j - 1] == '/') {
        if (i + 1 != _i || j - 1 != _j) { dfs(i + 1, j - 1, i, j); }
    }
    if (i < n && j < m && str[i][j] == '\\') {
        if (i + 1 != _i || j + 1 != _j) { dfs(i + 1, j + 1, i, j); }
    }
}

int getdet() {
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            a[i][j] = (a[i][j] % mod + mod) % mod;
        }
    }
    int res = 1;
    for (int r = 0; r < num; r++) {
        if (a[r][r] == 0) {
            res = sub(0, res);
            for (int i = r + 1; i < num; i++) {
                if (a[i][r] != 0) {
                    std::swap(a[r], a[i]);
                    break;
                }
            }
        }
        if (a[r][r] == 0) { return 0; }
        res = 1ll * res * a[r][r] % mod;
        int inv = power(a[r][r], mod - 2);
        for (int i = r + 1; i < num; i++) {
            int k = 1ll * a[i][r] * inv % mod;
            for (int j = r; j < num; j++) {
                a[i][j] = sub(a[i][j], 1ll * k * a[r][j] % mod);
            }
        }
    }
    return res;
}

int main() {
    scanf("%d%d%d", &n, &m, &mod);
    for (int i = 0; i < n; i++) {
        scanf("%s", str[i]);
    }
    for (int z = 0; z < 2; z++) {
        num = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if ((i + j) % 2 != z) { continue; }
                if (id[i][j] > 0) { continue; }
                num++; dfs(i, j, -1, -1);
            }
        }
        if (num > 201) { continue; }
        for (int i = 0; i < num; i++) {
            for (int j = 0; j < num; j++) {
                a[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (str[i][j] != '*') { continue; }
                int u, v;
                if ((i + j) % 2 == z) {
                    u = id[i][j] - 1;
                    v = id[i + 1][j + 1] - 1;
                } else {
                    u = id[i][j + 1] - 1;
                    v = id[i + 1][j] - 1;
                }
                a[u][u]++; a[v][v]++;
                a[u][v]--; a[v][u]--;
            }
        }
        num--; ans = add(ans, getdet());
    }
    printf("%d\n", ans);
    return 0;
}