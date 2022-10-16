#include <cstdio>
template<typename Elem>
Elem min(Elem a,Elem b){
	return a<b?a:b;
}
template<typename Elem>
Elem max(Elem a,Elem b){
	return a>b?a:b;
}
template<typename Elem>
Elem abs(Elem a){
	return a<0?-a:a;
}
typedef long long ll;
const int Maxn=200000;
const int Inf_int=0x3f3f3f3f;
const ll Inf_ll=0x3f3f3f3f3f3f3f3fll;
int n;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int a[Maxn+5];
int dep[Maxn+5];
int min_a[Maxn+5],max_a[Maxn+5];
ll f[Maxn+5];
int fa[Maxn+5];
void init_dfs(int u){
	dep[u]=dep[fa[u]]+1;
	min_a[dep[u]]=min(min_a[dep[u]],a[u]);
	max_a[dep[u]]=max(max_a[dep[u]],a[u]);
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[u]){
			continue;
		}
		fa[v]=u;
		init_dfs(v);
	}
}
int qu[Maxn+5],qu_f,qu_t;
int lis[Maxn+5],lis_len;
void work_bfs(int root){
	int lst_dep=0;
	lis_len=0;
	qu_t=0,qu_f=1;
	qu[++qu_t]=root;
	ll max_1=-Inf_ll,max_2=-Inf_ll;
	f[root]=0;
	while(qu_f<=qu_t){
		int u=qu[qu_f++];
		if(dep[u]!=lst_dep){
			for(int i=1;i<=lis_len;i++){
				f[lis[i]]=max(f[lis[i]],max_1+a[lis[i]]);
				f[lis[i]]=max(f[lis[i]],max_2-a[lis[i]]);
			}
			lst_dep=dep[u];
			lis_len=0;
			max_1=-Inf_ll;
			max_2=-Inf_ll;
		}
		if(u!=1){
			lis[++lis_len]=u;
			f[u]=f[fa[u]];
			max_1=max(max_1,f[u]-a[u]);
			max_2=max(max_2,f[u]+a[u]);
			f[u]+=max(max_a[dep[u]]-a[u],a[u]-min_a[dep[u]]);
		}
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			if(v==fa[u]){
				continue;
			}
			qu[++qu_t]=v;
		}
	}
}
void init(){
	for(int i=1;i<=n;i++){
		fa[i]=0;
		head[i]=0;
		min_a[i]=Inf_int;
		max_a[i]=-Inf_int;
		f[i]=-Inf_ll;
	}
	tot=0;
}
void solve(){
	scanf("%d",&n);
	init();
	for(int i=2;i<=n;i++){
		int u,v;
		u=i;
		scanf("%d",&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	for(int i=2;i<=n;i++){
		scanf("%d",&a[i]);
	}
	init_dfs(1);
	work_bfs(1);
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,f[i]);
	}
	printf("%lld\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}