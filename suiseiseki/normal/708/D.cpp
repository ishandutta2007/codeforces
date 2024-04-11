#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
const int Maxn=100;
const int Maxm=400;
const int Inf_int=0x3f3f3f3f;
const ll Inf_ll=0x3f3f3f3f3f3f3f3fll;
int n,m,S,T;
struct Edge{
	int to,flow,cap,val,nxt;
}edge[Maxm<<1|5];
int head[Maxn+5],tot;
int deg[Maxn+5];
void unuse_add_edge(int from,int to,int cap,int val){
	edge[++tot].to=to;
	edge[tot].nxt=head[from];
	edge[tot].flow=0;
	edge[tot].cap=cap;
	edge[tot].val=val;
	head[from]=tot;
}
void add_edge(int from,int to,int cap,int val){
	unuse_add_edge(from,to,cap,val);
	unuse_add_edge(to,from,0,-val);
}
ll dep[Maxn+5];
bool vis[Maxn+5];
bool in_q[Maxn+5];
bool Dinic_bfs(){
	memset(dep,0x3f,sizeof dep);
	memset(in_q,0,sizeof in_q);
	std::queue<int> q;
	q.push(S);
	dep[S]=0;
	in_q[S]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		in_q[u]=0;
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(edge[i].flow==edge[i].cap||dep[v]<=dep[u]+edge[i].val){
				continue;
			}
			dep[v]=dep[u]+edge[i].val;
			if(!in_q[v]){
				in_q[v]=1;
				q.push(v);
			}
		}
	}
	return dep[T]<Inf_ll;
}
int Dinic_dfs(int u,int flow,ll &min_cost){
	if(flow==0||u==T){
		return flow;
	}
	vis[u]=1;
	int sum=0;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(vis[v]||dep[v]!=dep[u]+edge[i].val||edge[i].flow==edge[i].cap){
			continue;
		}
		int op=std::min(edge[i].cap-edge[i].flow,flow-sum),f;
		if((f=Dinic_dfs(v,op,min_cost))){
			min_cost+=1ll*f*edge[i].val;
			edge[i].flow+=f;
			edge[((i-1)^1)+1].flow-=f;
			sum+=f;
			if(sum==flow){
				break;
			}
		}
	}
	if(sum==0){
		dep[u]=Inf_ll;
	}
	vis[u]=0;
	return sum;
}
int Dinic(ll &min_cost){
	int ans=0;
	while(Dinic_bfs()){
		ans+=Dinic_dfs(S,Inf_int,min_cost);
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	ll ans_1=0,ans_2=0;
	add_edge(n,1,Inf_int,0);
	for(int i=1;i<=m;i++){
		int u,v,c,f;
		scanf("%d%d%d%d",&u,&v,&c,&f);
		if(f<=c){
			add_edge(v,u,f,1);
			add_edge(u,v,c-f,1);
		}
		else{
			ans_1+=f-c;
			add_edge(v,u,f-c,0);
			add_edge(v,u,c,1);
		}
		add_edge(u,v,Inf_int,2);
		deg[u]+=f,deg[v]-=f;
	}
	S=n+1,T=n+2;
	for(int i=1;i<=n;i++){
		if(deg[i]>0){
			add_edge(i,T,deg[i],0);
		}
		else{
			add_edge(S,i,-deg[i],0);
		}
	}
	Dinic(ans_2);
	printf("%lld\n",ans_1+ans_2);
	return 0;
}