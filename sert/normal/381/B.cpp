#include <cstdio>
int n, t, mx, a[10000], len, ans[10000];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        if (t > mx) mx = t;
        a[t]++;
    }
    for (int i = 0; i <= mx; i++)
    if (a[i]) {
        ans[len++] = i;
        a[i]--;
    }
    for (int i = mx - 1; i >= 0; i--)
        if (a[i]) ans[len++] = i;
    printf("%d\n", len);
    for (int i = 0; i < len; i++)
        printf("%d ", ans[i]);
}