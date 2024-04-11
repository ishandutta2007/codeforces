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
int t,n,x,y,minn,a[200001],vis[200001];
void solve()
{
	n=read();
	minn=114514114514114514;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		vis[i]=0;
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
		if(a[i]-a[i-1]<minn)
		{
			minn=a[i]-a[i-1];
			x=i-1;
			y=i;
		}
	vis[x]=vis[y]=1;
	cout<<a[x]<<" ";
	for(int i=y+1;i<=n;i++)
		cout<<a[i]<<" ";
	for(int i=1;i<x;i++)
		cout<<a[i]<<" ";
	cout<<a[y]<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}