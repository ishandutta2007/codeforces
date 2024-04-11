#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	bool flag=1;
	int x=0;
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
int t,n,k,a[101];
void solve()
{
	n=read();
	k=read();
	memset(a,0,sizeof(a));
	if(k>(n-1)/2)
	{
		puts("-1");
		return ;
	}
	int cnt=n;
	for(int i=2;i<=k*2;i+=2)
	{
		a[i]=cnt;
		cnt--;
	}
	for(int i=1;i<=n;i++)
		if(!a[i])
		{
			cout<<cnt<<" ";
			cnt--;
		}
		else
			cout<<a[i]<<" ";
	cout<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}