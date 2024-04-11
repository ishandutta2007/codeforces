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
int t,n,a[400004];
void solve()
{
	n=read();
	int k=0;
	a[0]=a[n+1]=0;
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
		if(a[i]>max(a[i-1],a[i+1]))
		{
			k+=a[i]-max(a[i-1],a[i+1]);
			a[i]=max(a[i-1],a[i+1]); 
		}
	for(int i=0;i<=n;i++)
		k+=abs(a[i]-a[i+1]);
	cout<<k<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}