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
int n,k,f=1,b=1,val,ans,a[201],vis[201],q[201];
vector<int> G[201];
void dfs(int x,int fa,int dis)
{
	if(dis>=k)
		return ;
	a[x]-=val;
	for(int i:G[x])
		if(i!=fa)
			dfs(i,x,dis+1);
}
signed main()
{
	n=read();
	k=read()+1;
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	q[1]=1;
	vis[1]=1;
	while(f<=b)
	{
		int x=q[f++];
		for(int i:G[x])
			if(!vis[i])
			{
				q[++b]=i;
				vis[i]=1;
			}
	}
	for(int i=n;i;i--)
		if(a[q[i]]>0)
		{
			val=a[q[i]];
			ans+=val;
			dfs(q[i],0,0);
		}
	cout<<ans;
	return 0;
}