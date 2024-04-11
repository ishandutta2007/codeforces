#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=200000;
const ll Inf_ll=0x3f3f3f3f3f3f3f3fll;
int n;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int h[Maxn+5];
int mx_val[Maxn+5][2];
int mx_fa[Maxn+5];
int dfn[Maxn+5],sz[Maxn+5],dfn_tot;
namespace BIT{
	ll f[Maxn+5];
	void add(int x,int a){
		for(int i=x;i<=n;i+=(i&(-i))){
			f[i]+=a;
		}
	}
	void add(int l,int r,int a){
		add(l,a),add(r+1,-a);
	}
	ll query(int x){
		ll ans=0;
		for(int i=x;i>0;i-=(i&(-i))){
			ans+=f[i];
		}
		return ans;
	}
}
void init_dfs_1(int u,int fa){
	dfn[u]=++dfn_tot;
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		init_dfs_1(v,u);
		sz[u]+=sz[v];
		int tmp_val=std::max(mx_val[v][0],h[v]);
		if(tmp_val>mx_val[u][0]){
			mx_val[u][1]=mx_val[u][0];
			mx_val[u][0]=tmp_val;
		}
		else if(tmp_val>mx_val[u][1]){
			mx_val[u][1]=tmp_val;
		}
	}
}
void init_dfs_2(int u,int fa){
	if(fa){
		if(std::max(h[u],mx_val[u][0])==mx_val[fa][0]){
			mx_fa[u]=mx_val[fa][1];
		}
		else{
			mx_fa[u]=mx_val[fa][0];
		}
		mx_fa[u]=std::max(mx_fa[u],h[fa]);
		if(mx_fa[u]>mx_val[u][0]){
			mx_val[u][1]=mx_val[u][0];
			mx_val[u][0]=mx_fa[u];
		}
		else if(mx_fa[u]>mx_val[u][1]){
			mx_val[u][1]=mx_fa[u];
		}
		int cur_val;
		if(mx_fa[u]==mx_val[u][0]){
			cur_val=std::max(0,h[u]-mx_val[u][1]);
		}
		else{
			cur_val=std::max(0,h[u]-mx_val[u][0]);
		}
		BIT::add(1,dfn[u]-1,cur_val);
		BIT::add(dfn[u]+sz[u],n,cur_val);
	}
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		int tmp_val=std::max(h[v],mx_val[v][0]),cur_val;
		if(tmp_val==mx_val[u][0]){
			cur_val=std::max(0,h[u]-mx_val[u][1]);
		}
		else{
			cur_val=std::max(0,h[u]-mx_val[u][0]);
		}
		BIT::add(dfn[v],dfn[v]+sz[v]-1,cur_val);
		init_dfs_2(v,u);
	}
}
int main(){
	scanf("%d",&n);
	int max_h=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&h[i]);
		max_h=std::max(max_h,h[i]);
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v),add_edge(v,u);
	}
	init_dfs_1(1,0);
	init_dfs_2(1,0);
	ll ans=Inf_ll;
	for(int i=1;i<=n;i++){
		// printf("%d %lld %d\n",i,BIT::query(dfn[i]),max_h);
		if(h[i]==max_h&&mx_val[i][0]!=max_h){
			ans=std::min(ans,BIT::query(dfn[i])+max_h+max_h-mx_val[i][0]);
		}
		else{
			ans=std::min(ans,BIT::query(dfn[i])+max_h);
		}
	}
	printf("%lld\n",ans);
	return 0;
}