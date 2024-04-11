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
const int mod=998244353;
int d,n,m,q,inv[300001],a[200001],b[20],f[1<<18];
array<int,2> c[20];
signed main()
{
	d=read();
	n=read();
	m=read();
	inv[0]=inv[1]=1;
	for(int i=2;i<=d;i++)
		inv[i]=mod-mod/i*inv[mod%i]%mod;
	for(int i=0;i<n;i++)
		a[i]=read();
	for(int i=0;i<m;i++)
		b[i]=read();
	for(int i=0;i<(1<<m);i++)
		f[i]=1;
	for(int i=0;i<n;i++)
	{
		for(int l=0;l<m;l++)
			c[l]={abs(b[l]-a[i]),l};
		sort(c,c+m);
		int msk=(1<<m)-1;
		for(int l=0;l<m;l++)
		{
			// cout<<c[l][0]<<" ";
			(f[msk]*=c[l][0])%=mod;
			msk^=(1<<c[l][1]);
			(f[msk]*=inv[c[l][0]])%=mod;
		}
		// cout<<'\n';
		(f[0]*=(d+1))%=mod;
	}
	// for(int i=0;i<(1<<m);i++)
		// cout<<f[i]<<'\n';
	for(int l=0;l<m;l++)
		for(int i=0;i<(1<<m);i++)
			if(!((i>>l)&1))
				(f[i]*=f[i^(1<<l)])%=mod;
	for(int i=0;i<(1<<m);i++)
		if(__builtin_parity(i))
			f[i]=mod-f[i];
	for(int l=0;l<m;l++)
		for(int i=0;i<(1<<m);i++)
			if((i>>l)&1)
				(f[i]+=f[i^(1<<l)])%=mod;
	q=read();
	while(q--)
	{
		int x=read();
		for(int i=0;i<m;i++)
			c[i]={abs(b[i]-x),i};
		sort(c,c+m);
		int msk=(1<<m)-1,ans=0;
		for(int i=0;i<m;i++)
		{
			(ans+=f[msk]*(c[i][0]-(i?c[i-1][0]:0))%mod)%=mod;
			msk^=(1<<c[i][1]);
		}
		cout<<(ans+f[msk]*(d+1-c[m-1][0])%mod)%mod<<'\n';
	}
	return 0;
}