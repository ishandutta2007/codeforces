#include <iostream>
using namespace std;
typedef long long LL;
const int N=2000000+10;
const LL MOD=1e9+7;
int n,a[N]; LL sum[N],pw[N];
int main() {
    pw[0]=1;for(int i=1;i<N;i++)pw[i]=pw[i-1]*2%MOD;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum[a[i]]++;
    for(int i=0;i<20;i++) for(int j=0;j<1<<20;j++) if(!(j>>i&1)) sum[j]+=sum[j^(1<<i)];
    for(int i=0;i<1<<20;i++) {
        sum[i]=(pw[sum[i]]-1);
    }
    LL ans=0;
    for(int i=0;i<1<<20;i++){
        int c=0;
        for(int j=0;j<20;j++)if(i>>j&1) c++;
        if(c&1) ans-=sum[i]; else ans+=sum[i];
        ans=(ans%MOD+MOD)%MOD; 
    }
    printf("%lld\n", ans);
}