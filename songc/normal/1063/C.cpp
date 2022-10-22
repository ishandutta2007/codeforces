#include <bits/stdc++.h>
using namespace std;

int N;
int L=0, R=1000000000;
char a, str[10];

int main(){
    scanf("%d", &N);
    printf("%d 1\n", L);
    fflush(stdout);
    scanf("%s", str);
    a = str[0];
    for (int i=2; i<=N; i++){
        printf("%d 1\n", (L+R)/2);
        fflush(stdout);
        scanf("%s", str);
        if (str[0] == a) L = (L+R)/2;
        else R = (L+R)/2;
    }
    printf("%d %d %d %d\n", L, 0, R, 2);
    fflush(stdout);
    return 0;
}