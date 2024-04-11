#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N;
LL ans;
int A[202020];

int main(){
    scanf("%d", &N);
    for (int i=1; i<=N; i++){
        scanf("%d", &A[i]);
        if (A[i] < 0) A[i] *= -1;
    }
    sort(A+1, A+N+1);
    for (int i=1; i<=N; i++){
        if (A[i] == A[i-1] && i>1) ans += upper_bound(A+1, A+N+1, A[i-1]*2) - A - i - 1;
        else ans += upper_bound(A+1, A+N+1, A[i]*2) - A - i - 1;
    }
    printf("%lld\n", ans);
    return 0;
}