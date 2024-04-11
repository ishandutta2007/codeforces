#include <cstdio>
#include <cstring>
template<typename Elem>
Elem min(Elem a,Elem b){
	return a<b?a:b;
}
const int Maxn=100;
const int Maxm=50000;
const int Inf=0x3f3f3f3f;
int n,m;
struct Edge{
	int to,nxt,val,flow,cap;
}edge[Maxm+5];
int head[Maxn+5],tot;
void unuse_add_edge(int from,int to,int cap,int val){
	edge[++tot].to=to;
	edge[tot].nxt=head[from];
	edge[tot].flow=0;
	edge[tot].val=val;
	edge[tot].cap=cap;
	head[from]=tot;
}
void add_edge(int from,int to,int cap,int val){
	unuse_add_edge(from,to,cap,val);
	unuse_add_edge(to,from,0,-val);
}
int S,T;
int dep[Maxn+5],p[Maxn+5];
bool vis[Maxn+5];
int qu[Maxn+5],qu_f,qu_t;
bool work_bfs(){
	memset(dep,0x3f,sizeof dep);
	memset(vis,0,sizeof vis);
	qu_f=0,qu_t=0;
	dep[S]=0;
	qu[++qu_t]=S;
	vis[S]=1;
	while(qu_f!=qu_t){
		qu_f++;
		qu_f%=Maxn;
		int u=qu[qu_f];
		vis[u]=0;
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(edge[i].flow==edge[i].cap||dep[v]<=dep[u]+edge[i].val){
				continue;
			}
			dep[v]=dep[u]+edge[i].val;
			p[v]=i;
			if(!vis[v]){
				vis[v]=1;
				qu_t++;
				qu_t%=Maxn;
				qu[qu_t]=v;
			}
		}
	}
	return dep[T]<Inf;
}
int ans_f[Maxn+5],ans_c[Maxn+5];
int ans_len;
void EK(){
	int flow=0,cost=0;
	while(work_bfs()){
		int f=Inf;
		for(int i=T;i!=S;i=edge[((p[i]-1)^1)+1].to){
			f=min(f,edge[p[i]].cap-edge[p[i]].flow);
		}
		flow+=f;
		cost+=dep[T]*f;
		for(int i=T;i!=S;i=edge[((p[i]-1)^1)+1].to){
			edge[p[i]].flow+=f;
			edge[((p[i]-1)^1)+1].flow-=f;
		}
		ans_f[++ans_len]=flow;
		ans_c[ans_len]=cost;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	S=1,T=n;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,1,w);
	}
	EK();
	int q;
	scanf("%d",&q);
	for(int t=1;t<=q;t++){
		int x;
		scanf("%d",&x);
		double ans=Inf;
		for(int i=1;i<=ans_len;i++){
			ans=min(ans,1.0*(ans_c[i]+x)/ans_f[i]);
		}
		printf("%.10lf\n",ans);
	}
	return 0;
}