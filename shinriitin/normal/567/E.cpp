#include <map>
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

#define max_N 200005
#define inf (1ll<<40)
typedef long long ll;
typedef pair<ll,int>pli;

struct edge{
	int v,w,n;
	edge(int v=0,int w=0,int n=0):v(v),w(w),n(n){}
}e[max_N];

int head[max_N],tot;

inline void add_edge(int u,int v,int w){
	e[++tot]=edge(v,w,head[u]),head[u]=tot;
}

int n,m,s,t,u[max_N],v[max_N];

ll d[2][max_N],w[max_N];

bool vis[max_N];

priority_queue<pli,vector<pli>,greater<pli> >q;

inline void dj(int s,ll*d){
	for(int i=1;i<=n;++i)vis[i]=0,d[i]=inf;
	d[s]=0; q.push(pli(0,s));
	while(!q.empty()){
		int x=q.top().second; q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x],y;i;i=e[i].n){
			if(vis[y=e[i].v])continue;
			if(d[y]>d[x]+e[i].w){
				d[y]=d[x]+e[i].w;
				q.push(pli(d[y],y));
			}
		}
	}
}

struct Edge{
	int v,id,n;
	Edge(int v=0,int id=0,int n=0):v(v),id(id),n(n){}
}E[max_N];

int Head[max_N],Tot;

inline Add_Edge(int u,int v,int id){
	E[++Tot]=Edge(v,id,Head[u]),Head[u]=Tot;
}

int dfn[max_N],low[max_N],cnt;

bool bridge[max_N];

void dfs(int x,int p){
	dfn[x]=low[x]=++cnt;
	for(int i=Head[x],y;i;i=E[i].n){
		if((y=E[i].v)==p)continue;
		if(dfn[y]){
			low[x]=min(low[x],dfn[y]);
		}
		else{
			dfs(y,x);
			low[x]=min(low[x],low[y]);
			if(low[y]>dfn[x])bridge[E[i].id]=1;
		}
	}
}

map<pair<pair<int,int>,int>,int>S;

int main(){
	n=gint(),m=gint(),s=gint(),t=gint();
	for(int i=1;i<=m;++i){
		u[i]=gint(),v[i]=gint(),w[i]=gint();
		add_edge(u[i],v[i],w[i]);
	}
	dj(s,d[0]);
	tot=0;
	for(int i=1;i<=n;++i)head[i]=0;
	for(int i=1;i<=m;++i)add_edge(v[i],u[i],w[i]);
	dj(t,d[1]);
	for(int i=1;i<=m;++i)if(d[0][t]==d[0][u[i]]+w[i]+d[1][v[i]]){
		Add_Edge(u[i],v[i],i),Add_Edge(v[i],u[i],i);
	}
	dfs(s,0);
	for(int i=1;i<=m;++i)++S[make_pair(make_pair(u[i],v[i]),w[i])];
	for(int i=1;i<=m;++i){
		if(S[make_pair(make_pair(u[i],v[i]),w[i])]==1&&bridge[i])puts("YES");
		else{
			if(d[0][u[i]]==inf||d[1][v[i]==inf]){
				puts("NO"); continue;
			}
			ll ans=d[0][t]-d[0][u[i]]-d[1][v[i]]-1;
			if(ans<=0)puts("NO");
			else printf("CAN %d\n",w[i]-ans);
		}
	}
	return 0;
}