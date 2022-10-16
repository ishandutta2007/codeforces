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
int t,n,a[101],d[101];
void solve(int l,int r,int dp)
{
	if(l==r)
	{
		d[l]=dp;
		return ;
	}
	if(l>r)
		return ;
	int rt=0;
	for(int i=l;i<=r;i++)
		if(a[i]>a[rt])
			rt=i;
	d[rt]=dp;
	solve(l,rt-1,dp+1);
	solve(rt+1,r,dp+1);
}
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;i++)
			a[i]=read();
		solve(1,n,0);
		for(int i=1;i<=n;i++)
			cout<<d[i]<<" ";
		cout<<endl;
	}
	return 0;
}