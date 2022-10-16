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
int n,sum,a[2001],f[200001];
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		sum+=a[i];	
	}
	f[0]=1;
	for(int i=1;i<=n;i++)
		for(int l=sum-a[i];l>=0;l--)
			f[l+a[i]]+=f[l];
	if(sum&1||!f[sum/2])
	{
		puts("0");
		return 0;	
	}	
	int g=0,num=1;
	for(int i=1;i<=n;i++)
		g=__gcd(g,a[i]);
	while(g%2==0)
	{
		num*=2;
		g/=2;
	}
	for(int i=1;i<=n;i++)
	{
		a[i]/=num;
		if(a[i]&1)
		{
			cout<<1<<endl<<i<<endl;
			return 0;
		}
	}
	return 0;
}