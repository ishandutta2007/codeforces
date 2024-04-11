#include<bits/stdc++.h>
#define ri register signed
#define int long long
#define rd(x) x=read()
using namespace std;
const int N=400+5;
const int M=1e6+5;
const int maxn=5e6+5;
int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}

int n,tmp,ans;
int inv[N],fac[N],ifc[N]; 
void Init(int n)
{
    inv[1]=1;for (ri i=2;i<=n;i++)inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    fac[0]=1;for (ri i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    ifc[0]=1;for (ri i=1;i<=n;i++) ifc[i]=ifc[i-1]*inv[i]%mod;
}
int C(int n,int m){if (m>n || m<0) return 0;return fac[n]*ifc[m]%mod*ifc[n-m]%mod;}
int f[N][N];


void solve()
{
    f[1][1]=1;f[2][1]=2;
    for (int i=3;i<=n;i++) for (int j=1;j<=(i+1)/2;j++) if (j!=1) for (int k=1;k<i-1;k++) f[i][j]+=f[k][j-1]*C(i-j+1,i-k-1)%mod*ksm(2,i-k-2),f[i][j]%=mod;else f[i][j]+=ksm(2,i-1);
    for (int j=1;j<=n;j++) ans+=f[n][j],ans%=mod;
    cout<<ans<<endl;
}
signed main()
{
    rd(n);rd(mod);
    Init(400);
	solve();
}