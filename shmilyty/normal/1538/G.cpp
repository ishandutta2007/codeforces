#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
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
int t,n,m,a,b;
bool check(int x)
{
	int nn=n-min(a,b)*x;
	int mm=m-min(a,b)*x;
	if(nn<0||mm<0)
		return 0;
	if(a-b==0)
		return 1;
	if(nn/abs(a-b)+mm/abs(a-b)>=x)
		return 1;
	return 0;
}
void solve()
{
	n=read();
	m=read();
	a=read();
	b=read();
	int l=0,r=2e9,ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
			r=mid-1;
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