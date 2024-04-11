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
int t,n,a[2001],ok[2001][2001];
void solve()
{
	n=read();
	for(int i=1;i<=n;i++)
		for(int l=1;l<=n;l++)
			ok[i][l]=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(a[i]%2==0)
			for(int l=1;l<=n;l++)
				ok[i][l]=1;
		else
			for(int l=1;l<i;l++)
				if(__gcd(a[i],a[l])>1)
					ok[i][l]=ok[l][i]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int l=1;l<i;l++)
			ans+=(ok[i][l]|ok[l][i]);
	cout<<ans<<endl; 
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}