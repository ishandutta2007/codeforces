#include <bits/stdc++.h>
using namespace std;

int N, M, K, ans;
char s[2020][2020];

int main(){
    int con;
    scanf("%d %d %d", &N, &M, &K);
    for (int i=0; i<N; i++) scanf("%s", s[i]);

    if (K == 1){
        for (int i=0; i<=N; i++) for (int j=0; j<=M; j++) if (s[i][j] == '.') ans++;
        printf("%d", ans);
        return 0;
    }

    for (int i=0; i<N; i++){
        con=0;
        for (int j=0; j<=M; j++){
            if (s[i][j] == '.') con++;
            else {
                if (con >= K) ans += con-K+1;
                con = 0;
            }
        }
    }

    for (int i=0; i<M; i++){
        con=0;
        for (int j=0; j<=N; j++){
            if (s[j][i] == '.') con++;
            else {
                if (con >= K) ans += con-K+1;
                con = 0;
            }
        }
    }

    printf("%d", ans);
    return 0;
}