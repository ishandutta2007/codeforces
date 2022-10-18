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
	int to,nxt,v;
}e[200001];
struct que{
	int to,val;
	bool operator<(const que&x)const
	{
		return val>x.val;
	}
};
int n,m,cnt,q,used[100001],fa[100001],h[100001],dep[100001],vis[100001],f[21][100001],dis[51][100001];
array<int,3> a[100001];
vector<int> v;
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]); 
}
void add(int x,int y,int z)
{
	e[++cnt]={y,h[x],z};
	h[x]=cnt;
}
void build()
{
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
		if(find(a[i][0])!=find(a[i][1]))
		{
			fa[find(a[i][0])]=find(a[i][1]);
			add(a[i][0],a[i][1],a[i][2]);
			add(a[i][1],a[i][0],a[i][2]);
		}
		else
			v.push_back(i);
}
void dfs(int x,int pre)//dep[1]=1!!!
{
	f[0][x]=pre;
	for(int i=h[x];i;i=e[i].nxt)
		if(e[i].to!=pre)
		{
			dep[e[i].to]=dep[x]+1;
			dfs(e[i].to,x);
		}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])
		swap(x,y);
	for(int i=20;i>=0;i--)
		if(dep[f[i][x]]>=dep[y])
			x=f[i][x];
	if(x==y)
		return x;
	for(int i=20;i>=0;i--)
		if(f[i][x]!=f[i][y])
		{
			x=f[i][x];
			y=f[i][y];
		}
	return f[0][x];
}
void dijkstra(int id,int x)
{
	for(int i=1;i<=n;i++)
		dis[id][i]=INF;
	fill(vis+1,vis+1+n,0);
	dis[id][x]=0;
	priority_queue<que> q;
	q.push({x,0});
	while(!q.empty())
	{
		int f=q.top().to;
		q.pop();
		if(vis[f])
			continue;
		vis[f]=1;
		for(int i=h[f];i;i=e[i].nxt)
			if(dis[id][e[i].to]>dis[id][f]+e[i].v)
			{
				dis[id][e[i].to]=dis[id][f]+e[i].v;
				q.push({e[i].to,dis[id][e[i].to]});
			}
	}
}
signed main()
{
	n=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read(),z=read();
		a[i]={x,y,z};
	}
	build();
	dep[1]=1;
	dfs(1,0);
	for(int i=1;i<=20;i++)
		for(int l=1;l<=n;l++)
			f[i][l]=f[i-1][f[i-1][l]];
	dijkstra(0,1);
	for(int i:v)
	{
		add(a[i][0],a[i][1],a[i][2]);
		add(a[i][1],a[i][0],a[i][2]);
	}
	for(int i=0;i<v.size();i++)
	{
		dijkstra(i*2+1,a[v[i]][0]);
		dijkstra(i*2+2,a[v[i]][1]);
	}
	q=read();
	while(q--)
	{
		int x=read(),y=read();
		int z=lca(x,y);
		int ans=dis[0][x]+dis[0][y]-2*dis[0][z];
		for(int i=0;i<v.size();i++)
			ans=min({ans,dis[i*2+1][x]+dis[i*2+2][y]+a[v[i]][2],dis[i*2+1][y]+dis[i*2+2][x]+a[v[i]][2]});
		cout<<ans<<'\n';
	}
	return 0;
}