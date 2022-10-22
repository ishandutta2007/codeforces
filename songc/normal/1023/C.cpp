#include <bits/stdc++.h>
using namespace std;

int N, K;
int arr[202020];
int stk[202020], p;
char str[202020];

int main() {
    scanf("%d %d", &N, &K);
    scanf("%s", str);
    for (int i=0; i<N; i++){
        if (str[i] == '(') stk[p++] = i;
        else arr[stk[--p]] = i;
    }
    p=0;
    for (int i=0; i<N && K > 0; i++){
        if (str[i] == '('){
            K -= 2;
            while (p > 0 && stk[p-1] < i){
                printf(")");
                p--;
            }
            printf("(");
            stk[p++] = arr[i];
        }
    }
    for (int i=0; i<p; i++) printf(")");
    return 0;
}