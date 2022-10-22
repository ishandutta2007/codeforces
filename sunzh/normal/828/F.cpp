#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) x=~x+1,putchar('-');
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,m;
int ans[200010];
PII edg[200010];
int len[200010];
bool tre[200010];
namespace tree{
	vector<PII>vec[200010];
	int maxn[800010],ano[800010],tag[800010];
	int siz[200010],son[200010],fa[200010],dfn[200010],top[200010],val[200010],dep[200010];
	int id;
	void add(int u,int v,int w){
		vec[u].pb(mp(v,w));vec[v].pb(mp(u,w));
	}
	void pushup(int p){
		maxn[p]=max(maxn[p<<1],maxn[p<<1|1]);
		ano[p]=min(ano[p<<1],ano[p<<1|1]);
	}
	void pushdown(int p){
		if(tag[p]!=-1){
			if(tag[p]<ano[p<<1]){
				ano[p<<1]=tag[p];
			}
			if(tag[p]<ano[p<<1|1]){
				ano[p<<1|1]=tag[p];
			}
			tag[p<<1]=(tag[p<<1]==-1?tag[p]:min(tag[p<<1],tag[p]));
			tag[p<<1|1]=(tag[p<<1|1]==-1?tag[p]:min(tag[p<<1|1],tag[p]));
			tag[p]=-1;
		}
	}
	void update(int p,int l,int r,int L,int R,int k){
		if(l>=L&&r<=R){
//		printf("p:%d,l:%d,r:%d,L:%d,R:%d,ano:%d\n",p,l,r,L,R,ano[p]);
			if(k<ano[p]){
//		printf("p:%d,l:%d,r:%d,L:%d,R:%d\n",p,l,r,L,R);
				ano[p]=k;
			}tag[p]=(tag[p]==-1?k:min(tag[p],k));
			return ;
		}
		pushdown(p);
		int mid=l+r>>1;
		if(L<=mid) update(p<<1,l,mid,L,R,k);
		if(R>mid) update(p<<1|1,mid+1,r,L,R,k);
		pushup(p);
	}
	int qano(int p,int l,int r,int L,int R){
		if(l>=L&&r<=R){
//		printf("p:%d,l:%d,r:%d,res:%d\n",p,l,r,ano[p]);
			return ano[p];
		}
		pushdown(p);
		pushup(p);
		int mid=l+r>>1;
		int res=0x3f3f3f3f;
		if(L<=mid) res=min(res,qano(p<<1,l,mid,L,R));
		if(R>mid) res=min(res,qano(p<<1|1,mid+1,r,L,R));
//		printf("p:%d,l:%d,r:%d,res:%d\n",p,l,r,res);
		return res;
	}
	void build(int p,int l,int r){
		tag[p]=-1;
		if(l==r){
//			printf("l:%d,val:%d\n",l,val[l]);
			maxn[p]=val[l];ano[p]=0x3f3f3f3f;return ;
		}
		int mid=l+r>>1;
		build(p<<1,l,mid);
		build(p<<1|1,mid+1,r);
		pushup(p);
	}
	int query(int p,int l,int r,int L,int R){
		if(l>=L&&r<=R) return maxn[p];
		int mid=l+r>>1;
		int res=0;
		if(L<=mid) res=max(res,query(p<<1,l,mid,L,R));
		if(R>mid) res=max(res,query(p<<1|1,mid+1,r,L,R));
		return res;
	}
	int Query(int u,int v){
//		printf("u:%d,v:%d\n",u,v);
		int res=0;
		while(top[u]!=top[v]){
			if(dep[top[u]]<dep[top[v]]) swap(u,v);
			res=max(res,query(1,1,id,dfn[top[u]],dfn[u]));
//			printf("u:%d,topu:%d,res:%d\n",u,top[u],res);
			u=fa[top[u]];
		}
		if(u==v) return res;
		if(dep[u]>dep[v]) swap(u,v);
		res=max(res,query(1,1,id,dfn[u]+1,dfn[v]));//printf("u:%d,v:%d,res:%d\n",u,v,res);
		return res;
	}
	void dfs1(int x,int f){ 
		fa[x]=f,dep[x]=dep[f]+1,siz[x]=1;
		for(auto i:vec[x]){
			int v=i.fi;
			if(v==f) continue ;
			dfs1(v,x);
			siz[x]+=siz[v];
			if(siz[v]>siz[son[x]]) son[x]=v;
		}
	}
	void dfs2(int x,int topf,int va){
		dfn[x]=++id;val[id]=va;top[x]=topf;
//		printf("x:%d,topf:%d,va:%d,fa:%d,dfn:%d\n",x,topf,va,fa[x],dfn[x]);
		if(!son[x]) return ;
		for(auto i:vec[x]){
			int v=i.fi;
			if(v==son[x]){
				dfs2(v,topf,i.se);
			}
		}
		for(auto i:vec[x]){
			int v=i.fi;
			if(v==fa[x]||v==son[x]) continue ;
			dfs2(v,v,i.se);
		}
	}
	void UPD(int x,int y,int k){
		while(top[x]!=top[y]){
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			update(1,1,id,dfn[top[x]],dfn[x],k);
//			printf("topx:%d,x:%d,k:%d\n",dfn[top[x]],dfn[x],k);
			x=fa[top[x]];
		}
		if(x==y) return ;
		if(dep[x]>dep[y]) swap(x,y);
//		printf("x:%d,y:%d,k:%d\n",dfn[x]+1,dfn[y],k);
		update(1,1,id,dfn[x]+1,dfn[y],k);
	}
	int another(int x,int y){
		if(dep[x]<dep[y]) swap(x,y);
		return qano(1,1,id,dfn[x],dfn[x]);
	}
	void solve(){
		memset(ano,0x3f,sizeof(ano));
		dfs1(1,0);
		dfs2(1,1,0);
		build(1,1,id);
	}
}
namespace MST{
	int cnt;
	int fa[200010];
	struct edge{
		int u,v,w,id;
	}e[200010];
	void add(int u,int v,int w,int id){
		e[++cnt]=edge{u,v,w,id};
	}
	bool cmp(edge x,edge y){
		return x.w<y.w;
	}
	int find(int x){
		if(fa[x]==x) return x;
		return fa[x]=find(fa[x]);
	}
	void kruskal(){
		int t=1;
		for(int i=1;i<=m;++i){
			int fx=find(e[i].u);
			int fy=find(e[i].v);
			if(fx==fy){
				continue ;
			}
			++t;tree::add(e[i].u,e[i].v,e[i].w);tre[e[i].id]=1;
			fa[fx]=fy;if(t==n) break ;
		}
	}
	void solve(){
		for(int i=1;i<=n;++i) fa[i]=i;
		sort(e+1,e+m+1,cmp);
		kruskal();
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		edg[i].fi=u,edg[i].se=v,len[i]=w;
		MST::add(u,v,w,i);
	}
	MST::solve();
//	for(int i=1;i<=m;++i) if(tre[i]) printf("ww:%d\n",len[i]);
	tree::solve();
	for(int i=1;i<=m;++i){
		if(!tre[i]){
//			printf("\n\nu:%d,v:%d,w:%d\n",edg[i].fi,edg[i].se);
			tree::UPD(edg[i].fi,edg[i].se,len[i]);
		}
	}
	for(int i=1;i<=m;++i){
//		if(i!=19) continue ;
		if(ans[i]==-1) continue ;
		if(tre[i]){
			ans[i]=tree::another(edg[i].fi,edg[i].se)-1;
			if(ans[i]>0x3f3f3f15) ans[i]=-1;continue ;
		}
		int maxn=tree::Query(edg[i].fi,edg[i].se);
		ans[i]=maxn-1;
	}
	for(int i=1;i<=m;++i) print(ans[i]),putchar(' ');
	return 0;
}