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
int n,k,ans,tot,mul=1,ok,fac[1000003],ffac[1000003];
array<int,2> a[1000003];
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
signed main()
{
	n=read();
	k=read();
	fac[0]=1;
	for(int i=1;i<=k+2;i++)
		fac[i]=fac[i-1]*i%mod;
	ffac[0]=1;
	for(int i=1;i<=k+2;i++)
		ffac[i]=(ffac[i-1]*(-i)%mod+mod)%mod;
	if(k+2>=n)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
			(ans+=qp(i,k))%=mod;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=k+2;i++)
		mul=(mul*(n-i)%mod+mod)%mod;
	for(int i=1;i<=k+2;i++)
	{
		(tot+=qp(i,k))%=mod;
		(ans+=tot*mul%mod*qp(n-i,mod-2)%mod*qp(fac[i-1]*ffac[k+2-i]%mod,mod-2)%mod)%=mod;
	}
	cout<<ans;
	return 0;
}