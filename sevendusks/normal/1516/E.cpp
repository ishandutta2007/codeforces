/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define mod 1000000007
#define int long long
using namespace std;
const int N=410;
int n,k,dp[N][N],fac[N],inv[N],d[N],id[N],s[N];
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
inline int C(int p,int k)
{
	if (k==0) return 1;
	if (p==0) return d[k-1]*inv[k]%mod;
	return d[p+k-1]*id[p-1]%mod*inv[k]%mod;
}
signed main()
{
	n=read();k=read();
	fac[0]=1;
	for (int i=1;i<=2*k;i++) fac[i]=fac[i-1]*i%mod;
	inv[2*k]=m_pow(fac[2*k],mod-2);
	for (int i=2*k-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
	d[0]=n;
	int lim=min(2*k,n-1);
	for (int i=1;i<=lim;i++) d[i]=d[i-1]*(n-i)%mod;
	id[lim]=m_pow(d[lim],mod-2);
	for (int i=lim-1;i>=0;i--) id[i]=id[i+1]*(n-i-1)%mod;
	dp[0][0]=1;
	for (int i=1;i<=k;i++)
	{
		int lim=min(i+k,n);
		for (int j=1;j<=lim;j++)
		{
			for (int p=2;p<=j;p++)
			{
				add(dp[i][j],dp[i-1][j-p]*fac[j-1]%mod*inv[j-p]%mod);
			}
		}
	}
	for (int i=0;i<=k;i++)
	{
		for (int j=i;j<=i+k;j++) add(s[j-i],dp[i][j]*C(0,j)%mod);
	}
	for (int i=2;i<=k;i++) add(s[i],s[i-2]);
	for (int i=1;i<=k;i++) printf("%lld ",s[i]);
	printf("\n");
}