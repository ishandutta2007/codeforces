#include <cstdio>
#include <cstring>
const int Maxn=400;
const int Maxm=1000000;
const int Maxw=300000000;
const int Inf=0x7f7f7f7f;
int n,m;
int S,T;
int id[Maxn+5][Maxn+5],id_tot;
namespace Dinic{
	int min(int a,int b){
		return a<b?a:b;
	}
	struct Edge{
		int to,flow,cap,nxt;
	}edge[Maxm+5];
	int head[Maxn+5],tot;
	void unuse_add_edge(int from,int to,int cap){
		edge[++tot].to=to;
		edge[tot].nxt=head[from];
		edge[tot].cap=cap;
		edge[tot].flow=0;
		head[from]=tot;
	}
	void add_edge(int from,int to,int cap){
		unuse_add_edge(from,to,cap);
		unuse_add_edge(to,from,0);
	}
	int que[Maxn+5],que_f,que_t;
	int dep[Maxn+5];
	bool Dinic_bfs(){
		que_f=1;
		que_t=0;
		que[++que_t]=S;
		memset(dep,0,sizeof dep);
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
	bool vis[Maxn+5];
	void print_dfs(int u){
		vis[u]=1;
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(edge[i].flow!=edge[i].cap&&!vis[v]){
				print_dfs(v);
			}
		}
	}
	void print(){
		print_dfs(S);
		for(int i=1;i<=n;i++){
			int val=-1;
			for(int j=0;j<n;j++){
				if(vis[id[i][j]]){
					val=j;
				}
			}
			printf("%d ",val);
		}
		puts("");
	}
}
int head[Maxn+5],arrive[Maxn+5],nxt[Maxn+5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int sum[Maxn+5];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		sum[u]+=w;
		sum[v]-=w;
		add_edge(u,v);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			id[i][j]=++id_tot;
		}
	}
	S=++id_tot;
	T=++id_tot;
	for(int i=1;i<=n;i++){
		Dinic::add_edge(S,id[i][0],Inf);
		for(int j=1;j<=n;j++){
			Dinic::add_edge(id[i][j-1],id[i][j],sum[i]*(j-1)+Maxw);
		}
		Dinic::add_edge(id[i][n],T,Inf);
	}
	for(int u=1;u<=n;u++){
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			for(int j=1;j<=n;j++){
				Dinic::add_edge(id[v][j-1],id[u][j],Inf);
			}
		}
	}
	Dinic::Dinic();
	Dinic::print();
	return 0;
}