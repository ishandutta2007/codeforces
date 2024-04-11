#include <bits/stdc++.h>
using namespace std;

int N, S;

int main(){
    scanf("%d", &N);
    if (N <= 2){
        puts("No");
        return 0;
    }
    else puts("Yes");
    S = N * (N+1) / 2;
    for (int i=2; i<N; i++){
        if (S % i == 0){
            printf("1 %d\n", i);
            printf("%d ", N-1);
            for (int j=1; j<=N; j++) if (j != i) printf("%d ",  j);
            return 0;
        }
    }
    return 0;
}