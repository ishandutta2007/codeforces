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
int t,n,a[10001];
void solve()
{
	int x=0,y=0;
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(a[i]==n)
			x=i;
		if(a[i]==1)
			y=i;
	}
//	cout<<x<<" "<<y<<endl;
	int ans=max(abs(x-y)-1,max(min(x,y)-1,n-max(x,y)));
	cout<<n-ans<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}