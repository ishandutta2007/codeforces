#include <cstdio>
#include <algorithm>
long long a[100003], n, ans, x;
int main() {
    scanf("%I64d%I64d", &n, &x);
    for (int i = 0; i < n; i++) scanf("%I64d", &a[i]);
    std::sort(a, a + n);
    for (int i = 0; i < n; i++)
        ans += a[i] * std::max(1ll, x--);
    printf("%I64d", ans);
}