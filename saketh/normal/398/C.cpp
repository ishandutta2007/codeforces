#include <stdio.h>

int N;

void edge(int i, int j, int c){
    printf("%d %d %d\n", i, j, c);
}

int main(){
    scanf("%d", &N);

    if(N == 5){
        edge(1, 2, 2);
        edge(1, 3, 1);
        edge(2, 4, 1);
        edge(4, 5, 1);
        printf("3 4\n3 5\n");
        return 0;
    }

    int TE = N/2;
    int BS = TE + 1 + N%2;

    if(N%2) edge(TE, TE+1, 1);

    for(int i=0; i<TE; i++)
        edge(i+1, BS+i, 1);

    int a = 1;
    for(int n = TE; n>1; n--){
        edge(n-1, n, a);
        if(n == TE) a += 2;
        else a++;
    }

    for(int n=BS; n<N; n++)
        printf("%d %d\n", n, N);
    printf("%d %d\n", N-2, N-1);
    return 0;
}