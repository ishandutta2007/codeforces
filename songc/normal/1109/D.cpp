#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;

LL N, M, ans;
LL fac[2020202];
LL invfac[2020202];

LL Pow(LL X, LL Y){
    if (Y <= 0) return 1;
    LL Z = Pow(X, Y/2);
    if (Y&1) return Z * Z % MOD * X % MOD;
    return Z * Z % MOD;
}

LL inv(LL X){
    return Pow(X, MOD-2);
}

LL Comb(LL X, LL Y){
    if (Y <= 0) return 1;
    if (Y > X) return 0;
    return fac[X] * invfac[Y] % MOD * invfac[X-Y] % MOD;
}

int main(){
    scanf("%lld %lld %*d %*d", &N, &M);
    fac[0] = 1;
    for (int i=1; i<=2020000; i++) fac[i] = fac[i-1] * i % MOD;
    invfac[2020000] = inv(fac[2020000]);
    for (int i=2019999; i>=0; i--) invfac[i] = invfac[i+1] * (i+1) % MOD;
    for (int i=2; i<N; i++){
        LL k;
        if (M < i-1) break;
        k = i * Pow(N, N-i-1) % MOD;
        k = k * Comb(N-2, i-2) % MOD;
        k = k * fac[i-2] % MOD;
        k = k * Comb(M-1, M-i+1) % MOD;
        k = k * Pow(M, N-i) % MOD;
        ans = (ans + k) % MOD;
    }
    if (M >= N-1) ans = (ans + Comb(M-1, M-N+1) * fac[N-2]) % MOD;
    printf("%lld\n", ans);
    return 0;
}