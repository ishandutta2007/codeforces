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
int n,ans=114514,a[2001],b[2001];
bool check()
{
	for(int i=1;i<=2*n;i++)
		if(a[i]!=b[i])
			return 0;
	return 1;
}
signed main()
{
	n=read();
	for(int i=1;i<=2*n;i++)
	{
		a[i]=read();
		b[i]=i;
	}
	for(int i=0;i<2*n;i++)
	{
		if(check())
			ans=min(ans,min(i,2*n-i));
		if(i&1)
			for(int i=1;i<=n;i++)
				swap(a[i],a[i+n]);
		else
			for(int i=1;i<=2*n;i+=2)
				swap(a[i],a[i+1]);
	}
	if(ans==114514)
		ans=-1;
	cout<<ans;
	return 0;
}