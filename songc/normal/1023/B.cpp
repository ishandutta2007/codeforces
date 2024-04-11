#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL N, K;

int main(){
    scanf("%I64d %I64d", &N, &K);
    printf("%I64d\n", max(min(N, K-1)-(K/2), 0ll));
    return 0;
}