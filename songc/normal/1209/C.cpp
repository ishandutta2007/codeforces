#include <bits/stdc++.h>
using namespace std;

int Q, N;
int A[201010];
int ans[201010];
int O, T;

int main(){
    scanf("%d", &Q);
    while (Q--){
        scanf("%d", &N);
        for (int i=1; i<=N; i++) scanf("%1d", &A[i]);
        for (int i=0; i<=9; i++){
            bool tf = true;
            O = T = 0;
            for (int j=1; j<=N; j++){
                if (A[j] < i){
                    if (O > A[j]){
                        tf = false;
                        break;
                    }
                    ans[j] = 1;
                    O = A[j];
                }
                else if (A[j] > i){
                    if (T > A[j]){
                        tf = false;
                        break;
                    }
                    ans[j] = 2;
                    T = A[j];
                }
                else{
                    if (T <= i) ans[j] = 2;
                    else ans[j] = 1, O = i;
                }
            }
            if (tf) {
                for (int j=1; j<=N; j++) printf("%d", ans[j]);
                printf("\n");
                break;
            }
            if (i >= 9) puts("-");
        }
    }
    return 0;
}