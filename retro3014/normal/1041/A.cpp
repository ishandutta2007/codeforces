#include <iostream>
#include <algorithm>

using namespace std;

int N;
int M=1000000001, K=0;
int t;


int main(){
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        scanf("%d", &t);
        M=min(t, M);
        K=max(t, K);
    }
    printf("%d", K-M+1-N);
    
    return 0;
}