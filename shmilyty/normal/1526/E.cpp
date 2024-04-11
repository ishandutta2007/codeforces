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
int mod=998244353;
int n,k,cnt,a[200001],b[200001],c[500001];
int qp(int x,int y)
{
	if(x==1)
		return 1;
	if(x==0)
		return 0;
	if(y==0)
		return 1;
	if(y==1)
		return x;
	int ans=qp(x,y/2);
	(ans*=ans)%=mod;
	if(y&1)
		(ans*=x)%=mod;
	return ans;
}
int C(int x,int y)
{
	c[0]=1;
	for(int i=1;i<=x;i++)
		c[i]=(c[i-1]*i)%mod;
	int ans=c[x];
	return ans*qp(c[x-y],mod-2)%mod*qp(c[y],mod-2)%mod;
}
signed main()
{
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		b[a[i]]=i;
	}
	for(int i=1;i<n;i++)
	{
		int x=a[i],y=a[i+1];
		if(b[x+1]>b[y+1])
			cnt++;
	}
	cout<<C(n+k-cnt-1,n);
	return 0;
}