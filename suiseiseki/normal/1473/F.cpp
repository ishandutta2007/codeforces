#include <cstdio>
#include <cstring>
int min(int a,int b){
	return a<b?a:b;
}
const int Maxv=100;
const int Maxn=6000;
const int Maxm=600000;
const int Inf=0x3f3f3f3f;
int n;
int a[Maxn+5],b[Maxn+5];
struct Edge{
	int to,nxt,flow,cap;
}edge[Maxm<<1|5];
int id_tot;
int head[Maxn+5],tot;
int lst[Maxv+5];
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
int S,T;
int qu[Maxn+5],qu_f,qu_t;
int dep[Maxn+5];
bool Dinic_bfs(){
	memset(dep,0,sizeof dep);
	qu_f=1,qu_t=0;
	qu[++qu_t]=S;
	dep[S]=1;
	while(qu_f<=qu_t){
		int u=qu[qu_f++];
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(dep[v]||edge[i].flow==edge[i].cap){
				continue;
			}
			dep[v]=dep[u]+1;
			qu[++qu_t]=v;
		}
	}
	return dep[T]>0;
}
int Dinic_dfs(int u,int flow){
	if(u==T||flow==0){
		return flow;
	}
	int sum=0;
	for(int i=head[u];i&&sum<flow;i=edge[i].nxt){
		int v=edge[i].to;
		if(dep[v]!=dep[u]+1||edge[i].flow==edge[i].cap){
			continue;
		}
		int op=min(edge[i].cap-edge[i].flow,flow-sum);
		int f;
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
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	S=n+1;
	T=n+2;
	int ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		if(b[i]>0){
			add_edge(S,i,b[i]);
			ans+=b[i];
		}
		else{
			add_edge(i,T,-b[i]);
		}
	}
	id_tot=n+2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=Maxv;j++){
			if(a[i]%j==0&&lst[j]){
				add_edge(i,lst[j],Inf);
			}
		}
		id_tot++;
		add_edge(id_tot,i,Inf);
		if(lst[a[i]]){
			add_edge(id_tot,lst[a[i]],Inf);
		}
		lst[a[i]]=id_tot;
	}
	printf("%d\n",ans-Dinic());
	return 0;
}