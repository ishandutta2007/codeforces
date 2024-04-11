#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL A, B, ans, X;
bool chk[1010101];

int main(){
    scanf("%I64d %I64d", &A, &B);
    for (ans=0; A+B >= ans*(ans+1)/2; ans++);
    ans--;
    for (int i=ans; i>0 && A>0; i--) {
        if (i <= A) A -= i, chk[i] = true, X++;
    }
    printf("%I64d\n", X);
    for (int i=1; i<=ans; i++) if (chk[i]) printf("%d ", i);
    printf("\n%I64d\n", ans-X);
    for (int i=1; i<=ans; i++) if (!chk[i]) printf("%d ", i);
    return 0;
}