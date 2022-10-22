#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL N, K;
LL ans=(1ll << 60);

int main(){
    scanf("%lld %lld", &N, &K);
    for (LL i=2; i*i<=K; i++){
        if (K % i) continue;
        int d = 0;
        while (K%i == 0){
            d++;
            K /= i;
        }
        LL e=0;
        for (LL X=N; X; X/=i) e += X/i;
        ans = min(ans, e / d);
    }
    if (K > 1){
        LL e=0;
        for (LL X=N; X; X/=K) e += X/K;
        ans = min(ans, e);
    }
    printf("%lld", ans);
    return 0;
}