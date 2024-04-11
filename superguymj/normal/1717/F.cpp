#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
const int N=20005,INF=1000000000;
typedef long long LL;
LL ans;
bool vis[N];
int n,m,g[N],S[N],s,t,q[N],head,tail,dis[N];
int a[N],h[N],cnt,cur[N],d[N],u[N],v[N];
struct edge{int v,f,n;} e[N*20];
struct D{int u,v;} dat[N];

int getint()
{
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

void addedge(int u,int v,int f)
{
	e[cnt]=(edge){v,f,h[u]},h[u]=cnt++;
	e[cnt]=(edge){u,0,h[v]},h[v]=cnt++;
}

void bfs(int t)
{
	g[0]=0;
	rep(i,1,t) vis[i]=g[i]=0,dis[i]=t;
	vis[q[head=tail=0]=t]=1,dis[t]=0;
	while(head<=tail)
	{
		int x=q[head++];
		for(int i=h[x]; i!=-1; i=e[i].n)
			if(e[i^1].f && !vis[e[i].v])
			{
				dis[e[i].v]=dis[x]+1;
				vis[q[++tail]=e[i].v]=1;
			}
	}
	rep(i,1,t) ++g[dis[i]];
}

int isap(int x,int rt)
{
	if(x==t) return rt;
	int sum=0;
	for(int i=cur[x]; i!=-1; i=e[i].n)
		if(e[i].f && dis[x]==dis[e[i].v]+1)
		{
			int f=isap(e[i].v,min(rt-sum,e[i].f));
			e[i].f-=f,e[i^1].f+=f,sum+=f;
			if(sum==rt || dis[s]>=t) return sum;
		}
	if(!(--g[dis[x]])) dis[s]=t;
	++dis[x],++g[dis[x]],cur[x]=h[x];
	return sum;
}

int main()
{
	n=getint(),m=getint();
	memset(h,-1,sizeof(h));
	rep(i,1,n) S[i]=getint();
	rep(i,1,n) a[i]=getint();
	rep(i,1,m)
	{
		dat[i].u=getint(),dat[i].v=getint();
		++d[dat[i].u],++d[dat[i].v];
	}
	s=n+m+1,t=s+1;
	rep(i,1,n) if(S[i])
	{
		if((d[i]+a[i])&1)
		{
			puts("NO");
			return 0;
		}
		int x=(d[i]+a[i])/2;
		addedge(m+i,t,x),ans+=x;
	}
	rep(i,1,m) addedge(s,i,1);
	rep(i,1,m)
	{
		u[i]=cnt,addedge(i,m+dat[i].u,1);
		v[i]=cnt,addedge(i,m+dat[i].v,1);
	}
	memcpy(cur,h,sizeof(h));
	for(; dis[s]<t; )
	{
		bfs(t);
		ans-=isap(s,INF);
	}
	if(ans) puts("NO");
	else
	{
		rep(i,1,m)
		{
			if(!e[u[i]].f) swap(dat[i].u,dat[i].v);
			else if(e[v[i]].f)
			{
				if(S[dat[i].u] && S[dat[i].v])
				{
					puts("NO");
					return 0;
				}
				if(S[dat[i].v]) swap(dat[i].u,dat[i].v);
			}
		}
		puts("YES");
		rep(i,1,m) printf("%d %d\n",dat[i].u,dat[i].v);
	}
	return 0;
}