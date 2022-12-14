#include <iostream>
#include <algorithm>

using namespace std;

int N, M, K;

int main(){
    scanf("%d%d%d", &N, &M, &K);
    for(int i=1; i*i<=K; i++){
        if(K%i==0){
            int j=K/i;
            if(i<=(2*N) && (2*N)%i==0 && j<=M && M%j==0 && 2*N/i<=N && M/j<=M){
                printf("YES\n");
                printf("0 0\n");
                printf("%d 0\n", 2*N/i);
                printf("0 %d\n", M/j);
                return 0;
            }
            if(i<=(2*N) && (2*N)%i==0 && j<=M && M%j==0 && 2*N/i<=M && M/j<=N){
                printf("YES\n");
                printf("0 0\n");
                printf("0 %d\n", 2*N/i);
                printf("%d 0\n", M/j);
                return 0;
            }
            if(i<=M && M%i==0 && j<=(2*N) && (2*N)%j==0 && M/i<=N && 2*N/j<=M){
                printf("YES\n");
                printf("0 0\n");
                printf("%d 0\n", M/i);
                printf("0 %d\n", 2*N/j);
                return 0;
            }
            if(i<=M && M%i==0 && j<=(2*N) && (2*N)%j==0 && M/i<=M && 2*N/j<=N){
                printf("YES\n");
                printf("0 0\n");
                printf("0 %d\n", M/i);
                printf("%d 0\n", 2*N/j);
                return 0;
            }
            if(i<=N && N%i==0 && j<=(2*M) && (2*M)%j==0 && N/i<=N && 2*M/j<=M){
                printf("YES\n");
                printf("0 0\n");
                printf("%d 0\n", N/i);
                printf("0 %d\n", 2*M/j);
                return 0;
            }
            if(i<=N && N%i==0 && j<=(2*M) && (2*M)%j==0 && N/i<=M && 2*M/j<=N){
                printf("YES\n");
                printf("0 0\n");
                printf("0 %d\n", N/i);
                printf("%d 0\n", 2*M/j);
                return 0;
            }
            if(i<=(2*M) && (2*M)%i==0 && j<=N && N%j==0 && 2*M/i<=N && N/j<=M){
                printf("YES\n");
                printf("0 0\n");
                printf("0 %d\n", N/j);
                printf("%d 0\n", 2*M/i);
                return 0;
            }
            if(i<=(2*M) && (2*M)%i==0 && j<=N && N%j==0 && 2*M/i<=M && N/j<=N){
                printf("YES\n");
                printf("0 0\n");
                printf("%d 0\n", N/j);
                printf("0 %d\n", 2*M/i);
                return 0;
            }
        }
    }
    printf("NO");
    return 0;
}