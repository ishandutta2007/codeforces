#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N;
LL M, K, ans, A[101010];

int main(){
    scanf("%lld %d %lld", &M, &N, &K);
    for (int i=1; i<=N; i++) scanf("%lld", &A[i]);
    int t=1;
    while (t<=N){
        LL k = (A[t]-t)/K+1;
        t = upper_bound(A+1, A+N+1, K*k+t-1) - A;
        ans++;
    }
    printf("%lld\n", ans);
    return 0;
}