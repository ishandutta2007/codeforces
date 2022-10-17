#include<bits/stdc++.h>
#define INF 0x7f7f7f7f
using namespace std;

namespace IO {
	const int S=(1<<20)+5;
	//Input Correlation
	char buf[S],*H,*T;
	inline char Get() {
		if(H==T) T=(H=buf)+fread(buf,1,S,stdin);
		if(H==T) return -1;
		return *H++;
	}
	inline int read() {
		int x=0;
		char c=Get();
		while(!isdigit(c)) c=Get();
		while(isdigit(c)) x=x*10+c-'0',c=Get();
		return x;
	}
	//Output Correlation
	char obuf[S],*oS=obuf,*oT=oS+S-1,c,qu[55];
	int qr;
	inline void flush() {
		fwrite(obuf,1,oS-obuf,stdout);
		oS=obuf;
	}
	inline void putc(char x) {
		*oS++ =x;
		if(oS==oT) flush();
	}
	template <class I>inline void print(I x) {
		if(!x) putc('0');
		if(x<0) putc('-'),x=-x;
		while(x) qu[++qr]=x%10+'0',x/=10;
		while(qr) putc(qu[qr--]);
		putc('\n');
	}
}
using namespace IO;

inline void upmin(int &x,const int &y) {
	if(y<x) x=y;
}

const int N=100010;
int val[N<<1],n,m,q,tot;
multiset<int> st[N];

namespace TCD {
	const int N=200010;
	struct Edge {
		int to,next;
	} e[N<<1];
	int h[N],sum=0;
	int fa[N],top[N],hson[N];
	int size[N],dep[N];
	int dfn[N],idx[N],clk=0;
	int mn[N<<2];

	void AddEdge(int u,int v) {
		e[++sum].to=v;
		e[sum].next=h[u];
		h[u]=sum;
	}
	void add_edge(int u,int v) {
		AddEdge(u,v);
		AddEdge(v,u);
	}

	void dfs1(int u,int la) {
		size[u]=1;
		int mx=0;
		for(int tmp=h[u]; tmp; tmp=e[tmp].next) {
			int v=e[tmp].to;
			if(v==la) continue;
			dep[v]=dep[u]+1;
			dfs1(v,u);
			fa[v]=u;
			size[u]+=size[v];
			if(size[v]>mx) mx=size[v],hson[u]=v;
		}
	}

	void dfs2(int u,int tp) {
		top[u]=tp;
		idx[dfn[u]=++clk]=u;
		if(hson[u]) dfs2(hson[u],tp);
		for(int tmp=h[u]; tmp; tmp=e[tmp].next)
			if(e[tmp].to!=fa[u]&&e[tmp].to!=hson[u])
				dfs2(e[tmp].to,e[tmp].to);
	}

	inline void maintain(int o) {
		mn[o]=min(mn[o<<1],mn[o<<1|1]);
	}

	void Build(int o,int l,int r) {
		if(l==r) {
			mn[o]=val[idx[l]];
			return;
		}
		int mid=(l+r)/2;
		Build(o<<1,l,mid);
		Build(o<<1|1,mid+1,r);
		maintain(o);
	}

	void Modify(int o,int l,int r,int k,int x) {
		if(l==r) {
			mn[o]=x;
			return;
		}
		int mid=(l+r)/2;
		if(k<=mid) Modify(o<<1,l,mid,k,x);
		else Modify(o<<1|1,mid+1,r,k,x);
		maintain(o);
	}

	int Query(int o,int l,int r,int nl,int nr) {
		if(l>=nl&&r<=nr) return mn[o];
		int mid=(l+r)/2,res=INF;
		if(nl<=mid) upmin(res,Query(o<<1,l,mid,nl,nr));
		if(nr>mid) upmin(res,Query(o<<1|1,mid+1,r,nl,nr));
		return res;
	}

	int PathQuery(int u,int v) {
		int res=INF;
		while(top[u]!=top[v]) {
			if(dep[top[u]]<dep[top[v]]) swap(u,v);
			upmin(res,Query(1,1,tot,dfn[top[u]],dfn[u]));
			u=fa[top[u]];
		}
		if(dep[u]>dep[v]) swap(u,v);
		upmin(res,Query(1,1,tot,dfn[u],dfn[v]));
		if(u>n) upmin(res,val[fa[u]]);
		return res;
	}
}

namespace Graph {
	struct Edge {
		int to,next;
	} e[N<<1];
	int h[N],sum=0;
	int pre[N],low[N],dfn=0;
	int bcc[N];
	stack<int> stk;

	void add_edge(int u,int v) {
		e[++sum].to=v;
		e[sum].next=h[u];
		h[u]=sum;
	}

	void Tarjan(int u) {
		pre[u]=low[u]=++dfn;
		stk.push(u);
		for(int tmp=h[u]; tmp; tmp=e[tmp].next) {
			int v=e[tmp].to;
			if(!pre[v]) {
				Tarjan(v);
				upmin(low[u],low[v]);
				if(low[v]>=pre[u]) {
					int o;
					tot++;
					do {
						o=stk.top();
						stk.pop();
						bcc[o]=tot;
						TCD::add_edge(o,tot);
					} while(o!=v);
					TCD::add_edge(u,tot);
				}
			} else upmin(low[u],pre[v]);
		}
	}
}

int main() {
	int u,v;
	tot=n=read();
	m=read();
	q=read();
	for(int i=1; i<=n; i++) val[i]=read();
	for(int i=1; i<=m; i++) {
		u=read();
		v=read();
		Graph::add_edge(u,v);
		Graph::add_edge(v,u);
	}
	for(int i=1;i<=n;i++){
		if(!Graph::pre[i]){
			Graph::Tarjan(i);
		}
	}
	TCD::dfs1(1,0);
	TCD::dfs2(1,1);
	for(int i=2;i<=n;i++){
		st[TCD::fa[i]-n].insert(val[i]);
	}
	for(int i=n+1;i<=tot;i++){
		val[i]=st[i-n].empty()?INF:(*st[i-n].begin());
	}
	TCD::Build(1,1,tot);
	while(q--){
		char opt=Get();
		while(opt!='C'&&opt!='A') opt=Get();
		u=read();
		v=read();
		if(opt=='C'){
			TCD::Modify(1,1,tot,TCD::dfn[u],v);
			if(u==1){
				val[u]=v;
				continue;
			}
			int o=TCD::fa[u];
			st[o-n].erase(st[o-n].find(val[u]));
			st[o-n].insert(v);
			int minv=*st[o-n].begin();
			if(minv==val[o]){
				val[u]=v;
				continue;
			}
			TCD::Modify(1,1,tot,TCD::dfn[o],minv);
			val[o]=minv;
			val[u]=v;
		}
		else{
			print(TCD::PathQuery(u,v));
		}
	}
	flush();
	return 0;
}