#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=3000;
const ll Inf_ll=0x3f3f3f3f3f3f3f3fll;
int n,m;
int b[Maxn+5],w[Maxn+5];
int a[Maxn+5];
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int sz[Maxn+5];
std::pair<int,ll> f[Maxn+5][Maxn+5];
void init_dfs(int u,int fa){
	static std::pair<int,ll> tmp[Maxn+5];
	sz[u]=1;
	f[u][0]=std::make_pair(0,1ll*a[u]);
	f[u][1]=std::make_pair(-1,-Inf_ll);
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		init_dfs(v,u);
		for(int j=0;j<=std::min(sz[u]+sz[v],m);j++){
			tmp[j]=std::make_pair(-1,-Inf_ll);
		}
		for(int j=0;j<=std::min(m,sz[u]);j++){
			for(int k=0;k<=std::min(sz[v],m-j);k++){
				std::pair<int,ll> tmp_val=std::make_pair(f[u][j].first+f[v][k].first,f[u][j].second+f[v][k].second);
				tmp[j+k]=std::max(tmp[j+k],tmp_val);
			}
		}
		for(int j=0;j<=std::min(sz[u]+sz[v],m);j++){
			f[u][j]=tmp[j];
		}
		sz[u]+=sz[v];
	}
	if(u!=1){
		for(int i=std::min(m-1,sz[u]-1);i>=0;i--){
			f[u][i+1]=std::max(f[u][i+1],std::make_pair(f[u][i].first+(f[u][i].second>0),0ll));
		}
	}
}
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		head[i]=0;
	}
	tot=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		a[i]=w[i]-b[i];
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v),add_edge(v,u);
	}
	init_dfs(1,0);
	printf("%d\n",f[1][m-1].first+(f[1][m-1].second>0));
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}