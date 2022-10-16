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
const int mod=998244353;
int n,d[1000001],ans,x;
signed main()
{
	n=read();
	x=ans=1;
	for(int i=1;i<=1000000;i++)
		for(int j=1;i*j<=1000000;j++)
			d[i*j]++;
	for(int i=2;i<=n;i++)
	{
		x=(ans+d[i])%mod;
		(ans+=x)%=mod;
	}
	cout<<x;
	return 0;
}