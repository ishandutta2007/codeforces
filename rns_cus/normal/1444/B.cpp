#include <bits/stdc++.h>
using namespace std;

#define N 300100

int n, fac[N], ri[N], rfac[N], a[N];
const int mod = 998244353;

inline int C(int n, int m) {
    if (m > n) return 0;
    return 1ll * rfac[m] * rfac[n-m] % mod * fac[n] % mod;
}

int main() {
    fac[0] = rfac[0] = ri[1] = 1;
    for (int i = 1; i < N; i ++) {
        fac[i] = 1ll * i * fac[i-1] % mod;
        if (i > 1) ri[i] = 1ll * (mod - mod / i) * ri[mod%i] % mod;
        rfac[i] = 1ll * ri[i] * rfac[i-1] % mod;
    }
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i ++) scanf("%d", &a[i]);
    sort(a, a + 2 * n);
    long long sum = 0;
    for (int i = 0; i < n; i ++) sum -= a[i];
    for (int i = 0; i < n; i ++) sum += a[i+n];
    sum %= mod;
    sum = sum * C(2 * n, n) % mod;
    if (sum < 0) sum += mod;
    printf("%I64d\n", sum);

    return 0;
}