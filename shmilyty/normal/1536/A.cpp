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
int t,n,a[101];
map<int,int> vis;
void solve()
{
	n=read();
	bool muti=0; 
	vis.clear();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(vis[a[i]])
			muti=1;
		vis[a[i]]++;
	}
	sort(a+1,a+1+n);
	if(a[1]<0)
	{
		puts("No");
		return ;
	}
	int g=0,num=vis[0];
	for(int i=1;i<=n;i++)
		if(a[i]>0)
			g=__gcd(g,a[i]);
	if(vis[0]==0&&muti)
		num=1;
	for(int i=g;i<=a[n];i+=g)
		num+=max(1ll,vis[i]);
	if(num>300)
	{
		puts("No");
		return ;
	}
	puts("Yes");
	cout<<num<<endl;
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	if(vis[0]==0&&muti)
		cout<<0;
	for(int i=g;i<=a[n];i+=g)
		if(!vis[i])
			cout<<i<<" ";
	cout<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}