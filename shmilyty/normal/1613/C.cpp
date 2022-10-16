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
int t,n,h,a[101];
bool check(int x)
{
	int res=0;
	for(int i=1;i<n;i++)
		res+=min(x,a[i+1]-a[i]);
	return res+x>=h;
}
void solve()
{
	n=read();
	h=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	int l=1,r=1e18;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
			r=mid-1;
		else
			l=mid+1;
	}
	cout<<l<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}