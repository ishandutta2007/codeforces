#include <bits/stdc++.h>
using namespace std;

int T, N;
int tea[1010][2], sec;

int main(){
    scanf("%d", &T);
    for (int tc=0; tc<T; tc++){
        scanf("%d", &N);
        for (int i=0; i<N; i++) scanf("%d %d", &tea[i][0], &tea[i][1]);
        sec=1;
        for (int i=0; i<N; i++){
            if (tea[i][1] < sec) printf("0 ");
            else {
                printf("%d ", max(sec, tea[i][0]));
                sec = max(sec+1, tea[i][0]+1);
            }
        }
        printf("\n");
    }
    return 0;
}