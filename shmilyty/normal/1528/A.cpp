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
int t,n,ans1,ans,l[100001],r[100001],f[100001][2];
vector<int> adj[100001];
void dfs(int x,int fa)
{
	f[x][0]=f[x][1]=0;
	for(int i:adj[x])
		if(i!=fa)
		{
			dfs(i,x);
			f[x][0]+=max(f[i][0]+abs(l[i]-l[x]),f[i][1]+abs(r[i]-l[x]));
			f[x][1]+=max(f[i][0]+abs(l[i]-r[x]),f[i][1]+abs(r[i]-r[x]));
		}
}
void solve()
{
	n=read();
	ans1=ans=0;
	for(int i=1;i<=n;i++)
	{
		l[i]=read();
		r[i]=read();
		adj[i].clear();
	}
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1,0);
	cout<<max(f[1][0],f[1][1])<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}