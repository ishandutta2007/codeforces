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
struct node{
	int to,nxt,cap,val; 
}edge[5001];
int n,m,s,t,q,cnt=-1,flow,cost,head[51],dis[51],vis[51],from[51];
vector<array<int,2>> v;
void add(int x,int y,int z,int w)
{
	edge[++cnt]={y,head[x],z,w};
	head[x]=cnt;
	edge[++cnt]={x,head[y],0,-w};
	head[y]=cnt;
}
void spfa()
{
	fill(dis+1,dis+1+n,INF);
	fill(vis+1,vis+1+n,0);
	queue<int> q;
	q.push(s);
	vis[s]=1;
	dis[s]=0;
	while(!q.empty())
	{
		int f=q.front();
		q.pop();
		vis[f]=0;
		for(int i=head[f];~i;i=edge[i].nxt)
			if(edge[i].cap>0&&dis[edge[i].to]>dis[f]+edge[i].val)
			{
				dis[edge[i].to]=dis[f]+edge[i].val;
				from[edge[i].to]=i;
				if(!vis[edge[i].to])
				{
					vis[edge[i].to]=1;
					q.push(edge[i].to);
				}
			}
	}
}
void EK()
{
	while(1)
	{
		spfa();
		if(dis[t]==INF)
			return ;
		int x=INF;
		for(int i=t;i!=s;i=edge[from[i]^1].to)
			x=min(x,edge[from[i]].cap);
		flow+=x;
		for(int i=t;i!=s;i=edge[from[i]^1].to)
		{
			edge[from[i]^1].cap+=x;
			edge[from[i]].cap-=x;
			cost+=x*edge[from[i]].val;
		}
		v.push_back({flow,cost});
	}
}
signed main()
{
	s=1;
	t=n=read();
	m=read();
	for(int i=1;i<=n;i++)
		head[i]=-1;
	while(m--)
	{
		int x=read(),y=read(),z=read();
		add(x,y,1,z);
	}
	EK();
	q=read();
	while(q--)
	{
		int x=read();
		double ans=INF;
		for(auto i:v)
			ans=min(ans,1.0*(i[1]+x)/i[0]);
		printf("%.10f\n",ans);
	}
	return 0;
}