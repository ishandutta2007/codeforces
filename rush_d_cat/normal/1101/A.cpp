#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef long long LL;
const int N=200000+10;
int q;LL l,r,d;
int main(){
    scanf("%d",&q);
    while(q--){
        scanf("%lld%lld%lld",&l,&r,&d);
        if(d<l) printf("%lld\n", d);
        else {
            LL ans=(r/d+1)*d;
            printf("%lld\n", ans);
        }
    }
}