#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int P=1000000007;
LL F(LL n,LL k){
    if(k==0)return n;
    if(n==1)return 1;
    LL ans=F(n,k-1);
    LL x=ans;
    for(int i=2;i*1ll*i<=x;i++)if(x%i==0){
        while(x%i==0)x/=i;
        ans=(ans/i)*1ll*(i-1);
    }
    if(x>1)ans=(ans/x)*1ll*(x-1);
    return ans;
}
int main(){
    LL n,k;
    scanf("%I64d%I64d",&n,&k);
    k=(k+1)/2;
    while(k--){
        if(n==1)break;
        LL ans=n;
        LL x=ans;
        for(int i=2;i*1ll*i<=x;i++)if(x%i==0){
            while(x%i==0)x/=i;
            ans=(ans/i)*1ll*(i-1);
        }
        if(x>1)ans=(ans/x)*1ll*(x-1);
        n=ans;
    }
    printf("%d\n",n%P);
    return 0;
}