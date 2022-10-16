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
int t,n,l,r,nr[200001],nl[200001],nowl[200001],nowr[200001];
void solve()
{
	n=read();
	l=read();
	r=read();
	for(int i=1;i<=n;i++)
		nl[i]=nr[i]=nowl[i]=nowr[i]=0;
	for(int i=1;i<=l;i++)
		nl[read()]++;
	for(int i=1;i<=r;i++)
		nr[read()]++;
	int ans=0,a=0,b=0;
	for(int i=1;i<=n;i++)
	{
		int x=min(nr[i],nl[i]);
		nr[i]-=x;
		nl[i]-=x;
		a+=nl[i];
		b+=nr[i];
	}
	if(a<b)
	{
		int rest=b-a;
		ans+=a;
		for(int i=1;i<=n;i++)
		{
			if(nr[i]/2*2<=rest)
			{
				rest-=nr[i]/2*2;
				nowr[i]=nr[i]/2*2;
			}
			else
			{
				nowr[i]=rest;
				rest=0;
			}
		}
		for(int i=1;i<=n;i++)
			if(rest&&nr[i]&1)
			{
				nowr[i]++;
				rest--;
			}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			ans+=nowr[i]/2;
			cnt+=nowr[i]%2;
		}
		ans+=cnt;
	}
	else
	{
		int rest=a-b;
		ans+=b;
		for(int i=1;i<=n;i++)
		{
			if(nl[i]/2*2<=rest)
			{
				rest-=nl[i]/2*2;
				nowl[i]=nl[i]/2*2;
			}
			else
			{
				nowl[i]=rest;
				rest=0;
			}
		}
		for(int i=1;i<=n;i++)
			if(rest&&nl[i]&1)
			{
				nowl[i]++;
				rest--;
			}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			ans+=nowl[i]/2;
			cnt+=nowl[i]%2;
		}
		ans+=cnt;
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