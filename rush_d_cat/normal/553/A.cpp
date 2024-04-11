#include <iostream>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
int n;
LL mpow(LL a,LL x){
    if(x==0)return 1;
    LL t=mpow(a,x>>1);
    if(x%2==0)return t*t%MOD;
    return t*t%MOD*a%MOD;
}
LL fac[1002],inv[1002];
int c[1002],p[1002];
int main() {
    fac[0]=1;inv[0]=1;
    for(int i=1;i<=1000;i++){
        fac[i]=fac[i-1]*i%MOD; inv[i]=mpow(fac[i],MOD-2);
    }
    cin>>n;
    int s=0;
    LL ans=1;
    for(int i=1;i<=n;i++){
        cin>>c[i]; s+=c[i]; p[i]=p[i-1]+c[i];
        ans=ans*inv[c[i]]%MOD;
        ans=ans*c[i]%MOD*mpow(p[i],MOD-2)%MOD;
    }
    ans=ans*fac[s]%MOD;
    cout<<ans<<endl;
}