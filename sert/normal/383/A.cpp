#include <cstdio>
long long n, a[234567], k[234567], ans;
int main() {
    scanf("%I64d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    k[n] = 0;
    for (int i = n - 1; i >= 0; i--) k[i] = k[i + 1] + !a[i];
    for (int i = 0; i < n; i++) ans += a[i] * k[i];
    printf("%I64d\n", ans);
}