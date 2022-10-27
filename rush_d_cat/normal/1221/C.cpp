#include <iostream>
#include <map>
using namespace std;
typedef long long LL;
int q;
int main() {
    scanf("%d", &q);
    while(q--) {
        LL c,m,x;
        scanf("%lld%lld%lld",&c,&m,&x);
        LL ans=min(c,m);
        if(ans*3>(c+m+x)) {
            ans=(c+m+x)/3;
        }
        printf("%lld\n", ans);
    }
}