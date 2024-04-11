#include <cstdio>
long long n, ans = 1;
int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    scanf("%I64d", &n);
    for (long long i = 2; i * i <= n; i++) 
        if (n % i == 0) {
            ans *= i;
            while (n % i == 0)
                n /= i;
        }
    printf("%I64d\n", n * ans);
}