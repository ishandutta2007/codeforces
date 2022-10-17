#include <cstdio>
#include <cstring>
#define Inf 0x3f3f3f3f
#define Maxn 100000
int min(int a,int b){
	return a<b?a:b;
}
int m,n;
int mn(int a,int b){
	return a<b?a:b;
}
struct Edge{
	int to,nxt,cap,flow;
}edge[Maxn+5];
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
int S,T;
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
		if(f=Dinic_dfs(v,op)){
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
	int a_1,a_2,a_3,b_1,b_2,b_3;
	scanf("%d%d%d",&a_1,&a_2,&a_3);
	scanf("%d%d%d",&b_1,&b_2,&b_3);
	S=1,T=8;
	add_edge(1,2,b_1);
	add_edge(1,3,b_2);
	add_edge(1,4,b_3);
	add_edge(5,8,a_1);
	add_edge(6,8,a_2);
	add_edge(7,8,a_3);
	add_edge(2,5,Inf);
	add_edge(2,6,Inf);
	add_edge(3,6,Inf);
	add_edge(3,7,Inf);
	add_edge(4,7,Inf);
	add_edge(4,5,Inf);
	int ans_1=min(a_1,b_2)+min(a_2,b_3)+min(a_3,b_1);
	int ans_2=n-Dinic();
	printf("%d %d\n",ans_2,ans_1);
	return 0;
}