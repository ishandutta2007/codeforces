#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int Q;
LL N, A, B, ans;

int main(){
    scanf("%d", &Q);
    while (Q--){
        scanf("%lld %lld %lld", &N, &A, &B);
        ans = 0;
        if (N&1) ans += A, N--;
        if (2*A <= B) ans += N*A;
        else ans += N/2*B;
        printf("%lld\n", ans);
    }
    return 0;
}