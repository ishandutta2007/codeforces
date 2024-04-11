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

const int maxN = 105;

int n, m, f[maxN * maxN];

struct Exam { int id, l, r, t; } e[maxN];
bool cmp(Exam x, Exam y) { return x.r < y.r; }

bool solve() {
    for (int i = 1; i <= m; i++) { f[e[i].r] = m + 1; }
    for (int i = 1, p; i <= m; i++) {
        p = e[i].l;
        for (int j = 1; j <= e[i].t; ) {
            if (p >= e[i].r) { return false; }
            if (!f[p]) { f[p] = e[i].id; j++; } p++;
        }
    }
    return true;
}

int main() {
    n = read(), m = read();
    for (int i = 1; i <= m; i++) { e[i].id = i, e[i].l = read(), e[i].r = read(), e[i].t = read(); }
    std::sort(e + 1, e + m + 1, cmp);
    if (solve()) { for (int i = 1; i <= n; i++) { printf("%d ", f[i]); } } else { printf("-1\n"); }
    return 0;
}

// a/3fs;';3';'r.f'as;d'as;df';'fd'