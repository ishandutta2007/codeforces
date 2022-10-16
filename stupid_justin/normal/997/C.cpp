#include<bits/stdc++.h>
#define int long long 
#define rd(x) x=read()
using namespace std;
const int mod=998244353;
const int MOD=mod-1;
const int N=1e6+5;
inline int read(){int x=0,f=1;char ch=getchar();while((ch>'9' || ch<'0')){if(ch=='-') f=-1;ch=getchar();}while('0'<=ch && ch<='9') x=x*10+(ch^48),ch=getchar();return x*f;}
inline int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1LL) ret=ret*x%mod;x=x*x%mod;y>>=1LL;}return ret;}
int n,ans,sav;
int fac[N],inv[N],pw[35000],pw2[35000];
int C(int n,int m){return fac[n]*inv[m]%mod*inv[n-m]%mod;}
int gsm(int t){return pw2[t>>15]*pw[t&32767]%mod;}
void Init()
{
    fac[0]=inv[0]=inv[1]=1;
    for (int i=2;i<=n;i++) inv[i]=(inv[mod%i]*(mod-mod/i))%mod;
    for (int i=1;i<=n;i++){fac[i]=fac[i-1]*i%mod;inv[i]=inv[i]*inv[i-1]%mod;}
    pw[0]=pw2[0]=1;for (int i=1;i<=32767;i++) pw[i]=pw[i-1]*3%mod;
    int buf=pw[32767]*3%mod;
    for (int i=1;i<=31000;i++) pw2[i]=pw2[i-1]*buf%mod;
}
signed main()
{
    rd(n);
    Init();
    for (int i=1;i<=n;i++)
    {
    	sav=C(n,i)*gsm((MOD-i)*n%MOD)%mod*(ksm(1-gsm(i-n+MOD),n)-1)%mod;
    	if (i&1)ans=(ans-sav)%mod;else ans=(ans+sav)%mod;
    }
    ans=ans*gsm((n*n+1)%MOD)%mod;
    ans=(ans+2*gsm(n*n%MOD)%mod*(ksm(1-gsm(MOD+1-n),n)-1))%mod;
    cout<<(mod-ans)%mod<<endl;
}