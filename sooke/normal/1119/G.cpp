#include <cstdio>
#include <algorithm>

const int N = 1000005;

int n, m, ans, a[N], b[N];

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]); ans += b[i];
        a[i] = (a[i - 1] + b[i]) % m;
    }
    a[n] = m; std::sort(a + 1, a + n + 1);
    printf("%d\n", ans = (ans - 1) / m + 1);
    for (int i = n; i; i--) { a[i] -= a[i - 1]; }
    for (int i = 1; i <= n; i++) { printf("%d ", a[i]); } printf("\n");
    for (; ans; ans--) {
        for (int i = 1, j = 1; i <= n; i++) {
            while (j < n && b[j] <= 0) { j++; }
            printf("%d ", j); b[j] -= a[i];
        }
        printf("\n");
    }
    return 0;
} //