#include <cstdio>
using namespace std;

int N, T, S;

int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<=i; j++)
            scanf("%d", &T);
        if(T) S = !S;
        for(int j=i+1; j<N; j++)
            scanf("%d", &T);
    }

    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &T); 
        if(T == 3) printf("%d", S);
        else{ scanf("%d", &T); S = !S; }
    }

    printf("\n");
    return 0;
}