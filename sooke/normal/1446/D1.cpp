#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 2e5 + 5;

int n, max, ans, a[N], c[N], f[N], g[N * 2];

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read(); c[a[i]]++;
    }
    max = std::max_element(c + 1, c + n + 1) - c;
    for (int x = 1; x <= 100; x++) {
        if (x == max) { continue; }
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        for (int i = 1; i <= n; i++) {
            f[i] = f[i - 1];
            if (a[i] == x) { f[i]++; }
            if (a[i] == max) { f[i]--; }
        }
        for (int i = n; i >= 1; i--) {
            ans = std::max(ans, g[f[i - 1] + n] - i + 1);
            ans = std::max(ans, g[f[i - 1] + n + 1] - i + 1);
            g[f[i] + n] = std::max(g[f[i] + n], g[f[i] + n + 1]);
            g[f[i] + n] = std::max(g[f[i] + n], i);
        }
    }
    printf("%d\n", ans);
    return 0;
}