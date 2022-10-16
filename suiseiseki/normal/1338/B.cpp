#include <cstdio>
const int Maxn=100000;
int n;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int deg[Maxn+5];
int root;
int dep[Maxn+5];
int ans_1,ans_2;
void init_dfs_1(int u,int fa){
	dep[u]=dep[fa]+1;
	bool leaf=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		leaf=0;
		init_dfs_1(v,u);
	}
	if(leaf){
		if(~dep[u]&1){
			ans_1=3;
		}
	}
}
bool init_dfs_2(int u,int fa){
	int num=0;
	bool leaf=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		leaf=0;
		ans_2++;
		if(init_dfs_2(v,u)){
			num++;
		}
	}
	if(dep[u]==2&&num>0){
		ans_2-=num;
	}
	else if(num>1){
		ans_2-=num-1;
	}
	return leaf;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v),add_edge(v,u);
		deg[u]++,deg[v]++;
	}
	for(int i=1;i<=n;i++){
		if(deg[i]==1){
			root=i;
			break;
		}
	}
	ans_1=1;
	init_dfs_1(root,0);
	init_dfs_2(root,0);
	printf("%d %d\n",ans_1,ans_2);
	return 0;
}