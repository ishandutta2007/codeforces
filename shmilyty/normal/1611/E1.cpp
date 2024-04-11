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
int t,n,k,d1[200001],d2[200001];
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
void solve()
{
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
	{
		d2[i]=INF;
		G[i].clear();
	}
	while(k--)
	{
		int x=read();
		d2[x]=0;
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
			puts("YES");
			return ;
		}
	puts("NO");
}
signed main()
{
	t=read();
	while(t--)
		solve();
	return 0;
}