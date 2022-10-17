#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=500000;
int n;
struct Tree{
	int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
	void add_edge(int from,int to){
		arrive[++tot]=to;
		nxt[tot]=head[from];
		head[from]=tot;
	}
	int fa[Maxn+5];
	int dfn[Maxn+5],dfn_tot;
	void init_dfs(int u){
		dfn[u]=++dfn_tot;
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			if(v==fa[u]){
				continue;
			}
			fa[v]=u;
			init_dfs(v);
		}
	}
}tree_1,tree_2;
int lis[Maxn+5],lis_len;
bool cmp(int p,int q){
	return tree_1.dfn[p]>tree_1.dfn[q];
}
int fa[Maxn+5];
int find(int x){
	if(x==fa[x]){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fa_x=find(x),fa_y=find(y);
	if(fa_x==fa_y){
		return;
	}
	fa[fa_y]=fa_x;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		tree_1.add_edge(u,v);
		tree_1.add_edge(v,u);
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		tree_2.add_edge(u,v);
		tree_2.add_edge(v,u);
	}
	tree_1.init_dfs(1);
	tree_2.init_dfs(1);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=n;i++){
		if(tree_1.fa[i]!=tree_2.fa[i]&&tree_2.fa[tree_1.fa[i]]!=i){
			lis[++lis_len]=i;
		}
		if(tree_1.fa[i]==tree_2.fa[i]){
			merge(tree_1.fa[i],i);
		}
		else if(tree_2.fa[tree_1.fa[i]]==i){
			merge(i,tree_1.fa[i]);
		}
	}
	printf("%d\n",lis_len);
	sort(lis+1,lis+1+lis_len,cmp);
	for(int i=1;i<=lis_len;i++){
		printf("%d %d %d %d\n",tree_1.fa[lis[i]],lis[i],tree_2.fa[find(lis[i])],find(lis[i]));
	}
	return 0;
}