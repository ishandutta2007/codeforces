#include <cstdio>
const int Maxn=300000;
int n,m;
struct Edge{
	int u,v,w;
}edge[Maxn+5];
int sum[2][Maxn+5];
int ans[Maxn<<2|5];
int head[Maxn<<1|5],arrive[Maxn<<2|5],nxt[Maxn<<2|5],id[Maxn<<2|5],val[Maxn<<2|5],tot;
void unuse_add_edge(int from,int to,int _id,int _val){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	id[tot]=_id;
	val[tot]=_val;
	head[from]=tot;
}
void add_edge(int from,int to,int _id){
	unuse_add_edge(from,to,_id,1);
	unuse_add_edge(to,from,_id,2);
}
void work_dfs(int u){
	for(int &i=head[u];i;i=nxt[i]){
		if(ans[id[i]]){
			continue;
		}
		int v=arrive[i];
		ans[id[i]]=val[i];
		work_dfs(v);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
		sum[edge[i].w-1][edge[i].u]^=1;
		sum[edge[i].w-1][edge[i].v]^=1;
		if(edge[i].w==1){
			add_edge(edge[i].u,edge[i].v,i);
		}
		else{
			add_edge(edge[i].u+n,edge[i].v+n,i);
		}
	}
	int S=2*n+1;
	int answer=0;
	int tot=m;
	for(int i=1;i<=n;i++){
		if(sum[0][i]){
			answer++;
		}
		if(sum[0][i]!=sum[1][i]){
			if(sum[0][i]){
				add_edge(S,i,++tot);
			}
			else{
				add_edge(S,i+n,++tot);
			}
		}
		else{
			if(sum[0][i]){
				add_edge(i,i+n,++tot);
			}
		}
	}
	for(int i=1;i<=2*n+1;i++){
		work_dfs(i);
	}
	printf("%d\n",answer);
	for(int i=1;i<=m;i++){
		printf("%d",ans[i]);
	}
	puts("");
	return 0;
}