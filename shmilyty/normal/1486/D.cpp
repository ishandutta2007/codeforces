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
int n,k,l=114514114514114514,r,a[400001],b[200001],c[200001];
int lowbit(int x)
{
	return x&-x;
}
void add(int x,int y)
{
	while(x<=400000)
	{
		a[x]+=y;
		x+=x^(x&(x-1));
	}
}
int ask(int x)
{
	int ans=0;
	while(x)
	{
		ans+=a[x];
		x&=x-1;
	}
	return ans;
}
bool check(int x)
{
	for(int i=1;i<=n;i++)
		if(b[i]>=x)
			c[i]=c[i-1]+1;
		else
			c[i]=c[i-1]-1;
	memset(a,0,sizeof(a));
	for(int i=k;i<=n;i++)
	{	
		add(c[i-k]+200000,1);
		if(ask(c[i]+200000-1))
			return 1;
	}
	return 0; 
}
signed main()
{
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
	{
		b[i]=read();
		l=min(l,b[i]);
		r=max(r,b[i]);
	}
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
			l=mid+1;
		else
			r=mid-1;
	}
	cout<<l-1;
	return 0;
}