#include <cstdio>
#include <algorithm>

int m, x[4], y[4], p[1005], r[1005], c[10005];

int main() {
    for (int i = 1; i <= 3; i++) { scanf("%d%d", &x[i], &y[i]); p[x[i]] = y[i]; }
    std::sort(x + 1, x + 4); std::sort(y + 1, y + 4);
    for (int i = y[1]; i <= y[3]; i++) { r[++m] = x[2]; c[m] = i; }
    for (int i = x[1]; i < x[2]; i++) { r[++m] = i; c[m] = p[x[1]]; }
    for (int i = x[3]; i > x[2]; i--) { r[++m] = i; c[m] = p[x[3]]; }
    printf("%d\n", m);
    for (int i = 1; i <= m; i++) { printf("%d %d\n", r[i], c[i]); }
    return 0;
}