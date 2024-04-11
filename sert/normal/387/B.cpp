#include <cstdio>
int n, m, a[4000], b[4000], uk, ans;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < m; i++) scanf("%d", &b[i]);
    uk = m - 1;
    for (int i = n - 1; i >= 0; i--)
        if (a[i] <= b[uk]) uk--;
        else ans++;
    printf("%d", ans);
}