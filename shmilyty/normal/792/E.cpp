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
int n,ans,a[501];
void solve(int x)
{
	if(x==0)
		return ;
	int res=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]/x<a[i]%x)
			return ;
		res+=a[i]/x-(a[i]/x-a[i]%x)/(x+1);
	}
	ans=min(ans,res);
}
signed main()
{
	n=read();
	ans=INF;
	for(int i=1;i<=n;i++)
		a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i*i<=a[1];i++)
	{
		solve(i);
		solve(a[1]/i);
		solve(a[1]/i-1);
	}
	cout<<ans;
	return 0;
}