#include <cstdio>

long long n, ans;

int main() {
    scanf("%lld", &n); n--;
    for (long long i = 1; i <= n; i *= 2) { ans += n / i * (i + 1 >> 1); }
    printf("%lld", ans);
    return 0;
}