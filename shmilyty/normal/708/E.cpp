#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int n,m,k,a,b,fac[100001],inv[100001],p[100001],f[1501][1501],pre[1501];
const int mod=1e9+7;
int qp(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1)
			(res*=x)%=mod;
		(x*=x)%=mod;
		y>>=1;
	}
	return res;
}
int C(int x,int y)
{
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
signed main()
{
	n=read();
	m=read();
	a=read();
	b=read();
	k=read();
	(a*=qp(b,mod-2))%=mod;
	fac[0]=inv[0]=inv[1]=1;
	for(int i=1;i<=k;i++)
		fac[i]=fac[i-1]*i%mod;
	for(int i=2;i<=k;i++)
		inv[i]=mod-mod/i*inv[mod%i]%mod;
	for(int i=1;i<=k;i++)
		(inv[i]*=inv[i-1])%=mod;
	for(int i=k,l=1;~i;i--,(l*=(1+mod-a))%=mod)
		p[i]=l;
	for(int i=0,l=1;i<=k;i++,(l*=a)%=mod)
		(p[i]*=l)%=mod;
	for(int i=0;i<=k;i++)
		(p[i]*=C(k,i))%=mod;
	// cout<<C(5,2)<<endl;
	// for(int i=0;i<=k;i++)
		// cout<<p[i]<<" ";
	// cout<<endl;
	f[0][m]=1;
	for(int i=1;i<=n;i++)
	{
		int pre1=0,pre2=0;
		for(int l=1;l<=m;l++)
		{
			(pre1+=p[l-1])%=mod;
			(pre2+=p[l-1]*f[i-1][l-1]%mod)%=mod;
			f[i][l]=(f[i][l-1]+p[m-l]*(pre1*(f[i-1][m]+mod-f[i-1][m-l])%mod+mod-pre2)%mod)%mod;
		}
	}
	cout<<f[n][m];
	return 0;
}