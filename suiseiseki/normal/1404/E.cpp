#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
const int Maxn=200;
const int Maxm=80000;
const int Inf=0x3f3f3f3f;
int n,m;
char s[Maxn+5][Maxn+5];
int id_1[Maxn+5][Maxn+5],id_2[Maxn+5][Maxn+5],id_tot;
struct Edge{
	int to,flow,cap,nxt;
}edge[Maxm<<3|5];
int head[Maxm+5],tot;
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
queue<int> q;
int dep[Maxm+5];
int S,T;
bool Dinic_bfs(){
	while(!q.empty()){
		q.pop();
	}
	memset(dep,0x3f,sizeof dep);
	dep[S]=0;
	q.push(S);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(edge[i].flow==edge[i].cap){
				continue;
			}
			if(dep[v]>dep[u]+1){
				dep[v]=dep[u]+1;
				q.push(v);
			}
		}
	}
	return dep[T]!=Inf;
}
int Dinic_dfs(int u,int flow){
	if(flow==0||u==T){
		return flow;
	}
	int sum=0;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(dep[v]!=dep[u]+1||edge[i].flow==edge[i].cap){
			continue;
		}
		int op=min(flow-sum,edge[i].cap-edge[i].flow),f;
		f=Dinic_dfs(v,op);
		if(f){
			sum+=f;
			edge[i].flow+=f;
			edge[((i-1)^1)+1].flow-=f;
		}
	}
	if(sum==0){
		dep[u]=Inf;
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
	scanf("%d%d",&n,&m);
	int num=0;
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++){
			if(s[i][j]=='#'){
				num++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			if(s[i][j]=='#'&&s[i][j+1]=='#'){
				id_1[i][j]=++id_tot;
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]=='#'&&s[i+1][j]=='#'){
				id_2[i][j]=++id_tot;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(id_2[i-1][j]&&id_1[i][j]){
				add_edge(id_1[i][j],id_2[i-1][j],1);
			}
			if(id_1[i][j-1]&&id_2[i-1][j]){
				add_edge(id_1[i][j-1],id_2[i-1][j],1);
			}
			if(id_2[i][j]&&id_1[i][j]){
				add_edge(id_1[i][j],id_2[i][j],1);
			}
			if(id_2[i][j]&&id_1[i][j-1]){
				add_edge(id_1[i][j-1],id_2[i][j],1);
			}
		}
	}
	S=++id_tot;
	T=++id_tot;
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			if(id_1[i][j]){
				add_edge(S,id_1[i][j],1);
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			if(id_2[i][j]){
				add_edge(id_2[i][j],T,1);
			}
		}
	}
	printf("%d\n",num-(id_tot-2-Dinic()));
	return 0;
}