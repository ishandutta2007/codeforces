#include <bits/stdc++.h>
using namespace std;

#define N 1010

bitset <N> b[N], ans, T;

int m, n, B[N], fac[N], rfac[N], ri[N];
const int mod = 1e9 + 7;

inline int C(int n, int m) {
    return 1ll * rfac[m] * rfac[n-m] % mod * fac[n] % mod;
}

int main() {
    fac[0] = rfac[0] = ri[1] = 1;
    for (int i = 1; i < N; i ++) {
        fac[i] = 1ll * i * fac[i-1] % mod;
        if (i > 1) ri[i] = 1ll * (mod - mod / i) * ri[mod%i] % mod;
        rfac[i] = 1ll * ri[i] * rfac[i-1] % mod;
    }
    B[0] = 1;
    for (int i = 1; i < N; i ++) for (int j = 0; j < i; j ++) B[i] = (B[i] + 1ll * C(i - 1, j) * B[j]) % mod;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i ++) cin >> b[i];
    for (int i = 0; i < m; i ++) T[i] = 1;
    int rlt = 1;
    for (int i = 0; i < m; i ++) {
        if (ans[i]) continue;
        bitset <N> x = T;
        for (int j = 0; j < n; j ++) if (b[j][i]) x &= b[j]; else x &= (~b[j] & T);
        rlt = 1ll * rlt * B[x.count()] % mod;
        ans |= x;
    }
    printf("%d\n", rlt);

    return 0;
}