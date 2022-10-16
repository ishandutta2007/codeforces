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
int t,n,k,maxx,lst,p[101],dep[101];
vector<int> adj[101];
void g(int x)
{
	cout<<x<<" ";
	for(int i:adj[x])
		if(k)
		{
			k--;
			g(i);
			cout<<x<<" ";
		}
}
void f(int x,int y)
{
	if(x!=1)
		f(p[x],x);
	cout<<x<<" "; 
	for(int i:adj[x])
		if(x!=y&&i!=y&&k)
		{
			k--;
			g(i);
			cout<<x<<" ";
		}
}
void solve()
{
	n=read();
	k=read();
	maxx=0,lst=1;
	for(int i=1;i<=n;i++)
		adj[i].clear();
	for(int i=2;i<=n;i++)
	{
		p[i]=read();
		adj[p[i]].push_back(i);
		dep[i]=dep[p[i]]+1;
		if(dep[i]<k&&dep[i]>maxx)
		{
			maxx=dep[i];
			lst=i;
		}
	}
	cout<<2*(k-1)-maxx<<endl;
	k-=maxx+1;
	f(lst,lst);
	cout<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}