#include<bits/stdc++.h>
#define int long long 
#define ri register signed
#define rd(x) x=read()
#define endl '\n'
using namespace std;
const int N=500+5;
const int M=1e6+5;
const int maxn=5e6+5;
const int mod=1e9+7;
const int inf=1e18;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if (ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int inv[N],fac[N],ifc[N]; 
void gmax(int &x,int y){x=max(x,y);}
void Init(int n)
{
    inv[1]=1;for (ri i=2;i<=n;i++)inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    fac[0]=1;for (ri i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    ifc[0]=1;for (ri i=1;i<=n;i++) ifc[i]=ifc[i-1]*inv[i]%mod;
}
int f[35][35][2];
int n,ans;
signed main()
{
    rd(n);
    f[30][0][1]=1;
	for (int i=30;i>0;i--) for (int j=0;j<=30;j++)
    {
		f[i-1][j][0]+=(1LL<<j)*f[i][j][0]%mod;f[i-1][j][0]%=mod;
		f[i-1][j+1][0]+=f[i][j][0];f[i-1][j+1][0]%=mod;
		int x=j?(1<<(j-1)):1,y=j?(1<<(j-1)):0;
		if (n>>(i-1)&1)
        {
			f[i-1][j][0]+=x*f[i][j][1]%mod,f[i-1][j][0]%=mod;
			f[i-1][j][1]+=y*f[i][j][1]%mod,f[i-1][j][1]%=mod;
			f[i-1][j+1][1]+=f[i][j][1],f[i-1][j+1][1]%=mod;
		}
        else f[i-1][j][1]+=x*f[i][j][1]%mod,f[i-1][j][1]%=mod;
	}
	for (int i=0;i<=30;i++) ans+=f[0][i][0],ans+=f[0][i][1],ans%=mod;
	cout<<ans<<endl;
}