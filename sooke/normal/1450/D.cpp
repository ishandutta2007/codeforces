#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, a[N], b[N];

bool check() {
    for (int i = 1; i <= n; i++) {
        if (b[i] != i) { return false; }
    }
    return true;
}

void dfs(int d, int l, int r, int &min, bool ok) {
    if (d == 1) { min = a[l]; return; }
    bool _ok = ok;
    if (!_ok || (a[l] == n + 1 - d) == (a[r] == n + 1 - d)) {
        dfs(d - 1, l + 1, r, min, false);
        min = std::min(min, a[l]);
    } else if (a[l] == n + 1 - d) {
        dfs(d - 1, l + 1, r, min, _ok);
        min = std::min(min, a[l]);
    } else {
        dfs(d - 1, l, r - 1, min, _ok);
        min = std::min(min, a[r]);
    }
    printf("%d", min == n + 1 - d && ok);
}

int main() {
    for (int T = read(); T; T--) {
        n = read();
        for (int i = 1; i <= n; i++) {
            a[i] = b[i] = read();
        }
        std::sort(b + 1, b + n + 1);
        printf("%d", check());
        int min = 1e9;
        dfs(n, 1, n, min, true);
        printf("\n");
    }
    return 0;
}