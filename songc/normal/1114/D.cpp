#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[5050];
int D[5050][5050];
int ans=1234567890;

int main(){
    int a;
    scanf("%d", &M);
    for (int i=1; i<=M; i++){
        scanf("%d", &a);
        if (A[N] != a){
            N++;
            A[N] = a;
        }
    }
    for (int i=1; i<N; i++){
        for (int j=N; j>i; j--){
            if (A[i] == A[j]) D[i][j] = D[i-1][j+1] + 1;
            D[i][j] = max(D[i][j], D[i-1][j]);
            D[i][j] = max(D[i][j], D[i][j+1]);
            D[i][j] = max(D[i][j], D[i-1][j+1]);
        }
    }
    for (int i=1; i<=N; i++) ans = min(ans, N - 1 - D[i-1][i+1]);
    printf("%d\n", ans);
    return 0;
}