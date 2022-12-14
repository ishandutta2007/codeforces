#include <bits/stdc++.h>
using namespace std;
#define mod 1000003
int F[mod], G[mod], f[mod];
int Po(int a,int b) {
    int rlt = 1;
    while(b) {
        if(b & 1) rlt = 1ll * rlt * a % mod;
        b >>= 1;
        a = 1ll * a * a % mod;
    }
    return rlt;
}

int main() {
    //freopen("D2.in", "r", stdin);
    int n, C;
    scanf("%d%d", &n, &C);
    F[0] = 1;
    int m = n * 2;
    for(int i = 1; i <= m; i ++) F[i] = 1ll * F[i - 1] * i % mod;
    G[m] = Po(F[m], mod - 2);
    for(int i = m - 1; i >= 0; i --) G[i] = 1ll * G[i + 1] * (i + 1) % mod;
    int ans = 0;
    for(int i = 1; i <= n && i <= C; i ++) {
        ans += 1ll * F[C] * G[i] % mod * G[C - i] % mod * F[n] % mod * G[i] % mod * G[n - i] % mod;
        if(ans >= mod) ans -= mod;
    }
    printf("%d\n", ans);
    return 0;
}