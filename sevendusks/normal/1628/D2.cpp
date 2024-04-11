/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define mod 1000000007
#define int long long
#define len(a) (int)a.size()
using namespace std;
const int N=1e6+100,iv2=(mod+1)/2;
int T,n,m,k,fac[N],inv[N],z[N];
inline void add(int &a,int b){a=((a+b>=mod)?a+b-mod:a+b);}
inline void del(int &a,int b){a=((a-b<0)?a-b+mod:a-b);}
inline void mul(int &a,int b){a=a*b%mod;}
inline int C(int n,int m){return fac[n]*inv[m]%mod*inv[n-m]%mod;}
inline int m_pow(int a,int b)
{
	int ans=1;
	while (b)
	{
		if (b&1) mul(ans,a);
		b>>=1;
		mul(a,a);
	}
	return ans;
}
inline void ckmin(int &a,int b){a=((a<b)?a:b);}
inline void ckmax(int &a,int b){a=((a>b)?a:b);}
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
void prework()
{
	n=1000010;
	fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	inv[n]=m_pow(fac[n],mod-2);
	for (int i=n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
	z[0]=1;
	for (int i=1;i<=n;i++) z[i]=z[i-1]*iv2%mod;
}
signed main()
{
	prework();
	T=read();
	while (T--)
	{
		n=read();m=read();k=read();
		int ans=0;
		for (int i=1;i<=n;i++) if (i<=m)
		{
			int now=k*(i+1)%mod;
			mul(now,iv2*z[n-i]%mod);
			mul(now,C(n-i,m-i));
			add(ans,now);
		}
		printf("%lld\n",ans);
	}
}