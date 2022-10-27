#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int N=250000+10;
typedef long long LL;
LL fac[N];
LL n,m;
int main() {
    scanf("%lld%lld",&n,&m);
    fac[0]=1;
    for(int i=1;i<N;i++){
        fac[i]=fac[i-1]*i%m;
    }
    LL ans=0;
    for(int x=1;x<=n;x++){
        // R-L+1 = x
        LL tmp=0;
        tmp=(n-x+1)*fac[x]%m;
        tmp=tmp*fac[n-x]%m;
        tmp=tmp*(n-x+1)%m;
        ans=(ans+tmp)%m;
    }
    cout<<ans<<endl;
}