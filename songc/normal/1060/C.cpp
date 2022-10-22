#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N, M;
LL A[2020], B[2020], X;
LL K[2020], ans;

int main(){
    scanf("%d %d", &N, &M);
    for (int i=1; i<=N; i++) {
        scanf("%I64d", &A[i]);
        A[i] += A[i-1];
    }
    for (int i=1; i<=M; i++) {
        scanf("%I64d", &B[i]);
        B[i] += B[i-1];
    }
    scanf("%I64d", &X);
    for (int i=1; i<=M; i++) {
        K[i] = 123456789012345;
        for (int j=0; j+i<=M; j++) K[i] = min(K[i], B[j+i]-B[j]);
    }
    for (int i=1; i<=N; i++){
        for (int j=0; j+i<=N; j++){
            ans = max(ans, (LL)(upper_bound(K+1, K+M+1, X / (A[j+i]-A[j])) - K - 1) * i);
        }
    }
    printf("%I64d\n", ans);
    return 0;
}