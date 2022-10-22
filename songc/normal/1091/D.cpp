#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long LL;

int N;
LL fac[1010101];
LL ans;

int main(){
    scanf("%d", &N);
    fac[1] = 1;
    for (int i=2; i<=N; i++) fac[i] = fac[i-1] * i % MOD;
    ans = fac[N];
    LL k = N;
    for (int i=1; i<N-1; i++){
        ans += (fac[N-i] - 1) * k % MOD;
        ans %= MOD;
        k = k * (N-i) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}