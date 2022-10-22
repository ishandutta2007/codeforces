#include <bits/stdc++.h>
using namespace std;

long long N, K;

int main(){
    scanf("%I64d %I64d", &N, &K);
    printf("%I64d", (K / N) + ((K % N) ? 1 : 0));
    return 0;
}