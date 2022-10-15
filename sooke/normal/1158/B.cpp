#include <cstdio>

int n, m, k;

int main() {
    scanf("%d%d", &n, &k);
    m = (n - k) / 2 + 1;
    for (int i = 1; i <= n; i++) { putchar((i % m == 0) | 48); }
    putchar('\n');
    return 0;
} //