#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL N;

int main(){
    scanf("%I64d", &N);
    for (LL i=2; i*i<=N; i++){
        if (N % i == 0){
            printf("%I64d\n", 1 + (N-i)/2);
            return 0;
        }
    }
    printf("1\n");
    return 0;
}