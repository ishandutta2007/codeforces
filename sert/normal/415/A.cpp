#include <cstdio>
int n, m, b[111];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++)
            if (b[j] <= i) {
                printf("%d ", b[j]);
                break;
            }
}