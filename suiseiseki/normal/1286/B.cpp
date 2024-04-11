#include <cstdio>
const int Maxn=2000;
int sz[Maxn+5];
int fa[Maxn+5];
int head[Maxn+5],arrive[Maxn+5],e_nxt[Maxn+5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	e_nxt[tot]=head[from];
	head[from]=tot;
}
int n,Root;
int c[Maxn+5];
int nxt[Maxn+5],pre[Maxn+5];
int lea[Maxn+5],lea_len;
int a[Maxn+5];
int dfn[Maxn+5],out[Maxn+5],dfn_tot;
void init_dfs(int u){
	sz[u]=1;
	for(int i=head[u];i;i=e_nxt[i]){
		int v=arrive[i];
		init_dfs(v);
		sz[u]+=sz[v];
	}
	if(sz[u]==1){
		lea[++lea_len]=u;
	}
}
void dfs(int u){
	dfn[u]=++dfn_tot;
	for(int i=head[u];i;i=e_nxt[i]){
		int v=arrive[i];
		dfs(v);
	}
	out[u]=dfn_tot;
	if(sz[u]==1){
		return;
	}
	int pos=0;
	int num=0;
	while(num<c[u]||(num==c[u]&&c[u]!=sz[u]-1)){
		pos=nxt[pos];
		if(dfn[u]<=dfn[pos]&&out[u]>=dfn[pos]){
			num++;
		}
	}
	if(c[u]==sz[u]-1){
		pos=nxt[pos];
	}
	int las=pre[pos];
	nxt[u]=pos;
	pre[u]=las;
	nxt[las]=u;
	pre[pos]=u;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&fa[i],&c[i]);
		if(fa[i]==0){
			Root=i;
		}
		add_edge(fa[i],i);
	}
	init_dfs(Root);
	lea[lea_len+1]=n+1;
	for(int i=1;i<=lea_len;i++){
		pre[lea[i]]=lea[i-1];
		nxt[lea[i]]=lea[i+1];
	}
	nxt[0]=lea[1];
	pre[n+1]=lea[lea_len];
	for(int i=1;i<=n;i++){
		if(c[i]>=sz[i]){
			puts("NO");
			return 0;
		}
	}
	dfs(Root);
	int id_tot=0;
	int pos=nxt[0];
	while(pos!=n+1){
		a[pos]=++id_tot;
		pos=nxt[pos];
	}
	puts("YES");
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	puts("");
	return 0;
}