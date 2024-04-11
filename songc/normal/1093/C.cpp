#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N;
LL A[202020], B;

int main(){
    scanf("%d", &N);
    scanf("%lld", &B);
    A[N] = B;
    for (int i=2; i<=(N/2); i++) {
        scanf("%lld", &B);
        if (B - A[i-1] <= A[N-i+2]) {
            A[i] = A[i-1];
            A[N-i+1] = B - A[i-1];
        }
        else {
            A[N-i+1] = A[N-i+2];
            A[i] = B - A[N-i+2];
        }
    }
    for (int i=1; i<=N; i++) printf("%lld ", A[i]);
    return 0;
}