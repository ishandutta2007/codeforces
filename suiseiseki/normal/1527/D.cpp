#include <cstdio>
typedef long long ll;
const int Maxn=200000;
int n;
int fa[Maxn+5];
bool vis[Maxn+5];
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
int sz[Maxn+5],dfn[Maxn+5],dfn_tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
ll f[Maxn+5];
void clear_all(){
	for(int i=1;i<=n;i++){
		vis[i]=0;
		head[i]=0;
		f[i]=0;
	}
	dfn_tot=tot=0;
}
void init_dfs(int u){
	dfn[u]=++dfn_tot;
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[u]){
			continue;
		}
		fa[v]=u;
		init_dfs(v);
		sz[u]+=sz[v];
	}
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		u++,v++;
		add_edge(u,v);
		add_edge(v,u);
	}
	init_dfs(1);
	f[0]=1ll*n*(n-1)>>1;
	int sum_sz=1;
	for(int i=head[1];i;i=nxt[i]){
		int v=arrive[i];
		f[1]+=1ll*sum_sz*sz[v];
		sum_sz+=sz[v];
	}
	int s=1,t=2,s_l=1,s_r=n;
	vis[s]=1;
	int tmp_u=t;
	while(tmp_u!=s){
		vis[tmp_u]=1;
		if(fa[tmp_u]==s){
			s_l=dfn[tmp_u],s_r=dfn[tmp_u]+sz[tmp_u]-1;
		}
		tmp_u=fa[tmp_u];
	}
	f[2]=1ll*(n-(s_r-s_l+1))*sz[t];
	for(int i=3;i<=n;i++){
		if(vis[i]){
			f[i]=f[i-1];
			continue;
		}
		if(s==1){
			if(dfn[i]>=dfn[t]&&dfn[i]<=dfn[t]+sz[t]-1){
				tmp_u=i;
				while(tmp_u!=t){
					vis[tmp_u]=1;
					tmp_u=fa[tmp_u];
				}
				t=i;
				f[i]=1ll*(n-(s_r-s_l+1))*sz[t];
			}
			else{
				if(dfn[i]>=s_l&&dfn[i]<=s_r){
					break;
				}
				tmp_u=i;
				while(tmp_u!=s){
					vis[tmp_u]=1;
					tmp_u=fa[tmp_u];
				}
				s=i;
				f[i]=1ll*sz[s]*sz[t];
			}
		}
		else{
			if(dfn[i]>=dfn[t]&&dfn[i]<=dfn[t]+sz[t]-1){
				tmp_u=i;
				while(tmp_u!=t){
					vis[tmp_u]=1;
					tmp_u=fa[tmp_u];
				}
				t=i;
				f[i]=1ll*sz[s]*sz[t];
			}
			else if(dfn[i]>=dfn[s]&&dfn[i]<=dfn[s]+sz[s]-1){
				tmp_u=i;
				while(tmp_u!=s){
					vis[tmp_u]=1;
					tmp_u=fa[tmp_u];
				}
				s=i;
				f[i]=1ll*sz[s]*sz[t];
			}
			else{
				break;
			}
		}
	}
	for(int i=0;i<=n;i++){
		f[i]-=f[i+1];
	}
	for(int i=0;i<=n;i++){
		printf("%lld ",f[i]);
	}
	puts("");
	clear_all();
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}