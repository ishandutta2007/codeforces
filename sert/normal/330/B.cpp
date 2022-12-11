#include <cstdio>
int n, m, v1, v2;
bool u[1234];
int main() {
    scanf("%d%d", &n, &m);
    printf("%d\n", n - 1);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &v1, &v2);
        u[v1] = u[v2] = true;
    }
    for (int i = 1; i <= n; i++)
    if (!u[i]) {
        for (int j = 1; j <= n; j++)
            if (i != j) printf("%d %d\n", i, j);
        return 0;
    }
}