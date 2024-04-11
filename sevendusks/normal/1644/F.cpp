/*
after dusk passed,
there is a starry sky.
*/
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define mod 998244353
#define int long long
#define poly vector <int>
#define len(x) (int)x.size()
#define rev(x) reverse(x.begin(),x.end())
using namespace std;
const int N=2*1e5+100;
int n,k,inv[N],fac[N],v[N],mu[N],p[N],w,sum[N];
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
inline int read()
{
	int f=1,x=0;char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
	return x*f;
}
void prework()
{
	n=200000;
	fac[0]=1;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	inv[n]=m_pow(fac[n],mod-2);
	for (int i=n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
	mu[1]=1;
	for (int i=2;i<=n;i++)
	{
		if (!v[i]) v[i]=p[++w]=i,mu[i]=mod-1;
		for (int j=1;j<=w;j++)
		{
			if (p[j]>n/i||p[j]>v[i]) break;
			v[i*p[j]]=p[j];
			if (i%p[j]) mu[i*p[j]]=mod-mu[i];
			else mu[i*p[j]]=0;
		}
	}
}
int cal(int n)
{
	int lim=min(n,k-1),ans=0;
	for (int i=1;i<=lim;i++)
	{
		int now=m_pow(i+1,n)-1;
		mul(now,m_pow(i,mod-2));
		mul(now,sum[lim-i]*inv[i-1]%mod);
		add(ans,now);
	}
	return ans;
}
int cal_sp(int n)
{
	int lim=min(n,k),ans=0;
	for (int i=0;i<=lim;i++) 
		add(ans,m_pow(i,n)*inv[i]%mod*sum[lim-i]%mod);
	return ans;
}
signed main()
{
	prework();
	n=read();k=read();
	if (k==1)
	{
		printf("1\n");
		return 0;
	}
	sum[0]=1;
	for (int i=1;i<=k;i++)
	{
		sum[i]=sum[i-1];
		if (i&1) del(sum[i],inv[i]);
		else add(sum[i],inv[i]);
	}
	int ans=0;
	for (int i=1;i<=n;i++) if (mu[i]%mod!=0)
	{
		if (n%i==0) add(ans,cal_sp(n/i)*mu[i]%mod);
		else add(ans,cal(n/i)*mu[i]%mod);
	}
	printf("%lld\n",ans);
}