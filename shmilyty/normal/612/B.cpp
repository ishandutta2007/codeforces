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
int n,ans,a[200001],b[200001];
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		b[read()]=i;
	for(int i=1;i<n;i++)
		ans+=abs(b[i+1]-b[i]);
	cout<<ans;
	return 0;
}