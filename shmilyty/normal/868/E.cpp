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
struct node{
	int to,nxt,val;
}edge[101];
int n,m,s,cnt=1,ans,a[51],d[51],head[51],f[101][51][51];
void dfs(int x,int fa)
{
	for(int i=head[x];i;i=edge[i].nxt)
		if(edge[i].to^fa)
		{
			dfs(edge[i].to,x);
			a[x]+=a[edge[i].to];
		}
}
void add(int x,int y,int z)
{
	edge[++cnt].to=y;
	edge[cnt].val=z;
	edge[cnt].nxt=head[x];
	head[x]=cnt;
	edge[++cnt].to=x;
	edge[cnt].val=z;
	edge[cnt].nxt=head[y];
	head[y]=cnt;
	d[x]++;
	d[y]++;
}
int solve(int Edge,int x,int y)
{
	if(x==0&&y==0)
		return 0;
	if(~f[Edge][x][y])
		return f[Edge][x][y];
	int to=edge[Edge].to;
	if(d[to]==1)
	{
		if(y==0)
			return 0;
		return f[Edge][x][y]=(solve(Edge^1,y,0)+edge[Edge].val);
	}
	int g[51];
	memset(g,0,sizeof(g));
	g[0]=INF;
	for(int i=head[to];i;i=edge[i].nxt)
		if((i^1)!=Edge)
			for(int l=x;l;l--)
				for(int j=l;j;j--)
					g[l]=max(g[l],min(g[l-j],solve(i,j,x+y-j)+edge[i].val));
	return f[Edge][x][y]=g[x]; 
}
signed main()
{
	n=read();
	for(int i=1;i<=n*2-2;i+=2)
	{
		int x=read(),y=read(),z=read();
		add(x,y,z);
	}
	s=read();
	m=read();
	for(int i=1;i<=m;i++)
		a[read()]++;
	dfs(s,0);
	memset(f,-1,sizeof(f));
	ans=INF;
	for(int i=head[s];i;i=edge[i].nxt)
		ans=min(ans,solve(i,a[edge[i].to],m-a[edge[i].to])+edge[i].val);
	cout<<ans;
	return 0;
}