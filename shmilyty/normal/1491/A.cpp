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
int n,q,sum,a[100001];
signed main()
{
	n=read();
	q=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		sum+=a[i];
	}
	while(q--)
	{
		int x=read(),y=read();
		if(x==1)
		{
			sum+=1-2*a[y];
			a[y]^=1;
		}
		else
			cout<<(sum<y?0:1)<<endl;
	}
	return 0;
}