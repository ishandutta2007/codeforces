#include <cstdio>
const int Maxn=200000;
int n,m;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],val[Maxn<<1|5],tot;
void add_edge(int from,int to,int v){
	arrive[++tot]=to;
	val[tot]=v;
	nxt[tot]=head[from];
	head[from]=tot;
}
namespace DSU{
	int fa[Maxn+5],val[Maxn+5];
	void init(){
		for(int i=1;i<=n;i++){
			fa[i]=i;
			val[i]=0;
		}
	}
	int find(int x){
		if(x==fa[x]){
			return x;
		}
		int t_fa=find(fa[x]);
		val[x]^=val[fa[x]];
		return fa[x]=t_fa;
	}
	bool merge(int x,int y,int v){
		int fa_x=find(x),fa_y=find(y);
		if(fa_x==fa_y){
			if((val[x]^val[y])!=v){
				return 0;
			}
			return 1;
		}
		fa[fa_y]=fa_x;
		val[fa_y]=val[x]^val[y]^v;
		return 1;
	}
	int get_val(int x,int y){
		find(x),find(y);
		return val[x]^val[y];
	}
}
int fa[Maxn+5];
void init_dfs(int u){
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[u]){
			continue;
		}
		if(val[i]!=-1){
			DSU::merge(u,v,__builtin_popcount(val[i])&1);
		}
		fa[v]=u;
		init_dfs(v);
	}
}
int dis[Maxn+5];
void work_dfs(int u){
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[u]){
			continue;
		}
		if(val[i]==-1){
			dis[v]=dis[u]^DSU::get_val(u,v);
		}
		else{
			dis[v]=dis[u]^val[i];
		}
		work_dfs(v);
	}
}
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		head[i]=0;
	}
	tot=0;
	DSU::init();
	for(int i=1;i<n;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w),add_edge(v,u,w);
	}
	bool flag_ans=1;
	init_dfs(1);
	for(int i=1;i<=m;i++){
		int u,v,p;
		scanf("%d%d%d",&u,&v,&p);
		if(!DSU::merge(u,v,p)){
			flag_ans=0;
		}
	}
	if(!flag_ans){
		puts("NO");
		return;
	}
	for(int i=1;i<n;i++){
		if(DSU::find(i)!=DSU::find(i+1)){
			DSU::merge(i,i+1,0);
		}
	}
	work_dfs(1);
	puts("YES");
	for(int i=2;i<=n;i++){
		printf("%d %d %d\n",fa[i],i,dis[fa[i]]^dis[i]);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}