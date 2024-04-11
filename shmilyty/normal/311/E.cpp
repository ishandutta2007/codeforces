#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=1e9;
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
}e[600001];
int n,m,g,s,t,res,cnt=-1,a[10001],head[12002],lev[12002],iter[12002];
void add(int x,int y,int v)
{ 
	e[++cnt]={y,head[x],v};
	head[x]=cnt;
	e[++cnt]={x,head[y],0};
	head[y]=cnt; 
}
void bfs(int x)
{
	queue<int> q;
	q.push(x);
	memset(lev,-1,sizeof(lev));
	lev[x]=0;
	while(!q.empty())
	{
		int f=q.front();
		q.pop();
		for(int i=head[f];~i;i=e[i].nxt)
			if(e[i].cap>0&&lev[e[i].to]<0)
			{
				lev[e[i].to]=lev[f]+1;
				q.push(e[i].to);
			}
	}
}
int dfs(int x,int y,int cnt)
{
	if(x==y)
		return cnt;
	for(int &i=iter[x];~i;i=e[i].nxt)
	{
		node &E=e[i];
		if(E.cap&&lev[x]<lev[E.to])
		{
			int d=dfs(E.to,y,min(cnt,E.cap));
			if(d)
			{
				E.cap-=d;
				e[i^1].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
int dinic()
{
	int ans=0;
	while(1)
	{
		bfs(s);
		if(lev[t]<0)
			return ans;
		for(int i=0;i<=t;i++)
			iter[i]=head[i];
		int f=0;
		while(f=dfs(s,t,INF))
			ans+=f;
	}
}
signed main()
{
	n=read();
	m=read();
	g=read();
	t=n+m+1;
	fill(head,head+t+1,-1);
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++)
	{
		int x=read();
		if(a[i])
			add(i,t,x);
		else
			add(s,i,x);	
	}
	for(int i=n+1;i<=n+m;i++)
	{
		int opt=read(),w=read(),k=read();
		res+=w;
		if(opt)
			while(k--)
				add(read(),i,INF);
		if(!opt)
			while(k--)
				add(i,read(),INF);
		w+=g*read();
		if(opt)
			add(i,t,w);
		else
			add(s,i,w);
	}
	cout<<res-dinic();
	return 0;
}