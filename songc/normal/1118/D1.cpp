#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N, M, ans;
LL A[202020];

bool chk(int K){
    LL P=0;
    for (int i=1; i<=N; i++) P += max(0ll, A[i] - ((i-1)/K));
    return P >= M;
}

int main(){
    scanf("%d %d", &N, &M);
    for (int i=1; i<=N; i++) scanf("%lld", &A[i]);
    sort(A+1, A+N+1, greater<LL>());
    int L=1, H=N;
    while (L<=H){
        int mid = (L+H)/2;
        if (chk(mid)) ans = mid, H = mid-1;
        else L = mid+1;
    }
    if (ans) printf("%d\n", ans);
    else puts("-1");
    return 0;
}