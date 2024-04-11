#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N;
LL A[505050];
LL sum, ans;

int main(){
    scanf("%d", &N);
    for (int i=1; i<=N; i++) scanf("%I64d", &A[i]);
    if (N <= 1){
        printf("%I64d\n", A[1]);
        return 0;
    }
    for (int i=1; i<=N; i++) sum += abs(A[i]);
    for (int i=1; i<N; i++){
        LL T = sum - abs(A[i]) - abs(A[i+1]) + abs(A[i] - A[i+1]);
        ans = max(ans, T);
    }
    printf("%I64d\n", ans);
    return 0;
}