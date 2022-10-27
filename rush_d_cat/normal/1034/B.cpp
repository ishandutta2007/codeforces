#include <iostream>
using namespace std;
typedef long long LL;
int biao[6][6];

int main() {
    LL n,m; cin>>n>>m;
    if(n>m) swap(n,m);

    if(n==1) {
        LL ans;
        if(m<=3) ans=0;
        else if(m%6==1) ans=m-1;
        else if(m%6==2) ans=m-2;
        else if(m%6==3) ans=m-3;
        else if(m%6==4) ans=m-2;
        else if(m%6==5) ans=m-1;
        else ans=m;
        return !printf("%lld\n", ans);
    } 

    if(n==2){
        LL ans;
        if(m<=2) ans=0;
        else if(m==3) ans=4;
        else if(m==7) ans=12;
        else ans=2*m;
        return !printf("%lld\n", ans);
    }

    if(n%2==0 || m%2==0) return !printf("%lld\n", n*m);
    return !printf("%lld\n", n*m-1);

}