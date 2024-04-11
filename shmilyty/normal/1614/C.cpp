#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
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
const int mod=1e9+7;
int t,n,m,ans,a[200002],num[31];
array<int,3> q[200001];
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
void solve()
{
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int l=read(),r=read(),x=read();
		q[i]={l,r,x};
	}
	memset(num,0,sizeof(num));
	ans=0;
	for(int i=0;i<=30;i++)
	{
		for(int l=1;l<=n;l++)
			a[l]=0;
		for(int l=1;l<=m;l++)
			if(!((q[l][2]>>i)&1))
			{
				a[q[l][0]]++;
				a[q[l][1]+1]--;
			}
		for(int l=1;l<=n;l++)
			a[l]+=a[l-1];
		for(int l=1;l<=n;l++)
			if(!a[l])
				num[i]++;
		if(num[i])
			(ans+=qp(2,num[i]-1)*qp(2,n-num[i])%mod*(1ll<<i)%mod)%=mod;
	}
	cout<<ans<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}