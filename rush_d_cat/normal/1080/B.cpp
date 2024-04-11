#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
LL f(LL x){
    if(x%2==0) return x/2;
    return x/2 - x;
}
int q;
int main(){
    scanf("%d",&q);
    while(q--){
        LL L,R; scanf("%lld%lld",&L,&R);
        printf("%lld\n", f(R)-f(L-1));
    }
}