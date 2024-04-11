/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define mod 998244353
#define int long long
#define len(a) (int)a.size()
using namespace std;
const int N=2100;
int T,n,m,k,fac[N],inv[N],s[N][N];
inline void add(int &a,int b){a=((a+b>=mod)?a+b-mod:a+b);}
inline void del(int &a,int b){a=((a-b<0)?a-b+mod:a-b);}
inline void mul(int &a,int b){a=a*b%mod;}
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
	n=2005;
	fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	inv[n]=m_pow(fac[n],mod-2);
	for (int i=n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
	s[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=i;j++) s[i][j]=(s[i-1][j-1]+j*s[i-1][j])%mod;
	}
}
signed main()
{
	prework();
	T=read();
	while (T--)
	{
		n=read();m=read();k=read();
		int A=(m-1)/2+1,iv=m_pow(m,mod-2),z=m_pow(m,n),ans=0;
		for (int i=0;i<=k;i++)
		{
			add(ans,z*s[k][i]%mod);
			mul(z,iv*A%mod*(n-i)%mod);
		}
		printf("%lld\n",ans);
	}
}