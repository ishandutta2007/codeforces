#include <cstdio>
int n, k, q = 100011000;
int main() {
    scanf("%d%d", &n, &k);
    if (n == 1 && k == 0) {printf("34\n"); return 0;}
    if ((n < 2 && k != 0) || k < n / 2) {printf("-1"); return 0;}
    printf("%d %d", 2 * (k - n / 2 + 1), k - n / 2 + 1);
    for (int i = 2; i < n; i++) printf(" %d", q++);
}