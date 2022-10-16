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
int t,n,ans,num,fa[400001],x[400001];
const int mod=1e9+7;
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void solve()
{
	n=read();
	num=0;
	ans=1;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=n;i++)
		x[i]=read();
	for(int i=1;i<=n;i++)
	{
		int y=read();
		if(y==x[i])
			num--;
		fa[find(y)]=find(x[i]);
	}
	for(int i=1;i<=n;i++)
		if(fa[i]==i)
			num++;
	while(num--)
		(ans*=2)%=mod;
	cout<<ans<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}