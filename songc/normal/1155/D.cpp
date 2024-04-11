#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N, M;
LL A[303030], ans;
LL D1[303030], D2[303030], D3[303030];

int main(){
    scanf("%d %d", &N, &M);
    for (int i=1; i<=N; i++) scanf("%lld", &A[i]);
    for (int i=1; i<=N; i++){
        D1[i] = max(D1[i-1], 0ll) + A[i];
        D2[i] = max(max(D1[i-1], D2[i-1]), 0ll) + A[i]*M;
        D3[i] = max(max(D3[i-1], D2[i-1]), 0ll) + A[i];
        ans = max(ans, D1[i]);
        ans = max(ans, D2[i]);
        ans = max(ans, D3[i]);
    }
    printf("%lld", ans);
    return 0;
}