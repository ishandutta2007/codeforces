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
int t,a,b,ans;
void solve()
{
	a=read();
	b=read();
	ans=0;
	if(a<b)
	{
		int n=(b-a)/2;
		if(a<n||b<n*3)
		{
			cout<<min(a,b/3)<<endl;
			return ;
		}
		a-=n;
		b-=n*3;
		ans+=n;
	}
	else
	{
		int n=(a-b)/2;
		if(a<n*3||b<n)
		{
			cout<<min(a/3,b)<<endl;
			return ;
		}
		a-=n*3;
		b-=n;
		ans+=n;
	}
	int k=min(a,b)/2;
	ans+=k;
	a-=k*2;
	b-=k*2;
	while(a&&b>2)
	{
		a--;
		b-=3;
		ans++;
	}
	while(b&&a>2)
	{
		b--;
		a-=3;
		ans++;
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