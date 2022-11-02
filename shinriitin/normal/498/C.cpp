#include <queue>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int gint(){
	char c; int f=1;
	while(c=getchar(),c<48||c>57)
		if(c=='-')f=-1;
	int x=0;
	for(;c>47&&c<58;c=getchar()){
		x=x*10+c-48;
	}
	return x*f;
}

#define max_N 110
#define inf 0x7f7f7f7f

int n,m,u[max_N],v[max_N],a[max_N];

int p[max_N*30],cnt;

inline void divide(int x){
	if(~x&1){
		p[++cnt]=2;
		while(~x&1)x>>=1;
	}
	for(int i=3;i*i<=x;i+=2){
		if(x%i)continue;
		p[++cnt]=i;
		while(!(x%i))x/=i;
	}
	if(x>1)p[++cnt]=x;
}

struct edge{
	int v,c,f,n;
	edge(int v=0,int c=0,int f=0,int n=0):v(v),c(c),f(f),n(n){}
}e[max_N*10];

int head[max_N],tot;

inline void add_edge(int u,int v,int c){
	if(!c)return;
	e[++tot]=edge(v,c,0,head[u]),head[u]=tot;
	e[++tot]=edge(u,0,0,head[v]),head[v]=tot;
}

int d[max_N],cur[max_N];

bool vis[max_N];

queue<int>q;

inline bool bfs(int s,int t){
	for(int i=0;i<=n+1;++i)vis[i]=0,cur[i]=head[i];
	q.push(s),d[s]=0,vis[s]=1;
	while(!q.empty()){
		int x=q.front(); q.pop();
		for(int i=head[x],y;i;i=e[i].n){
			if(vis[y=e[i].v]||e[i].c<=e[i].f)continue;
			q.push(y),d[y]=d[x]+1,vis[y]=1;
		}
	}
	return vis[t];
}

int dfs(int x,int t,int a){
	if(x==t||!a)return a;
	int flow=0,f;
	for(int&i=cur[x],y;i;i=e[i].n){
		if(d[x]+1!=d[y=e[i].v])continue;
		if((f=dfs(y,t,min(a,e[i].c-e[i].f)))>0){
			flow+=f;
			e[i].f+=f,e[i^1].f-=f;
			if(!(a-=f))break;
		}
	}
	if(!flow)d[x]=n+2;
	return flow;
}

inline int Dinic(int s,int t){
	int flow=0;
	while(bfs(s,t))flow+=dfs(s,t,inf);
	return flow;
}

int idx[max_N],ans;

int main(){
	n=gint(),m=gint();
	for(int i=1;i<=n;++i)divide(a[i]=gint());
	sort(p+1,p+1+cnt);
	cnt=unique(p+1,p+1+cnt)-p-1;
	for(int i=1;i<=m;++i){
		u[i]=gint(),v[i]=gint();
		if(v[i]&1)swap(u[i],v[i]);
	}
	for(int i=1;i<=cnt;++i){
		for(int j=1,x;j<=n;++j){
			idx[j]=0;
			for(x=a[j];!(x%p[i]);++idx[j],x/=p[i]);
		}
		tot=1;
		for(int j=0;j<=n+1;++j)head[j]=0;
		for(int j=1;j<=m;++j)add_edge(u[j],v[j],inf);
		for(int j=1;j<=n;++j){
			if(j&1)add_edge(0,j,idx[j]);
			else add_edge(j,n+1,idx[j]);
		}
		ans+=Dinic(0,n+1);
	}
	return printf("%d\n",ans),0;
}