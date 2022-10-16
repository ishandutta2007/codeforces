#include <cstdio>
#include <cstring>
#include <algorithm>
const int Maxn=300000;
const int Maxm=600000;
const int Maxq=1200000;
#define int long long
int w[Maxn+5];
int f[Maxn+5][20][2][2];
int f_x[2],f_y[2],d[Maxn+5];
int n;
int fa[Maxn+5][20],dep[Maxn+5];
int head[Maxn+5],arrive[Maxn<<1|5],val_1[Maxn<<1|5],val_2[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to,int w_1,int w_2){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	val_1[tot]=w_1;
	val_2[tot]=w_2;
	head[from]=tot;
}
void init_dfs_1(int u){
	dep[u]=dep[fa[u][0]]+1;
	for(int i=1;fa[fa[u][i-1]][i-1];i++){
		fa[u][i]=fa[fa[u][i-1]][i-1];
	}
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[u][0]){
			continue;
		}
		fa[v][0]=u;
		init_dfs_1(v);
		w[u]=std::min(w[u],w[v]+val_1[i]+val_2[i]);
	}
}
void init_dfs_2(int u){
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[u][0]){
			continue;
		}
		w[v]=std::min(w[v],w[u]+val_1[i]+val_2[i]);
		init_dfs_2(v);
	}
}
void work_dfs(int u){
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[u][0]){
			continue;
		}
		work_dfs(v);
		f[v][0][0][0]=std::min(val_1[i],w[v]+val_2[i]+w[u]);
		f[v][0][0][1]=std::min(w[v]+val_2[i],w[u]+val_1[i]);
		f[v][0][1][0]=std::min(w[v]+val_1[i],w[u]+val_2[i]);
		f[v][0][1][1]=std::min(val_2[i],w[v]+val_1[i]+w[u]);
	}
}
int find_lca(int u,int v){
	if(dep[u]<dep[v]){
		std::swap(u,v);
	}
	for(int i=19;i>=0;i--){
		if(dep[fa[u][i]]>=dep[v]){
			u=fa[u][i];
		}
	}
	if(u==v){
		return u;
	}
	for(int i=19;i>=0;i--){
		if(fa[u][i]!=fa[v][i]){
			u=fa[u][i],v=fa[v][i];
		}
	}
	return fa[u][0];
}
void solve(){
	int u,v,op_u,op_v;
	scanf("%lld%lld",&u,&v);
	op_u=(u&1)^1,op_v=(v&1)^1;
	u=(u+1)>>1,v=(v+1)>>1;
	int lca=find_lca(u,v);
	f_x[op_u]=f_y[op_v]=0;
	f_x[op_u^1]=w[u],f_y[op_v^1]=w[v];
	for(int i=19;i>=0;i--){
		if(dep[fa[u][i]]>=dep[lca]){
			int tmp_0=f_x[0],tmp_1=f_x[1];
			f_x[0]=std::min(tmp_0+f[u][i][0][0],tmp_1+f[u][i][1][0]);
			f_x[1]=std::min(tmp_0+f[u][i][0][1],tmp_1+f[u][i][1][1]);
			u=fa[u][i];
		}
	}
	for(int i=19;i>=0;i--){
		if(dep[fa[v][i]]>=dep[lca]){
			int tmp_0=f_y[0],tmp_1=f_y[1];
			f_y[0]=std::min(tmp_0+f[v][i][0][0],tmp_1+f[v][i][1][0]);
			f_y[1]=std::min(tmp_0+f[v][i][0][1],tmp_1+f[v][i][1][1]);
			v=fa[v][i];
		}
	}
	printf("%lld\n",std::min(f_x[0]+f_y[0],f_y[1]+f_x[1]));
}
signed main(){
	memset(f,0x3f,sizeof f);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<n;i++){
		int u,v,a,b;
		scanf("%lld%lld%lld%lld",&u,&v,&a,&b);
		add_edge(u,v,a,b),add_edge(v,u,a,b);
	}
	init_dfs_1(1);
	init_dfs_2(1);
	work_dfs(1);
	for(int i=1;i<20;i++){
		for(int j=1;j<=n;j++){
			f[j][i][0][0]=std::min(f[j][i-1][0][0]+f[fa[j][i-1]][i-1][0][0],f[j][i-1][0][1]+f[fa[j][i-1]][i-1][1][0]);
			f[j][i][0][1]=std::min(f[j][i-1][0][0]+f[fa[j][i-1]][i-1][0][1],f[j][i-1][0][1]+f[fa[j][i-1]][i-1][1][1]);
			f[j][i][1][0]=std::min(f[j][i-1][1][0]+f[fa[j][i-1]][i-1][0][0],f[j][i-1][1][1]+f[fa[j][i-1]][i-1][1][0]);
			f[j][i][1][1]=std::min(f[j][i-1][1][0]+f[fa[j][i-1]][i-1][0][1],f[j][i-1][1][1]+f[fa[j][i-1]][i-1][1][1]);
		}
	}
	int T;
	scanf("%lld",&T);
	for(int t=1;t<=T;t++){
		solve();
	}
	return 0;
}