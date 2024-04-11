#include<stdio.h>
using namespace std;

const int N = 4e6 + 5, P = 1e9 + 7;
int n, q;
long long fac[N], inv[N], f[N], g[N], ans[N];

long long qpow(long long x, int y) {
    long long res = 1;
    while(y) res = res * ((y & 1)? x : 1) % P, x = x * x % P, y >>= 1;
    return res;
}

void init(int n) {
    fac[0] = 1;
    for(int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % P;
    inv[n] = qpow(fac[n], P - 2);
    for(int i = n; i >= 1; i--) inv[i - 1] = inv[i] * i % P;
}

int C(int n, int m) { return n >= m? fac[n] * inv[m] % P * inv[n - m] % P : 0; }

signed main() {
    scanf("%d%d", &n, &q);
    init(3 * n + 5);
    for(int i = 0; i <= 3 * n + 3; i++) f[i] = C(3 * n + 3, i);
    for(int i = 0; i <= 3; i++) g[i] = C(3, i), f[i] = (f[i] - g[i]) % P;
    g[0]--;
    int fn = 3 * n + 3, fm = 3;
    int invB = qpow(g[fm], P - 2);
    for(int i = fn; i >= fm; i--) {
        int res = f[i] * invB % P;
        ans[i - fm] = res;
        for(int j = fm; j >= 0; j--) f[i - fm + j] = (f[i - fm + j] - g[j] * res % P) % P;
    }
    for(int i = 0; i <= 3 * n; i++) ans[i] = (ans[i] + P) % P;
    while(q--) {
        int x;
        scanf("%d", &x);
        printf("%lld\n", ans[x]);
    }
    return 0;
}

/*
1000000 1
1
*/