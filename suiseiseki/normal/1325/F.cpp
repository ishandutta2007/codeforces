#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
const int Maxn=1000000;
const int Maxm=2000000;
int n,m,t;
bool vis[Maxn+5];
bool in[Maxn+5];
int head[Maxn+5],arrive[Maxm<<1|5],nxt[Maxm<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int ans[Maxn+5],ans_len;
int dep[Maxn+5];
int fa[Maxn+5];
void init_dfs(int u,int lst){
	in[u]=1;
	dep[u]=dep[fa[u]]+1;
	for(int i=head[u];i;i=nxt[i]){
		if(i==(((lst-1)^1)+1)){
			continue;
		}
		int v=arrive[i];
		if(in[v]){
			if(dep[u]-dep[v]+1>=t){
				puts("2");
				printf("%d\n",dep[u]-dep[v]+1);
				int tmp=u;
				while(tmp!=v){
					printf("%d ",tmp);
					tmp=fa[tmp];
				}
				printf("%d\n",v);
				exit(0);
			}
			continue;
		}
		fa[v]=u;
		init_dfs(v,i);
	}
	if(!vis[u]){
		ans[++ans_len]=u;
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			vis[v]=1;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	t=ceil(sqrt(n));
	init_dfs(1,0);
	puts("1");
	for(int i=1;i<=t;i++){
		printf("%d ",ans[i]);
	}
	puts("");
	return 0;
}