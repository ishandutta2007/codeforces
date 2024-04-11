#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

LL N, K;
LL ans = 1;
LL D[100][10101];
LL P[10101];

LL Pow(LL a, LL b){
    if (b <= 0) return 1;
    if (b == 1) return a;
    LL c = Pow(a, b/2);
    if (b & 1) return (c*c%MOD) * a % MOD;
    return c * c % MOD;
}

LL f(LL x, int d){
    for (int i=0; i<=d; i++) D[i][0] = Pow(x, i);
    for (int i=1; i<=K; i++){
        LL sum = 0;
        for (int j=0; j<=d; j++){
            sum = (sum + D[j][i-1]) % MOD;
            D[j][i] = sum * P[j+1] % MOD;
        }
    }
    return D[d][K];
}

int main(){
    scanf("%lld %lld", &N, &K);
    for (int i=1; i<=60; i++) P[i] = Pow(i, MOD-2);
    for (LL i=2; i*i <= N && N > 1; i++){
        if (N % i) continue;
        int d = 0;
        while (N % i == 0){
            N /= i;
            d++;
        }
        ans = ans * f(i, d) % MOD;
    }
    if (N > 1) ans = ans * f(N, 1) % MOD;
    printf("%lld\n", ans);
    return 0;
}