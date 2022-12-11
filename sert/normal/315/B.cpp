#include <cstdio>
long long n, m, k, x, t, a[123445], ans;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    while (m--) {
        scanf("%d%d", &t, &x);
        if (t == 1) {scanf("%d", &k); a[x - 1] = k - ans;}
        if (t == 2) ans += x;
        if (t == 3) printf("%d\n", a[x - 1] + ans);
    }
}