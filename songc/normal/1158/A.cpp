#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N, M;
LL ans;
int A[101010];
int B[101010];

int main(){
    scanf("%d %d", &N, &M);
    for (int i=1; i<=N; i++) scanf("%d", &A[i]);
    for (int i=1; i<=M; i++) scanf("%d", &B[i]);
    sort(A+1, A+N+1);
    sort(B+1, B+M+1);
    if (B[1] < A[N]){
        printf("-1");
        return 0;
    }
    for (int i=1; i<=N; i++) ans += (LL)M * A[i];
    for (int i=1; i<=M; i++) ans += B[i] - A[N];
    if (B[1] != A[N]) ans += A[N] - A[N-1];
    printf("%lld\n", ans);
    return 0;
}