#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
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
int t,n,k,top,ans,stk[200001],v1[200001],v2[200001],d1[200001],d2[200001];
vector<int> G[200001];
queue<int> q;
void dfs(int x,int fa)
{
	for(int i:G[x])
		if(i!=fa)
		{
			d1[i]=d1[x]+1;
			dfs(i,x);
		}
}
void dfs1(int x,int fa)
{
	stk[++top]=x;
	if(v1[x])
		v2[stk[top/2+1]]=1;
	for(int i:G[x])
		if(i!=fa)
			dfs1(i,x);
	top--;
}
void dfs2(int x,int fa)
{
	if(v2[x])
	{
		ans++;
		return ;
	}
	for(int i:G[x])
		if(i!=fa)
			dfs2(i,x);
}
void solve()
{
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
	{
		G[i].clear();
		d2[i]=INF;
		v1[i]=v2[i]=0;
	}
	while(k--)
	{
		int x=read();
		d2[x]=0;
		v1[x]=1;
		q.push(x);
	}
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1,0);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i:G[x])
			if(d2[i]>d2[x]+1)
			{
				d2[i]=d2[x]+1;
				q.push(i);
			}
	}
	for(int i=2;i<=n;i++)
		if(G[i].size()==1&&d1[i]<d2[i])
		{
			puts("-1");
			return ;
		}
	top=0;
	dfs1(1,0);
	ans=0;
	dfs2(1,0);
	cout<<ans<<endl;
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}