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
int t,n,minn,x;
void solve()
{
	n=read();
	minn=114514114514114514;
	cout<<n-1<<endl;
	for(int i=1;i<=n;i++)
	{
		int a=read();
		if(a<minn)
		{
			minn=a;
			x=i;
		}
	}
	for(int i=1;i<x;i++)
		cout<<x-i<<" "<<x<<" "<<minn+i<<" "<<minn<<endl;
	for(int i=x+1;i<=n;i++)
		cout<<i<<" "<<x<<" "<<minn+i-x<<" "<<minn<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}