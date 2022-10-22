#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N;
LL A[303030], ans;

int main(){
    scanf("%d", &N);
    for (int i=1; i<=N; i++) scanf("%lld", &A[i]);
    sort(A+1, A+N+1);
    for (int i=1; i<=N/2; i++) ans += (A[i]+A[N-i+1])*(A[i]+A[N-i+1]);
    printf("%lld\n", ans);
    return 0;
}