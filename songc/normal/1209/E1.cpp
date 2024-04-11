#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int Q, N, M;
int A[16][2020];
int D[16][2020];

int main(){
    scanf("%d", &Q);
    while (Q--){
        scanf("%d %d", &N, &M);
        for (int i=0; i<N; i++) for (int j=1; j<=M; j++) scanf("%d", &A[i][j]);
        memset(D ,0, sizeof D);
        for (int i=1; i<=M; i++) for (int j=0; j<(1<<N); j++){
            for (int k=0; k<N; k++) for (int l=0; l<(1<<N); l++){
                if (l & j) continue;
                int sum = 0;
                for (int x=0; x<N; x++) if (l & (1<<x)) sum += A[(x+k)%N][i];
                D[l|j][i+1] = max(D[l|j][i+1], D[j][i]+sum);
            }
        }
        printf("%d\n", D[(1<<N)-1][M+1]);
    }
    return 0;
}