#include <cstdio>
bool u1[100], u2[100];
int x, y, n;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n * n; i++) {
        scanf("%d%d", &x, &y);
        if (!u1[x] && !u2[y]) {
            printf("%d ", i);
            u1[x] = u2[y] = true;
        }
    }
}