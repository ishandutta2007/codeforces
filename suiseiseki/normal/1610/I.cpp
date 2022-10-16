#include <cstdio>
const int Maxn=300000;
int n;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int f[Maxn+5];
int fa[Maxn+5];
bool vis[Maxn+5];
void init_dfs(int u){
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[u]){
			continue;
		}
		fa[v]=u;
		init_dfs(v);
		f[u]^=f[v]+1;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v),add_edge(v,u);
	}
	init_dfs(1);
	vis[1]=1;
	if(f[1]==0){
		putchar('2');
	}
	else{
		putchar('1');
	}
	int sum_xor=f[1],sum_edge=0;
	for(int i=2;i<=n;i++){
		int u=i;
		while(!vis[u]){
			vis[u]=1;
			sum_edge^=1;
			sum_xor^=f[u]+1;
			for(int j=head[u];j;j=nxt[j]){
				int v=arrive[j];
				if(v==fa[u]){
					continue;
				}
				sum_xor^=f[v]+1;
			}
			u=fa[u];
		}
		if((sum_xor^sum_edge)==0){
			putchar('2');
		}
		else{
			putchar('1');
		}
	}
	putchar('\n');
	return 0;
}