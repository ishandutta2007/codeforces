#include <cstdio>

int n, m;

int main() {
    scanf("%d", &n);
    m = n / 2 + 1;
    printf("%d\n", m);
    for (int i = 1; i <= m; i++) { printf("%d %d\n", 1, i); }
    for (int i = m + 1; i <= n; i++) { printf("%d %d\n", i - m + 1, m); }
    return 0;
}