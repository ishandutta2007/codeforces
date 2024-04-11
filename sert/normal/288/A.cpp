#include <cstdio>
int n, k;
int main() {
    scanf("%d%d", &n, &k);
    if (n == 1 && k == 1) {
        printf("a\n");
        return 0;
    }
    if (k == 1 || k > n) {
        printf("-1\n");
        return 0;
    }
    for (int i = 0; i < n - k + 2; i++)
        printf("%c", char('a' + i % 2));
    for (int i = n - k + 2; i < n; i++)
        printf("%c", char('a' + i - n + k));
}