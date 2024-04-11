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
int t,n,ans,a[101];
void solve(int l,int r)
{
	int len=0;
	for(int i=l;i<=r;i++)
		if(a[i]==0)
			len++;
	ans+=r-l+1+len; 
}
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	ans=0;
	for(int i=1;i<=n;i++)
		for(int l=i;l<=n;l++)
			solve(i,l);
	cout<<ans<<'\n';
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}