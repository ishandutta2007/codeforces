#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 3e6 + 5;

int n, ans, a[N], f[N];

void dfs(int i, int x) {
    if (f[x] >= 2) { return; }
    if (i > 20) {
        f[x]++; return;
    } dfs(i + 1, x);
    if (1 << i & x) { dfs(i + 1, 1 << i ^ x); }
}

int main() {
    n = read();
    for (int i = 0; i < n; i++) { a[i] = read(); }
    for (int i = n - 1; i >= 0; i--) {
        int x = 0;
        for (int j = 20; j >= 0; j--) {
            if ((1 << j & a[i]) == 0 && f[1 << j | x] >= 2) { x |= 1 << j; }
        }
        if (i <= n - 3) { ans = std::max(ans, a[i] | x); }
        dfs(0, a[i]);
    } printf("%d\n", ans);
    return 0;
} ////