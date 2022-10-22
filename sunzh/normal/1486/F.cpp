#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<random>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
int n,m;
vector<int>vec[300010];
int fa[300010],dep[300010];
int siz[300010],son[300010];
int top[300010],dfn[300010];
map<int,int>Map[300010];
vector<int>cnt[300010];
void dfs1(int x,int f){
	fa[x]=f,dep[x]=dep[f]+1;
	siz[x]=1;
	for(int v:vec[x]){
		if(v==f) continue ;
		dfs1(v,x);
		if(siz[son[x]]<siz[v]) son[x]=v;siz[x]+=siz[v];
	}
	for(int i=0;i<vec[x].size();++i){
		Map[x][vec[x][i]]=i;
	}
	cnt[x].assign(vec[x].size()+1,0);
}
int idx;
void dfs2(int x,int tf) {
	dfn[x]=++idx;top[x]=tf;
	if(son[x]){
		dfs2(son[x],tf);
	}
	else return ;
	for(int v:vec[x]){
		if(v==fa[x]||v==son[x]) continue ;
		dfs2(v,v);
	}
}
int LCA(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		u=fa[top[u]];
	}
	return dep[u]>dep[v]?v:u;
}
struct sgt{
	long long sum[2000010],tag[2000010];
	void pushup(int p,int l,int r){
		sum[p]=sum[p<<1]+sum[p<<1|1]+tag[p]*(r-l+1); 
	}
	void update(int p,int l,int r,int L,int R){
		if(L>R) return ;
		if(l>=L&&r<=R){
			++tag[p];sum[p]+=r-l+1;
			return ;
		}
		int mid=l+r>>1;
		if(L<=mid) update(p<<1,l,mid,L,R);
		if(R>mid) update(p<<1|1,mid+1,r,L,R);
		pushup(p,l,r);
	}
	long long query(int p,int l,int r,int pos){
		if(l==r) return sum[p];
		int mid=l+r>>1;
		long long res=tag[p];
		if(pos<=mid) res+=query(p<<1,l,mid,pos);
		else res+=query(p<<1|1,mid+1,r,pos);
		return res;
	}
}T1,T2;
map<PII,int>Ma[300010];
void upd(int u,int v){
	int tu=u,tv=v;
	int lca=LCA(u,v);
	int su=-1,sv=-1;
	while(top[u]!=top[lca]){
		T1.update(1,1,n,dfn[top[u]],dfn[fa[u]]);
		T2.update(1,1,n,dfn[top[u]],dfn[u]);
		if(fa[top[u]]!=lca){
			int x=fa[top[u]];
			++cnt[x][Map[x][top[u]]];
		}
		else su=top[u];
		u=fa[top[u]];
	}
	if(su==-1){
		if(tu!=lca) su=son[lca];
	}
	T2.update(1,1,n,dfn[lca]+1,dfn[u]);
	T1.update(1,1,n,dfn[lca]+1,dfn[fa[u]]);
	while(top[v]!=top[lca]){
		T1.update(1,1,n,dfn[top[v]],dfn[fa[v]]);
		T2.update(1,1,n,dfn[top[v]],dfn[v]);
		if(fa[top[v]]!=lca){
			int x=fa[top[v]];
			++cnt[x][Map[x][top[v]]];
		}
		else sv=top[v];
		v=fa[top[v]];
	}
	if(sv==-1){
		if(tv!=lca) sv=son[lca];
	}
	T1.update(1,1,n,dfn[lca]+1,dfn[fa[v]]);
	T2.update(1,1,n,dfn[lca]+1,dfn[v]);
	if(sv!=-1){
		Ma[lca][mp(sv,-1)]++;
	}
	if(su!=-1){
		Ma[lca][mp(su,-1)]++;
	}
	if(su!=-1&&sv!=-1){
		Ma[lca][mp(min(su,sv),max(sv,su))]++;
	}
	Ma[lca][mp(-1,-1)]++;
}
long long ans;
struct edge{
	int u,v;
}e[300010];
void solve(){
	long long res1=0,res2=0;
	for(int i=1;i<=m;++i){
		int lca=LCA(e[i].u,e[i].v);
		int su,sv;su=sv=-1;
		int u=e[i].u,v=e[i].v;
		if(u!=lca){
			while(top[u]!=top[lca]){
				if(fa[top[u]]==lca) su=top[u];
				u=fa[top[u]];
			}
			if(su==-1) su=son[lca];
		}
		if(v!=lca){
			while(top[v]!=top[lca]){
				if(fa[top[v]]==lca) sv=top[v];
				v=fa[top[v]];
			}
			if(sv==-1) sv=son[lca];
		}
		res1+=Ma[lca][mp(-1,-1)];
		if(su!=-1){
			res1-=Ma[lca][mp(su,-1)];
		}
		if(sv!=-1){
			res1-=Ma[lca][mp(sv,-1)];
		}
		if(su!=-1&&sv!=-1){
			res1+=Ma[lca][mp(min(su,sv),max(su,sv))];
		}
		if(su==-1&&sv==-1){
			--res1;
		}
		res2+=T2.query(1,1,n,dfn[lca]);
		if(su!=-1){
			if(su==son[lca]) res2-=T1.query(1,1,n,dfn[lca]);
			else res2-=cnt[lca][Map[lca][su]];
		}
		if(sv!=-1){
			if(sv==son[lca]) res2-=T1.query(1,1,n,dfn[lca]);
			else res2-=cnt[lca][Map[lca][sv]];
		}
	}
	ans+=(res1>>1);
	ans+=res2;
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		vec[u].pb(v),vec[v].pb(u);
	}
	dfs1(1,0);
	dfs2(1,1);
	m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		e[i]={u,v};
		upd(u,v);
	}
	solve();
	printf("%lld\n",ans);	
}