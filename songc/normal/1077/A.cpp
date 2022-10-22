#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int T;
LL A, B, K;

int main(){
    scanf("%d", &T);
    while (T--){
        scanf("%I64d %I64d %I64d", &A, &B, &K);
        printf("%I64d\n", (K/2) * (A-B) + (K&1) * A);
    }
    return 0;
}