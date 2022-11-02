#include <stdio.h>
#include <algorithm>
using namespace std;
int A, N, P, H, R;
int F(long long a, int n, int p){
    int t = a*n/p;
    if(!t)return a>p-a*n?a:p-a*n;
    if(a*n%p<a*(p/a-1))t--;
    return F(min(p%a, a-p%a), t, a);
}
int main(){
    ///freopen("E.in", "r", stdin);
    for(scanf("%d", &R); R--; ){
        scanf("%d%d%d%d", &A, &N, &P, &H);
        //printf("%d %d %d %d\n", A, N, P, H);
        int HH;
        A%=P;
        if(1LL*A*N<P)HH=A;
        else HH=F(A, N, P);
        puts(HH<=H ? "YES" : "NO");
    }
}