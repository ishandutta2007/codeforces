#include <cstdio>
#define Maxn 100000
int head[Maxn+5],arrive[Maxn+5],nxt[Maxn+5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int p[Maxn+5];
int id[Maxn+5],id_tot;
int son[Maxn+5],maxn[Maxn+5];
void dfs_1(int u){
	for(int i=head[u];i;i=nxt[i]){
		dfs_1(arrive[i]);
		if(maxn[arrive[i]]>maxn[u]){
			son[u]=arrive[i];
			maxn[u]=maxn[arrive[i]];
		}
	}
	maxn[u]++;
}
int ans[Maxn+5],len;
void dfs_2(int u){
	id[++id_tot]=u;
	int last=0;
	for(int i=head[u];i;i=nxt[i]){
		if(arrive[i]==son[u]){
			continue;
		}
		dfs_2(arrive[i]);
		for(int j=1;j<=last;j++){
			ans[++len]=arrive[i];
		}
		last=maxn[arrive[i]];
	}
	if(son[u]>0){
		dfs_2(son[u]);
		for(int j=1;j<=last;j++){
			ans[++len]=son[u];
		}
		last=maxn[son[u]];
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		scanf("%d",&p[i]);
		p[i]++;
		add_edge(p[i],i);
	}
	dfs_1(1);
	dfs_2(1);
	for(int i=1;i<=n;i++){
		printf("%d ",id[i]-1);
	}
	puts("");
	printf("%d\n",n-maxn[1]);
	for(int i=1;i<=len;i++){
		printf("%d ",ans[i]-1);
	}
	puts("");
	return 0;
}