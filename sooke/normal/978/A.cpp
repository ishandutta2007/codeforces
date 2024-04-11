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

const int maxN = 1005;

int n, m, a[maxN], cnt[maxN];

int main() {
    n = read();
    for (int i = 1; i <= n; i++) { a[i] = read(); }
    for (int i = n; i; i--) { if (cnt[a[i]]) { a[i] = -1; } else { m++; } cnt[a[i]]++; }
    printf("%d\n", m);
    for (int i = 1; i <= n; i++) { if (a[i] != -1) { printf("%d ", a[i]); } }
    return 0;
}

////./././..././././././././././.