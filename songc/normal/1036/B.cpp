#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int Q;
LL X, Y, K, ans;

int main(){
    scanf("%d", &Q);
    for (int q=0; q<Q; q++){
        scanf("%I64d %I64d %I64d", &X, &Y, &K);
        if (X > Y) swap(X, Y);
        if (X > K){
            printf("-1\n");
            continue;
        }
        Y -= X;
        ans = X, K -= X;
        if (Y > K){
            printf("-1\n");
            continue;
        }
        if (Y & 1) K--;
        else if (K & 1) K -= 2;
        printf("%I64d\n", ans + K);
    }
    return 0;
}