#include <iostream>
using namespace std;
typedef long long LL;
const LL MOD=998244353;
int n,m,k;
LL mpow(LL a,LL x){
    if(x==0)return 1;
    LL t=mpow(a,x>>1);
    if(x%2==0)return t*t%MOD;
    return t*t%MOD*a%MOD;
}
LL p[5002][5002];
int main() {
    cin>>n>>m>>k;
    p[0][0]=1;
    LL invn = mpow(n,MOD-2);
    for(int i=0;i<5000;i++){
        for(int j=0;j<=min(i,n);j++){
            (p[i+1][j]+=p[i][j]*j%MOD*invn%MOD)%=MOD;
            (p[i+1][j+1]+=p[i][j]*(n-j)%MOD*invn%MOD)%=MOD;
        }
    }
    LL ans=0;
    for(int i=1;i<=k;i++){
        LL v1=p[k][i];
        LL v2=mpow(mpow(m,MOD-2),i);
        (ans+=v1*v2%MOD*mpow(n,k))%=MOD;
    }
    cout<<ans<<endl;
}