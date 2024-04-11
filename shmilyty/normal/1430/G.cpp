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
const int INF=(1ll<<60),inf=4e11;
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
	int to,nxt,cap;
}e[100001];
int n,m,s,t,cnt=-1,tot,v[20],h[401],pre[401],lev[401],vis[401],id[20][20];
queue<int> q;
void add(int x,int y,int z)
{
	e[++cnt]={y,h[x],z};
	h[x]=cnt;
}
void bfs()
{
	fill(lev+1,lev+tot+1,-1);
	lev[s]=0;
	q.push(s);
	while(!q.empty())
	{
		int f=q.front();
		q.pop();
		for(int i=h[f];~i;i=e[i].nxt)
			if(lev[e[i].to]==-1&&e[i].cap)
			{
				lev[e[i].to]=lev[f]+1;
				q.push(e[i].to);
			}
	}
}
int dfs(int x,int y,int cur)
{
	if(x==y)
		return cur;
	for(int &i=pre[x];~i;i=e[i].nxt)
	{
		node &T=e[i];
		if(lev[T.to]>lev[x]&&T.cap)
		{
			int f=dfs(T.to,y,min(cur,T.cap));
			if(f)
			{
				T.cap-=f;
				e[i^1].cap+=f;
				return f;
			}
		}	
	}
	return 0;
}
void dfs2(int x)
{
	vis[x]=1;
	for(int i=h[x];~i;i=e[i].nxt)
		if(!vis[e[i].to]&&e[i].cap)
			dfs2(e[i].to);
}
void flow()
{
	while(1)
	{
		bfs();
		if(lev[t]==-1)
			return ;
		for(int i=1;i<=tot;i++)
			pre[i]=h[i];
		while(dfs(s,t,INF));
	}
}
signed main()
{
	memset(h,-1,sizeof(h));
	n=read();
	m=read();
	s=++tot;
	t=++tot;
	for(int i=1;i<=n;i++)
		for(int l=0;l<=n;l++)
			id[i][l]=++tot;
	while(m--)
	{
		int x=read(),y=read(),z=read();
		v[x]+=z;
		v[y]-=z;
		for(int i=0;i<n;i++)
		{
			add(id[y][i],id[x][i+1],INF);
			add(id[x][i+1],id[y][i],0);
		}
	}
	for(int i=1;i<=n;i++)
	{
		add(s,id[i][0],INF);
		add(id[i][0],s,0);
		add(id[i][n],t,INF);
		add(t,id[i][n],0);
		for(int l=0;l<n;l++)
		{
			add(id[i][l],id[i][l+1],v[i]*l+inf);
			add(id[i][l+1],id[i][l],0);
		}
	}
	flow();
	dfs2(s);
	for(int i=1;i<=n;i++)
	{
		int ans=0;
		for(int l=0;l<=n;l++)
			if(vis[id[i][l]])
				ans=l;
		cout<<ans<<" ";
	}
	return 0;
}