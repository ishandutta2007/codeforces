#include<bits/stdc++.h>
#define rep for(int s,i=lk[x];i;i=hd[i])
const int N=300005;
using namespace std;
int n,m,q,qn,st[N],f[N],lst,
sz[N],top[N],son[N],dep[N],t,
a[N],b[N*3],tot;
struct G{
	int to[N*4],hd[N*4],lk[N],cnt=1,
	dfn[N],low[N],scn,scc[N];
	inline void add(int u,int v){
		to[++cnt]=v,hd[cnt]=lk[u],lk[u]=cnt;
	}
	inline void Add(int u,int v){
		if(u&&v)add(u,v),add(v,u);
	}
	void dfs(int x,int y){
		if(dfn[x])return;
		dfn[x]=low[x]=++cnt,st[++t]=x;
		rep if(i^y)
		dfs(s=to[i],i^1),
		low[x]=min(low[x],low[s]);
		if(dfn[x]==low[x])
		for(scn++;scc[st[t]]=scn,st[t--]^x;);
	}
	void dfs(int x){
		sz[x]=1,dep[x]=dep[f[x]]+1,dfn[x]=++cnt;
		rep if(f[x]^(s=to[i]))
		f[s]=x,dfs(s),sz[x]+=sz[s],
		sz[son[x]]<sz[s]?son[x]=s:0;
	}
	void clr(int x){
		if(!dfn[x])return;
		dfn[x]=0;
		rep clr(to[i]);
		lk[x]=0;
	}
	void dfss(int x){
		!top[x]?top[x]=x:0;
		top[son[x]]=top[x];
		rep if(f[s=to[i]]==x)dfss(s);
	}
	void trans();
}I,T,Q;
void G::trans(){
	for(int x=1;x<=n;x++)
	for(int i=lk[x];i;i=hd[i])
	if(scc[to[i]]^scc[x])
	T.add(scc[to[i]],scc[x]);
}
bool cmp(int x,int y){
	return T.dfn[x]<T.dfn[y];
}
inline int lca(int u,int v){
	for(;top[u]^top[v];u=f[top[u]])
	if(dep[top[u]]<dep[top[v]])swap(u,v);
	return dep[u]<dep[v]?u:v;
}
inline void rd(int&x){
	scanf("%d",&x),x=(x+n+lst-1)%n+1;
	b[tot++]=x=I.scc[x];
}
int u,v,w;
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(;m--;)
	scanf("%d%d",&u,&v),I.Add(u,v);
	for(int i=1;i<=n;i++)I.dfs(i,0);
	I.trans();
	for(int i=1;i<=I.scn;i++)
	if(!T.dfn[i])T.dfs(i),T.dfss(i);
	top[0]=0;
	for(int al=1;al<=q;al++){
		scanf("%d%d",&qn,&m);
		tot=0,Q.cnt=1;
		for(int i=0;i<qn;i++)rd(a[i]);
		for(;m--;)rd(u),rd(v),Q.Add(u,v);
		sort(b,b+tot,cmp);
		for(int i=0;i<tot;i++){
			w=lca(u=b[i],v=st[t]);
			for(v=0;dep[st[t]]>dep[w];v=st[t--])
			if(v)Q.Add(v,st[t]);
			if(v)Q.Add(v,w);
			if(st[t]^w)st[++t]=w;
			if(u^w)st[++t]=u;
		}
		for(;t;t--)
		Q.Add(st[t],st[t-1]);
		for(int i=0;i<tot;i++)Q.dfs(b[i],0);
		for(int i=0;i<tot;i++)Q.clr(b[i]);
		v=Q.scc[a[0]],u=1;
		for(int i=1;i<qn;i++)
		if(Q.scc[a[i]]^v)u=0;
		if(u)puts("YES"),lst=(lst+al)%n;
		else puts("NO");
	}
}