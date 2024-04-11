#include <cstdio>
#include <cstring>
void swap(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}
int min(int a,int b){
	return a<b?a:b;
}
int max(int a,int b){
	return a>b?a:b;
}
const int Maxn=20000;
const int Maxv=1000000;
const int Maxm=4000000;
const int Inf=0x3f3f3f3f;
int n,m;
int id_tot;
int pos[Maxn+5];
int id[15][Maxn+5];
int S,T;
namespace Dinic{
	int bel[Maxv+5];
	struct Edge{
		int to,nxt,cap,flow;
	}edge[Maxm+5];
	int head[Maxv+5],tot;
	void unuse_add_edge(int from,int to,int cap){
		edge[++tot].to=to;
		edge[tot].nxt=head[from];
		edge[tot].cap=cap;
		edge[tot].flow=0;
		head[from]=tot;
	}
	void add_edge(int from,int to,int cap){
		/*if(cap==Inf){
			printf("%d %d Inf\n",from,to);
		}
		else{
			printf("%d %d %d\n",from,to,cap);
		}*/
		unuse_add_edge(from,to,cap);
		unuse_add_edge(to,from,0);
	}
	int que[Maxv+5],que_f,que_t;
	int dep[Maxv+5];
	bool Dinic_bfs(){
		que_f=1;
		que_t=0;
		que[++que_t]=S;
		for(int i=1;i<=id_tot;i++){
			dep[i]=0;
		}
		dep[S]=1;
		while(que_f<=que_t){
			int u=que[que_f++];
			for(int i=head[u];i;i=edge[i].nxt){
				int v=edge[i].to;
				if(edge[i].flow==edge[i].cap){
					continue;
				}
				if(dep[v]==0){
					dep[v]=dep[u]+1;
					que[++que_t]=v;
				}
			}
		}
		return dep[T]>0;
	}
	int Dinic_dfs(int u,int flow){
		if(flow==0||u==T){
			return flow;
		}
		int sum=0;
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(dep[v]!=dep[u]+1||edge[i].cap==edge[i].flow){
				continue;
			}
			int op=min(edge[i].cap-edge[i].flow,flow-sum),f;
			if((f=Dinic_dfs(v,op))){
				sum+=f;
				edge[i].flow+=f;
				edge[((i-1)^1)+1].flow-=f;
			}
		}
		if(sum==0){
			dep[u]=0;
		}
		return sum;
	}
	int Dinic(){
		int ans=0;
		while(Dinic_bfs()){
			ans+=Dinic_dfs(S,Inf);
		}
		return ans;
	}
	void work_bfs_S(){
		que_f=1,que_t=0;
		que[++que_t]=S;
		while(que_f<=que_t){
			int u=que[que_f++];
			bel[u]=1;
			for(int i=head[u];i;i=edge[i].nxt){
				int v=edge[i].to;
				if(edge[i].flow==edge[i].cap||bel[v]){
					continue;
				}
				que[++que_t]=v;
			}
		}
	}
}
namespace Tree{
	int edge_id[Maxn+5];
	int fa[15][Maxn+5];
	int dep[Maxn+5];
	int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
	void add_edge(int from,int to){
		arrive[++tot]=to;
		nxt[tot]=head[from];
		head[from]=tot;
	}
	struct Edge{
		int u,v;
	}edge[Maxn+5];
	void init_dfs(int u){
		id[0][u]=++id_tot;
		dep[u]=dep[fa[0][u]]+1;
		for(int i=1;fa[i-1][fa[i-1][u]];i++){
			fa[i][u]=fa[i-1][fa[i-1][u]];
			id[i][u]=++id_tot;
			Dinic::add_edge(id[i][u],id[i-1][u],Inf);
			Dinic::add_edge(id[i][u],id[i-1][fa[i-1][u]],Inf);
		}
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			if(v==fa[0][u]){
				continue;
			}
			edge_id[(i+1)>>1]=v;
			fa[0][v]=u;
			init_dfs(v);
		}
	}
	int find_lca(int u,int v){
		if(dep[u]<dep[v]){
			swap(u,v);
		}
		for(int i=14;i>=0;i--){
			if(dep[fa[i][u]]>=dep[v]){
				u=fa[i][u];
			}
		}
		if(u==v){
			return u;
		}
		for(int i=14;i>=0;i--){
			if(fa[i][u]!=fa[i][v]){
				u=fa[i][u];
				v=fa[i][v];
			}
		}
		return fa[0][u];
	}
	void insert(int u,int v,int t){
		int lca=find_lca(u,v);
		for(int i=14;i>=0;i--){
			if(dep[fa[i][u]]>=dep[lca]){
				Dinic::add_edge(t,id[i][u],Inf);
				u=fa[i][u];
			}
			if(dep[fa[i][v]]>=dep[lca]){
				Dinic::add_edge(t,id[i][v],Inf);
				v=fa[i][v];
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		Tree::add_edge(u,v);
		Tree::add_edge(v,u);
		Tree::edge[i].u=u;
		Tree::edge[i].v=v;
	}
	Tree::init_dfs(1);
	S=++id_tot;
	T=++id_tot;
	for(int i=2;i<=n;i++){
		Dinic::add_edge(id[0][i],T,1);
	}
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		id_tot++;
		pos[i]=id_tot;
		Dinic::add_edge(S,id_tot,1);
		Tree::insert(u,v,id_tot);
	}
	int ans=Dinic::Dinic();
	printf("%d\n",ans);
	int num_1=0,num_2=0;
	Dinic::work_bfs_S();
	for(int i=1;i<=m;i++){
		if(Dinic::bel[pos[i]]==0){
			num_1++;
		}
	}
	for(int i=1;i<n;i++){
		if(Dinic::bel[id[0][Tree::edge_id[i]]]==1){
			num_2++;
		}
	}
	printf("%d ",num_1);
	for(int i=1;i<=m;i++){
		if(Dinic::bel[pos[i]]==0){
			printf("%d ",i);
		}
	}
	puts("");
	printf("%d ",num_2);
	for(int i=1;i<n;i++){
		if(Dinic::bel[id[0][Tree::edge_id[i]]]==1){
			printf("%d ",i);
		}
	}
	puts("");
	return 0;
}