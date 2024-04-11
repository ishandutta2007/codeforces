#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL A, B, X, Y;

int main(){
    scanf("%I64d %I64d %I64d %I64d", &A, &B, &X, &Y);
    LL g = __gcd(X, Y);
    X /= g, Y /= g;
    printf("%I64d\n", min(A/X, B/Y));
    return 0;
}