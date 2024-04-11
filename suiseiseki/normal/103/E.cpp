#include <cstdio>
#include <cstring>
void read(int &a){
	a=0;
	char c=getchar();
	while((c<'0'||c>'9')&&c!='-'){
		c=getchar();
	}
	int f=1;
	if(c=='-'){
		f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
	if(f==-1){
		a=-a;
	}
}
int mn(int a,int b){
	return a<b?a:b;
}
const int Maxn=300;
const int Inf=0x7f7f7f7f;
int n;
int len[Maxn+5];
int a[Maxn+5][Maxn+5];
bool vis[Maxn+5],in[Maxn+5];
int ned[Maxn+5][Maxn+5];
int qu[Maxn+5],qu_f,qu_t;
int dep[Maxn+5];
int ned_l[Maxn+5];
int pos[Maxn+5],rnk[Maxn+5];
int val[Maxn+5];
namespace Graph_1{
	bool g[Maxn+5][Maxn+5];
	int vis[Maxn+5];
	bool used[Maxn+5];
	bool dfs(int u){
		for(int i=1;i<=n;i++){
			if(g[u][i]&&(!used[i])){
				used[i]=1;
				if(vis[i]==0){
					vis[i]=u;
					return 1;
				}
				if(dfs(vis[i])){
					vis[i]=u;
					return 1;
				}
			}
		}
		return 0;
	}
}
struct Edge{
	int to,nxt,cap,val;
}edge[Maxn*Maxn*4+5];
int head[Maxn+5],tot;
void unuse_add_edge(int from,int to,int cap){
	edge[++tot].to=to;
	edge[tot].nxt=head[from];
	edge[tot].cap=cap;
	edge[tot].val=0;
	head[from]=tot;
}
void add_edge(int from,int to,int cap){
	unuse_add_edge(from,to,cap);
	unuse_add_edge(to,from,0);
}
int S,T;
bool Dinic_bfs(){
	memset(dep,0,sizeof dep);
	dep[S]=1;
	qu_f=1,qu_t=0;
	qu[++qu_t]=S;
	while(qu_f<=qu_t){
		int u=qu[qu_f++];
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(dep[v]||edge[i].val==edge[i].cap){
				continue;
			}
			dep[v]=dep[u]+1;
			qu[++qu_t]=v;
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
		if(dep[v]!=dep[u]+1){
			continue;
		}
		int op=mn(edge[i].cap-edge[i].val,flow),f;
		if(f=Dinic_dfs(v,op)){
			sum+=f;
			flow-=f;
			edge[i].val+=f;
			edge[((i-1)^1)+1].val-=f;
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
	read(n);
	for(int i=1;i<=n;i++){
		read(len[i]);
		for(int j=1;j<=len[i];j++){
			read(a[i][j]);
			Graph_1::g[i][a[i][j]]=1;
		}
	}
	for(int i=1;i<=n;i++){
		memset(Graph_1::used,0,sizeof Graph_1::used);
		Graph_1::dfs(i);
	}
	for(int i=1;i<=n;i++){
		rnk[i]=Graph_1::vis[i];
		pos[rnk[i]]=i;
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);
		memset(in,0,sizeof in);
		qu_f=1;
		qu_t=0;
		qu[++qu_t]=i;
		in[pos[i]]=1;
		while(qu_f<=qu_t){
			int u=qu[qu_f++];
			ned[i][++ned_l[i]]=u;
			for(int j=1;j<=len[u];j++){
				vis[a[u][j]]=1;
			}
			for(int j=1;j<=n;j++){
				if(vis[j]&&(!in[j])){
					qu[++qu_t]=rnk[j];
					in[j]=1;
				}
			}
		}
	}
	S=n+1;
	T=n+2;
	int ans=0;
	for(int i=1;i<=n;i++){
		read(val[i]);
		val[i]=-val[i];
		if(val[i]>0){
			ans+=val[i];
			add_edge(S,i,val[i]);
		}
		else{
			add_edge(i,T,-val[i]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=ned_l[i];j++){
			if(ned[i][j]==i){
				continue;
			}
			add_edge(i,ned[i][j],Inf);
		}
	}
	printf("%d\n",-(ans-Dinic()));
	return 0;
}