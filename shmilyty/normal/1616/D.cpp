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
int t,n,k,ans,a[50001],ok[50001];
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	fill(ok+1,ok+1+n,0);
	k=read();
	ok[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!ok[i-1])
			ok[i]=1;
		else
		{
			if(a[i]+a[i-1]<2*k)
				continue;
			if(ok[i-2])
			{
				if(a[i-1]+a[i-2]+a[i]>=3*k)
					ok[i]=1;
			}
			else
				ok[i]=1;
		}
	}
	ans=0;
	for(int i=1;i<=n;i++)
		ans+=ok[i];
	cout<<ans<<'\n';
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}