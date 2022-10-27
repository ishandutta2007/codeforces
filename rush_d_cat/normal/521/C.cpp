#include <iostream>
using namespace std;
typedef long long LL;
const int N = 100000+10;
const LL MOD = 1e9 + 7;
int n,k; char s[N];
LL a[N],sum[N];
LL f[N],inv[N],p[N];
LL C(int a,int b){
    if(b<0)return 0;
    if(a<b)return 0;
    return f[a]*inv[b]%MOD*inv[a-b]%MOD;
}

int main(){
    p[0]=1; for(int i=1;i<N;i++) p[i]=p[i-1]*10%MOD;
    inv[1]=1;
    for(int i=2;i<N;i++)inv[i]=(MOD-(MOD/i))*inv[MOD%i]%MOD;
    f[0]=1;inv[0]=1;
    for(int i=1;i<N;i++)f[i]=f[i-1]*i%MOD, (inv[i]*=inv[i-1])%=MOD;

    scanf("%d%d%s",&n,&k,s+1);
    for(int i=1;i<=n;i++){
        a[i]=a[i-1]*10+s[i]-'0';
        a[i]%=MOD;
        sum[i]=(sum[i-1]+a[i])%MOD;
    }
    if(k==0)
    {
        return !printf("%lld\n", a[n]);
    }
    // 1 1 [1 1] 1 1
    LL ans=0;
    for(int len=1;len<n;len++){
        LL tmp = ((sum[n]-sum[len-1]) - (sum[n-len]*p[len]%MOD) + 2*MOD) % MOD;

        tmp -= (a[len] - a[0]); 
        ans += (a[len]-a[0]*p[len])*C(n-len-1,k-1)%MOD;
        
        tmp -= (a[n] - a[n-len]*p[len]%MOD); 
        ans += (a[n] - a[n-len]*p[len]%MOD)*C(n-len-1,k-1)%MOD;
        
        tmp = (tmp % MOD + MOD) % MOD;
        LL way = C(n-len-2,k-2);
        //printf("way = %lld\n", way);
        ans += tmp*way%MOD;
        ans = (ans%MOD+MOD)%MOD;
    }
    cout<<ans<<endl;
}