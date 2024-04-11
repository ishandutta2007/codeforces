#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
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
int n;
signed main()
{
	n=read();
	if(n&1)
	{
		for(int i=2;i<n;i+=2)
			cout<<i<<" ";
		for(int i=n-1;i>=2;i-=2)
			cout<<i<<" ";
		for(int i=1;i<=n;i+=2)
			cout<<i<<" ";
		for(int i=n-2;i>=1;i-=2)
			cout<<i<<" ";
		cout<<n;
	}
	else
	{
		for(int i=1;i<n;i+=2)
			cout<<i<<" ";
		for(int i=n-1;i>=1;i-=2)
			cout<<i<<" ";
		for(int i=2;i<=n;i+=2)
			cout<<i<<" ";
		for(int i=n-2;i>=2;i-=2)
			cout<<i<<" ";
		cout<<n;
	}
	return 0;
}