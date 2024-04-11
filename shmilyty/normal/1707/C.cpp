#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
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
int n,m,tot,fa[100001],pre[100001][21],d[100001],f[100001],used[200001];
array<int,2> e[200001];
std::vector<int> G[100001];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void dfs1(int x,int y)
{
	pre[x][0]=y;
	d[x]=d[y]+1;
	for(int i:G[x])
		if(i!=y)
			dfs1(i,x);
}
int lca(int x,int y)
{
	if(d[x]<d[y])
		swap(x,y);
	// cout<<d[x]<<" "<<d[y]<<endl;
	for(int i=20;~i;i--)
		if(d[y]+(1<<i)<=d[x])
			x=pre[x][i];
	if(x==y)
		return x;
	for(int i=20;~i;i--)
		if(pre[x][i]!=pre[y][i])
		{
			x=pre[x][i];
			y=pre[y][i];
		}
	return pre[x][0];
}
void dfs2(int x,int y)
{
	for(int i:G[x])
		if(i!=y)
		{
			f[i]+=f[x];
			dfs2(i,x);
		}
}
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		e[i]={x,y};
		if(find(x)==find(y))
			continue;
		used[i]=1;
		fa[find(x)]=find(y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs1(1,0);
	for(int i=1;i<=20;i++)
		for(int l=1;l<=n;l++)
			pre[l][i]=pre[pre[l][i-1]][i-1];
	for(int i=1;i<=m;i++)
		if(!used[i])
		{
			int lc=lca(e[i][0],e[i][1]);
			// cout<<e[i][0]<<" "<<e[i][1]<<" "<<lc<<endl;
			if(e[i][0]==lc)
			{
				f[1]++;
				f[e[i][1]]++;
				int x=e[i][1];
				for(int l=20;~l;l--)
					if(d[e[i][0]]+(1<<l)<d[x])
						x=pre[x][l];
				f[x]--;
			}
			elif(e[i][1]==lc)
			{
				f[1]++;
				f[e[i][0]]++;
				int x=e[i][0];
				for(int l=20;~l;l--)
					if(d[e[i][1]]+(1<<l)<d[x])
						x=pre[x][l];
				f[x]--;
			}
			else
			{
				f[e[i][0]]++;
				f[e[i][1]]++;
			}
		}
	dfs2(1,0);
	for(int i=1;i<=m;i++)
		if(!used[i])
			tot++;
	for(int i=1;i<=n;i++)
		if(f[i]==tot)
			cout<<1;
		else
			cout<<0;
	return 0;
}