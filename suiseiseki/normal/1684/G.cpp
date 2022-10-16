#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
const int Maxn=1000;
const int Maxm=Maxn*Maxn+Maxn;
const int Inf=0x3f3f3f3f;
namespace Dinic{
	struct Edge{
		int to,flow,cap,nxt;
	}edge[Maxm<<1|5];
	int head[Maxn+5],cur_h[Maxn+5],tot;
	int dep[Maxn+5];
	int S,T;
	void unuse_add_edge(int from,int to,int cap){
		edge[++tot].to=to,edge[tot].flow=0,edge[tot].cap=cap,edge[tot].nxt=head[from],head[from]=tot;
	}
	void add_edge(int from,int to,int cap){
		unuse_add_edge(from,to,cap),unuse_add_edge(to,from,0);
	}
	bool Dinic_bfs(){
		static int qu[Maxn+5];
		memcpy(cur_h,head,sizeof cur_h);
		memset(dep,0,sizeof dep);
		int qu_f=1,qu_t=0;
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
		for(int &i=cur_h[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(edge[i].flow==edge[i].cap||dep[v]!=dep[u]+1){
				continue;
			}
			int op=std::min(flow-sum,edge[i].cap-edge[i].flow),f;
			if((f=Dinic_dfs(v,op))){
				sum+=f,edge[i].flow+=f,edge[((i-1)^1)+1].flow-=f;
				if(sum==flow){
					break;
				}
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
}
int n,m;
int a[Maxn+5],b[Maxn+5],c[Maxn+5];
int t_1,t_2,tot;
int z[Maxn+5],len;
struct Edge{
	int u,v,id;
	Edge(int _u=0,int _v=0,int _id=0){
		u=_u,v=_v,id=_id;
	}
}g[Maxn*Maxn+5];
int ans;
std::vector<int> d[Maxn+5];
std::map<int,int> cnt;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(2*a[i]+1>m){
			puts("-1");
			return 0;
		}
		cnt[a[i]]++;
	}
	std::sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]*3ll>m){
			b[++t_1]=a[i];
		}
		else{
			c[++t_2]=a[i];
		}
	}
	int S=t_1+t_2+1,T=t_1+t_2+2;
	Dinic::S=S,Dinic::T=T;
	for(int i=1;i<=t_1;i++){
		Dinic::add_edge(S,i,1);
	}
	for(int i=1;i<=t_2;i++){
		Dinic::add_edge(i+t_1,T,1);
	}
	for(int i=1;i<=t_1;i++){
		for(int j=1;j<=t_2;j++){
			int u=b[i],v=c[j];
			if(2*u+v<=m&&u%v==0){
				Dinic::add_edge(i,j+t_1,1);
				g[++tot]=Edge(u,v,Dinic::tot);
			}
		}
	}
	int ans=Dinic::Dinic();
	if(ans!=t_1){
		puts("-1");
		return 0;
	}
	int d_len=0;
	for(int i=1;i<=tot;i++){
		if(Dinic::edge[g[i].id].flow<Dinic::edge[g[i].id].cap){
			d_len++;
			int u=g[i].u,v=g[i].v;
			d[d_len].push_back(2*u+v),d[d_len].push_back(u+v);
			cnt[u]--,cnt[v]--;
		}
	}
	for(int i=1;i<=n;i++){
		if(cnt[a[i]]){
			cnt[a[i]]--;
			d_len++;
			d[d_len].push_back(3*a[i]),d[d_len].push_back(2*a[i]);
		}
	}
	printf("%d\n",d_len);
	for(int i=1;i<=d_len;i++){
		for(int u:d[i]){
			printf("%d ",u);
		}
		puts("");
	}
	return 0;
}