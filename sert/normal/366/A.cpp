#include <cstdio>
#include <iostream>
int n, a, b, c, d;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= 4; i++) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        a = std::min(a, b);
        b = std::min(c, d);
        if (a + b <= n) {
            printf("%d %d %d\n", i, a, n - a);
            return 0;
        }
    }
    printf("-1\n");
}