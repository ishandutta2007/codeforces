#include <cstdio>
const int N = 1e5 + 34;
int a[N], b[N], n, ans, mn;
int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
        scanf("%d%d", a + i, b + i);
    mn = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] < b[mn])
            mn = i;
        ans += a[i] * b[mn];
    }
    printf("%d\n", ans);
}