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
int n,q,cnt,dfn[200010],sz[200010],dep[200010],pre[200010][20],t[30][200010],f[30][200010];
std::vector<int> G[200010];
void dfs(int x,int fa)
{
	dfn[x]=++cnt;
	sz[x]=1;
	dep[x]=dep[fa]+1;
	pre[x][0]=fa;
	for(int i:G[x])
		if(i!=fa)
		{
			dfs(i,x);
			sz[x]+=sz[i];
		}
}
void modify(int id,int x,int y)
{
	for(;x<=n;x+=lowbit(x))
		t[id][x]+=y;
}
int query(int id,int x)
{
	int y=0;
	for(;x;x^=lowbit(x))
		y+=t[id][x];
	return y;
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])
		swap(x,y);
	for(int i=19;~i;i--)
		if(dep[x]-(1<<i)>=dep[y])
			x=pre[x][i];
	if(x==y)
		return x;
	for(int i=19;~i;i--)
		if(pre[x][i]!=pre[y][i])
		{
			x=pre[x][i];
			y=pre[y][i];
		}
	return pre[x][0];
}
signed main()
{
	n=read();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1,0);
	for(int i=1;i<20;i++)
		for(int l=1;l<=n;l++)
			pre[l][i]=pre[pre[l][i-1]][i-1];
	q=read();
	while(q--)
	{
		int opt=read();
		if(opt&1)
		{
			int x=read(),ans=0;
			for(int i=0;x&&i<=20;i++)
			{
				ans+=f[i][x]+query(i,dfn[x]+sz[x]-1)-query(i,dfn[x]-1);
				x=pre[x][0];
			}
			cout<<ans<<'\n';
		}
		else
		{
			int x=read(),y=read(),k=read(),d=read();
			int z=lca(x,y);
			modify(d,dfn[x],k);
			modify(d,dfn[y],k);
			modify(d,dfn[z],-2*k);
			for(int i=d;i>=0;i--)
			{
				f[i][z]+=k;
				if(i)
					f[i-1][z]+=k;
				if(z==1)
				{
					for(i-=2;i>=0;i--)
						f[i][z]+=k;
					break;
				}
				else
					z=pre[z][0];
			}
		}
	}
	return 0;
}