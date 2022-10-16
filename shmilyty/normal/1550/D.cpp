#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
int t,n,a,b,f[200001],g[200001],jie[200001];
vector<pair<int,int> > v;
const int mod=1e9+7;
map<int,int> vis;
void init()
{
	f[1]=1;
	for(int i=2;i<=2e5;i++)
		f[i]=(mod-mod/i*f[mod%i]%mod)%mod;
	jie[0]=g[0]=1;
	for(int i=1;i<=2e5;i++)
	{
		jie[i]=(jie[i-1]*i)%mod;
		g[i]=(g[i-1]*f[i])%mod;
	}
}
int qp(int x,int y)
{
	if(x<=1)
		return x;
	if(y==0)
		return 1;
	if(y==1)
		return x;
	int res=qp(x,y/2);
	(res*=res)%=mod;
	if(y&1)
		(res*=x)%=mod;
	return res;
}
int C(int x,int y)
{
	if(x==0)
		return 1;
	if(x>y)
		return 0;
	if(x<0)
		return 0;
	if(y<0)
		return 0;
	return jie[y]*qp(jie[y-x],mod-2)%mod*qp(jie[x],mod-2)%mod;
}
void solve()
{
	n=read();
	a=read();
	b=read();
	int k=min(1ll-a,b-n);
	int ans=k*C(n/2,n)%mod;
	if(n&1)
		(ans*=2)%=mod;
	for(int i=k+1;i<=k+n-1;i++)
	{
		int x=max(a-(1-i),0ll),y=max(n+i-b,0ll);
		if(x+y>n)
			break;
		if(x>(n+1)/2||y>(n+1)/2)
			break;
		(ans+=C(n/2-x,n-x-y))%=mod;
		if(n&1)
			(ans+=C((n+1)/2-x,n-x-y))%=mod;
	}
	cout<<ans<<endl;
}
signed main()
{
	init();
	t=read();
	while(t--)
		solve();
	return 0;
}