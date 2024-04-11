#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

inline int read() {
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const int maxN = 100005;

int n, fa[maxN], f[maxN], cnt[maxN], ans[maxN];
bool used[maxN];

int main() {
    n = read();
    for (int i = 2; i <= n; i++) { fa[i] = read(); used[fa[i]] = true; }
    for (int i = n; i >= 1; i--) {
        if (!used[i]) { f[i] = 1; } cnt[f[i]]++;
        f[fa[i]] += f[i];
    }
    for (int i = 1, j = 1, k; i <= n; i++) {
        for (k = 1; k <= cnt[i]; j++, k++) { ans[j] = i; }
    }
    for (int i = 1; i <= n; i++) { printf("%d ", ans[i]); }
    return 0;
} //