#include <bits/stdc++.h>
using namespace std;

#define N 1000100

int n, m, a, b, ri[N], pw[N];
const int mod = 1e9 + 7;


int main() {
    ri[1] = 1;
    for (int i = 2; i < N; i ++) ri[i] = 1ll * (mod - mod / i) * ri[mod%i] % mod;
    scanf("%d %d %d %d", &n, &m, &a, &b);
    int rlt = 0;
    pw[0] = 1, pw[1] = 1ll * n * m % mod;
    for (int i = 2; i < N; i ++) pw[i] = 1ll * pw[i-1] * pw[1] % mod;
    for (int i = 1, c = 2 * ri[n]; i <= m && i < n; i ++) {
        rlt = (rlt + 1ll * c * pw[n-i-1]) % mod;
        c = 1ll * c * (n - i - 1) % mod;
        c = 1ll * c * (m - i) % mod;
        c = 1ll * c * ri[i] % mod;
        c = 1ll * c * ri[i+1] % mod;
        c = 1ll * c * (i + 2) % mod;
    }
    printf("%d\n", rlt);
}