#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N, ans;
int A[202020], P[202020], S[202020];

int main(){
    scanf("%d", &N);
    for (int i=1; i<=N; i++) scanf("%d", &A[i]);
    P[1] = A[1];
    for (int i=2; i<=N; i++) P[i] = A[i] + P[i-2];
    for (int i=N; i>=1; i--) S[i] = A[i] + S[i+2];
    if (S[3] == S[2]) ans++;
    for (int i=2; i<=N; i++){
        if (P[i-1] + S[i+2] == P[i-2] + S[i+1]) ans++;
    }
    printf("%d\n", ans);
    return 0;
}