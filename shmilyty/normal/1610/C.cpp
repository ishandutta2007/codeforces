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
int t,n,ans,a[200001],b[200001],f1[200001],f2[200002];
bool check(int x)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(cnt<=a[i]&&cnt+1+b[i]>=x)
			cnt++;
	if(cnt<x)
		return 0;
	return 1;
}
void solve()
{
	n=read();
	ans=INF;
	for(int i=1;i<=n;i++)
	{
		b[i]=read();
		a[i]=read();
	}
	int l=0,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
			l=mid+1;
		else
			r=mid-1;
	}
	cout<<l-1<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}