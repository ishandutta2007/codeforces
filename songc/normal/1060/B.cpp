#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL N, ans;

int main(){
    scanf("%I64d", &N);
    while (N > 9){
        N -= 9;
        ans += 9;
        ans += (N % 10);
        N /= 10;
    }
    printf("%I64d", ans+N);
    return 0;
}