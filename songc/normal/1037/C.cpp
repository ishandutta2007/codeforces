#include <bits/stdc++.h>
using namespace std;

int N;
int D[1010101];
int A[1010101];
int B[1010101];

int main(){
    scanf("%d", &N);
    for (int i=1; i<=N; i++) scanf("%1d", &A[i]);
    for (int i=1; i<=N; i++) scanf("%1d", &B[i]);
    for (int i=1; i<=N; i++){
        if (A[i] ^ B[i]) {
            D[i] = D[i-1] + 1;
            if (A[i-1] ^ B[i-1] && A[i] ^ A[i-1]) D[i] = D[i-2] + 1;
        }
        else D[i] = D[i-1];
    }
    printf("%d", D[N]);
    return 0;
}