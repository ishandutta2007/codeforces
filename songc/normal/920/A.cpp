#include <bits/stdc++.h>
using namespace std;

int T, N, K;
int G[220];

int main() {
    int x, chk;
    scanf("%d", &T);
    for (int tc=0; tc<T; tc++){
        scanf("%d %d", &N, &K);
        for (int i=0; i<K; i++){
            scanf("%d", &x);
            G[x] = 1;
        }
        for (int i=1; ; i++){
            chk = true;
            for (int j=1; j<=N; j++){
                if (G[j] == 0){
                    chk = false;
                    if (G[j-1] == i || G[j+1] == i){
                        G[j] = i+1;
                    }
                }
            }
            if (chk) {
                printf("%d\n", i);
                break;
            }
        }
        for (int i=1; i<=N; i++) G[i] = 0;
    }
    return 0;
}