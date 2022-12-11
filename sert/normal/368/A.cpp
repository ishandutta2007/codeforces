#include <cstdio>
#include <cstring>
int n, d, m, a[2014], ans, t;
bool u[2014];
int main() {
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    a[n] = 2014;
    for (int i = 0; i < m; i++) {
        t = n;
        for (int j = 0; j < n; j++)
            if (!u[j] && a[j] < a[t]) t = j;
        ans += (t == n ? -d : a[t]);
        u[t] = true;
    }
    printf("%d\n", ans);
}