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
int t,n,ans,a[200001],b[200001];
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	if(n<=2)
	{
		puts("0");
		return ;
	}
	ans=n-2;
	for(int i=1;i<n;i++)
	{
		if(a[n]==a[i])
		{
			ans=min(ans,(i-1));
			break;
		}
		int x=upper_bound(a+1,a+1+n,a[i])-a;
		int maxx=a[x],cnt=x-i+1;
		while(1)
		{
			if(x==n)
				break;
			int val=maxx*2-a[i];
			if(a[n]<val)
				break;
			cnt++;
			x=lower_bound(a+x+1,a+1+n,val)-a;
			maxx=a[x];
		}
		ans=min(ans,n-cnt);
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