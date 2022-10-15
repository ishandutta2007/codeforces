#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e2 + 2;

int n, m;
char f[N][N];

struct Element {
    int a, b, c, d, e, f;
};

std::vector<Element> ans;

int main() {
    for (int T = read(); T; T--) {
        n = read(); m = read(); ans.clear();
        for (int i = 1; i <= n; i++) {
            scanf("%s", f[i] + 1);
        }
        if (n % 2 == 1) {
            for (int i = 1; i <= m; i++) {
                if (f[n][i] == '1') {
                    if (i == 1) {
                        f[n - 1][i] ^= 1;
                        f[n - 1][i + 1] ^= 1;
                        ans.push_back({n, i, n - 1, i, n - 1, i + 1});
                    } else {
                        f[n - 1][i] ^= 1;
                        f[n - 1][i - 1] ^= 1;
                        ans.push_back({n, i, n - 1, i, n - 1, i - 1});
                    }
                }
            }
            n--;
        }
        if (m % 2 == 1) {
            for (int i = 1; i <= n; i++) {
                if (f[i][m] == '1') {
                    if (i == 1) {
                        f[i][m - 1] ^= 1;
                        f[i + 1][m - 1] ^= 1;
                        ans.push_back({i, m, i, m - 1, i + 1, m - 1});
                    } else {
                        f[i][m - 1] ^= 1;
                        f[i - 1][m - 1] ^= 1;
                        ans.push_back({i, m, i, m - 1, i - 1, m - 1});
                    }
                }
            }
            m--;
        }
        for (int i = 1; i <= n / 2; i++) {
            for (int j = 1; j <= m / 2; j++) {
                bool a = false, b = false, c = false, d = false;
                if (f[i * 2 - 1][j * 2 - 1] == '1') { b ^= 1; c ^= 1; d ^= 1; }
                if (f[i * 2 - 1][j * 2 - 0] == '1') { a ^= 1; c ^= 1; d ^= 1; }
                if (f[i * 2 - 0][j * 2 - 1] == '1') { a ^= 1; b ^= 1; d ^= 1; }
                if (f[i * 2 - 0][j * 2 - 0] == '1') { a ^= 1; b ^= 1; c ^= 1; }
                if (a) { ans.push_back((Element) {i * 2 - 1, j * 2 - 0, i * 2 - 0, j * 2 - 1, i * 2 - 0, j * 2 - 0}); }
                if (b) { ans.push_back((Element) {i * 2 - 1, j * 2 - 1, i * 2 - 0, j * 2 - 1, i * 2 - 0, j * 2 - 0}); }
                if (c) { ans.push_back((Element) {i * 2 - 1, j * 2 - 1, i * 2 - 1, j * 2 - 0, i * 2 - 0, j * 2 - 0}); }
                if (d) { ans.push_back((Element) {i * 2 - 1, j * 2 - 1, i * 2 - 1, j * 2 - 0, i * 2 - 0, j * 2 - 1}); }
            }
        }
        printf("%d\n", ans.size());
        for (auto i : ans) {
            printf("%d %d %d %d %d %d\n", i.a, i.b, i.c, i.d, i.e, i.f);
            // f[i.a][i.b] ^= 1;
            // f[i.c][i.d] ^= 1;
            // f[i.e][i.f] ^= 1;
        }
        // for (int i = 1; i <= n; i++) {
        //     printf("%s\n", f[i] + 1);
        // }
    }
    return 0;
}