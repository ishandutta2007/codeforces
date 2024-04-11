#include <bits/stdc++.h>
using namespace std;

int T, N;

int main(){
    scanf("%d", &T);
    while (T--){
        scanf("%d", &N);
        for (int i=3; i<=360; i++){
            bool tf = false;
            for (int j=1; j<=i-2; j++){
                if (180 * j == N * i){
                    tf = true;
                    break;
                }
            }
            if (tf){
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}