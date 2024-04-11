#include <cstdio>
int n, k, a[100002], b[100002], m, x;
bool u[100002];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = n - 1; i >= 0; i--) {
        b[i] = b[i + 1] + int(!u[a[i]]);
        u[a[i]] = true;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        printf("%d\n", b[x - 1]);
    }
}