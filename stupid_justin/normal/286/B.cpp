#include<bits/stdc++.h>
#define int long long 
#define ri register signed
#define rd(x) x=read()
using namespace std;
const int N=2e6+5;
const int M=1e6+5;
const int maxn=5e6+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f3f3f3f3f;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline int ksm(int x,int y=mod-2,int z=mod){int ret=1;while (y){if (y&1) ret=(ret*x)%z;x=(x*x)%z;y>>=1;}return ret;}
int inv[N],fac[N],ifc[N]; 
void Init(int n)
{
    inv[1]=1;for (ri i=2;i<=n;i++)inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    fac[0]=1;for (ri i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    ifc[0]=1;for (ri i=1;i<=n;i++) ifc[i]=ifc[i-1]*inv[i]%mod;
}
int C(int n,int m){if (m>n || m<0) return 0;return fac[n]*ifc[m]%mod*ifc[n-m]%mod;}
int f(int b,int n)
{
	if (b==0 || b==1) return -1;
	if (n<b) return n;
	return f(b,n/b)+n%b;
}
int n;
int a[N];
//
// n/i 
//
// tag
// k  k+1 

signed main()
{
	rd(n);for (int i=1;i<=n;i++) a[i]=i;
	
	for (int k=2;k<=n;k++)
	{
		a[n+k-1]=a[n+k-1-(n-(n/k)*k)];
		for(int i=(n/k)*k+k-1;i>=k-1;i-=k) a[i]=a[i-k];	
	}
	for (int i=n;i<2*n;i++) cout<<a[i]<<" ";cout<<endl;
}