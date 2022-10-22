#include <bits/stdc++.h>
using namespace std;

int N, M;
long long K, A[303030], P[303030];

int main(){
    scanf("%d %d", &N, &M);
    for (int i=1; i<=N; i++) scanf("%lld", &A[i]);
    for (int i=1; i<=M; i++) scanf("%lld", &P[i]);
    for (int i=1; i<N; i++) K = __gcd(K, A[i+1]-A[i]);
    for (int i=1; i<=M; i++){
        if (K % P[i] == 0){
            puts("YES");
            printf("%lld %d\n", A[1], i);
            return 0;
        }
    }
    puts("NO");
    return 0;
}