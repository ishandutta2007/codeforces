#include <cstdio>
#include <algorithm>
int n, t, x, k, len, a[10000], mn, mx;
int main() {
    a[len++] = 0;
    scanf("%d%d", &t, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        for (int j = 0; j < 3 - k; j++) {
            scanf("%d", &x);
            a[len++] = x;
        }
    }
    std::sort(a, a + len);
    a[len] = t;
    for (int i = 0; i < len; i++) {
        mx += a[i + 1] - a[i] - 1;
        mn += (a[i + 1] - a[i]) / 2;
    }
    printf("%d %d\n", mn, mx);
}