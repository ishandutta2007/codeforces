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
int n,sum,t;
void solve()
{
	n=read();
	sum=0;
	for(int i=1;i<=n;i++)
		sum+=read();
	if(sum==n)
		puts("0");
	if(sum<n)
		puts("1");
	if(sum>n)
		cout<<sum-n<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}