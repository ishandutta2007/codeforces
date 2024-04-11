#include <bits/stdc++.h>
using namespace std;

int N, S, K;
int cnt[101010];

int main(){
    int s, e;
    scanf("%d %d", &N, &S);
    if (N == 2){
        printf("%d\n", S);
        return 0;
    }
    for (int i=1; i<N; i++){
        scanf("%d %d", &s, &e);
        cnt[s]++;
        cnt[e]++;
    }
    for (int i=1; i<=N; i++) if (cnt[i] == 1) K++;
    printf("%.12f\n", (double)S/K*2);
    return 0;
}