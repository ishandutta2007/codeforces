#include <cstdio>
int n, k, ans[100], len, x, ok, v;
int main() {
    scanf("%d%d", &n, &v);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k);
        ok = 0;
        for (int i = 0; i < k; i++) {
            scanf("%d", &x);
            if (x < v) ok = 1;
        }
        if (ok) ans[len++] = i;
    }
    printf("%d\n", len);
    for (int i = 0; i < len; i++) printf("%d ", ans[i]);
}