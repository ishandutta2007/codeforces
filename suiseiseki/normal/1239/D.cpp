#include <cstdio>
#define Maxn 1000000
int n,m;
int head[Maxn+5],arrive[Maxn+5],nxt[Maxn+5],tot;
int dfn[Maxn+5],low[Maxn+5],dfn_tot;
int sta[Maxn+5],st_top;
int bel[Maxn+5],cnt;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
void init(){
	for(int i=1;i<=n;i++){
		head[i]=0;
		dfn[i]=low[i]=0;
		bel[i]=0;
	}
	cnt=0;
	tot=0;
	st_top=0;
	dfn_tot=0;
}
int mn(int a,int b){
	return a<b?a:b;
}
void tarjan(int u){
	dfn[u]=low[u]=++dfn_tot;
	sta[++st_top]=u;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(!dfn[v]){
			tarjan(v);
			low[u]=mn(low[u],low[v]);
		}
		else if(!bel[v]){
			low[u]=mn(low[u],dfn[v]);
		}
	}
	if(dfn[u]!=low[u]){
		return;
	}
	cnt++;
	while(sta[st_top]!=u){
		bel[sta[st_top--]]=cnt;
	}
	bel[sta[st_top--]]=cnt;
}
int main(){
	int t;
	scanf("%d",&t);
	int u,v;
	int ans;
	while(t--){
		scanf("%d%d",&n,&m);
		init();
		for(int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			if(u==v){
				continue;
			}
			add_edge(u,v);
		}
		for(int i=1;i<=n;i++){
			if(dfn[i]==0){
				tarjan(i);
			}
		}
		if(cnt==1){
			puts("No");
			continue;
		}
		ans=0;
		for(int i=1;i<=n;i++){
			if(bel[i]==1){
				ans++;
			}
		}
		puts("Yes");
		printf("%d %d\n",ans,n-ans);
		for(int i=1;i<=n;i++){
			if(bel[i]==1){
				printf("%d ",i);
			}
		}
		puts("");
		for(int i=1;i<=n;i++){
			if(bel[i]!=1){
				printf("%d ",i);
			}
		}
		puts("");
	}
	return 0;
}