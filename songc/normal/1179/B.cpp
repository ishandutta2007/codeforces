#include <bits/stdc++.h>
#define INF 1234567890
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N, M;

int main(){
    scanf("%d %d", &N, &M);
    for (int i=1; i<=M/2; i++){
        for (int j=0; j<N; j++){
            printf("%d %d\n", 1+j, i);
            printf("%d %d\n", N-j, M-i+1);
        }
    }
    if (M & 1){
        for (int i=0; i<N/2; i++){
            printf("%d %d\n", i+1, M/2+1);
            printf("%d %d\n", N-i, M/2+1);
        }
        if (N & 1) printf("%d %d\n", N/2+1, M/2+1);
    }
    return 0;
}