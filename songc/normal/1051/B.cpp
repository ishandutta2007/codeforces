#include <bits/stdc++.h>
using namespace std;

long long L, R;

int main(){
    scanf("%I64d %I64d", &L, &R);
    printf("YES\n");
    for (long long i=L; i<R; i+=2) printf("%I64d %I64d\n", i, i+1);
    return 0;
}