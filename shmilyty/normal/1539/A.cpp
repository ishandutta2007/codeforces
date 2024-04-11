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
int T,n,x,t,k;
signed main()
{
	T=read();
	while(T--)
	{
		n=read();
		x=read();
		t=read();
		k=t/x;
		if(n>=k)
			cout<<(n-k)*k+k*(k-1)/2<<endl;
		else
			cout<<n*(n-1)/2<<endl;
	}
	return 0;
}