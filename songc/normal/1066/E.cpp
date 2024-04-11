#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long LL;

int N, M;
LL ans;
LL twoPow[202020];
int A[202020], B[202020];

int main(){
    scanf("%d %d", &N, &M);
    for (int i=N-1; i>=0; i--) scanf("%1d", &A[i]);
    for (int i=M-1; i>=0; i--) scanf("%1d", &B[i]);
    twoPow[0] = 1;
    for (int i=1; i<N; i++) twoPow[i] = (twoPow[i-1] * 2) % MOD;
    for (int i=M-1; i>=0; i--) B[i] += B[i+1];
    for (int i=0; i<N; i++) if (A[i]) ans = (ans + ((B[i] * twoPow[i]) % MOD)) % MOD;
    printf("%I64d", ans);
    return 0;
}