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
int t,n,sum,a[200001];
void solve()
{
	sum=0;
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		sum+=a[i];
	}
	if(sum%n)
	{
		puts("-1");
		return ;
	}
	sum/=n;
	int ans=0;
	for(int i=1;i<=n;i++)
		if(a[i]>sum)
			ans++;
	cout<<ans<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}