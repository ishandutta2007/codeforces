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
int n,x,cnt,ans;
signed main()
{
	n=read();
	while(n--)
	{
		x=read();
		cnt+=x;
		ans=min(ans+x/2,cnt/3);
	}
	cout<<ans;
	return 0;
}