#include <iostream>
using namespace std;
typedef long long LL;
const LL MOD=998244353;
const int N=10000+10;
int p,s,r;
LL fac[N],inv[N],rev[N];
LL mpow(LL a,LL x){
    if(x==0)return 1;
    LL t=mpow(a,x>>1);
    if(x%2==0)return t*t%MOD;
    return t*t%MOD*a%MOD;
}
LL c(int a,int b){
    if(a <b)return 0;
    if(a==b)return 1;
    return fac[a]*inv[b]%MOD*inv[a-b]%MOD;
}
LL cac(int n,int m,int k){
    LL ret=0;
    for(int i=0;i<=n;i++){
        if(m>=(k+1)*i){
            LL tmp = c(n,i) * c(m-(k+1)*i + n-1, n-1) % MOD;
            if(i%2==1) ret=(ret-tmp+MOD)%MOD;
            else ret=(ret+tmp)%MOD;
        }
    } 
    return ret;
}
int main(){
    fac[0]=1;inv[0]=1;rev[0]=1;
    for(int i=1;i<N;i++){
        rev[i]=mpow(i,MOD-2);
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=mpow(fac[i],MOD-2);
    }
    cin>>p>>s>>r;
    LL tot=0;
    for(int i=r;i<=s;i++){
        tot=(tot+c(s-i + (p-2),(p-2)))%MOD;
    }
    tot=mpow(tot,MOD-2); LL res=0;
    for(int i=r;i<=s;i++){
        for(int j=0;j<=p-1;j++){
            if(s-i-j*i>=0){
                res=res + rev[j+1]*c(p-1,j)%MOD*cac(p-1-j,s-i-j*i,i-1)%MOD*tot%MOD;
                res%=MOD;
            }
        }
    }
    cout<<res<<endl;
}