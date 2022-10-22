#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N, K;
LL A, B;
int H[101010];

LL f(LL s, LL e){
    int r = upper_bound(H+1, H+K+1, e) - H;
    int l = lower_bound(H+1, H+K+1, s) - H;
    if (l >= r) return A;
    if (s == e){
        if (l >= r) return A;
        return B * (r-l);
    }
    LL ret1 = f(s, (s+e)/2) + f((s+e)/2 + 1, e);
    LL ret2;
    if (l >= r) ret2 = A;
    else ret2 =  B * (r-l) * (e-s+1);
    return min(ret1, ret2);
}

int main(){
    scanf("%d %d %lld %lld", &N, &K, &A, &B);
    for (int i=1; i<=K; i++) scanf("%d", &H[i]);
    sort(H+1, H+K+1);
    printf("%lld", f(1, (1<<N)));
    return 0;
}