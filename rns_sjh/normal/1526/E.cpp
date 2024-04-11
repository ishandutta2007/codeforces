#include<bits/stdc++.h>
using namespace std;

#define N 400010
const int mod = 998244353;

int n, k, a[N], b[N];

int fac[N], inv[N];

int inverse(int a, int b = mod - 2) {
    int ans = 1;
    for( ; b; b >>= 1, a = 1ll * a * a % mod) if(b & 1) ans = 1ll * a * ans % mod;
    return ans;
}

void build() {
    fac[0] = 1;
    for(int i = 1; i < N; i ++) fac[i] = 1ll * fac[i - 1] * i % mod;
    inv[N - 1] = inverse(fac[N - 1]);
    for(int i = N - 2; i >= 0; i --) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
}

int com(int a, int b) {
    if(b > a || b < 0) return 0;
    return 1ll * fac[a] * inv[b] % mod * inv[a - b] % mod;
}

int main() {
    build();
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i ++) {
        scanf("%d", a + i);
        b[a[i]] = i;
    }
    b[n] = -1;
    for(int i = 0; i < n - 1; i ++) k += b[a[i] + 1] < b[a[i + 1] + 1];
    printf("%d\n", com(k, n));
}