#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Maxn=600;
const int Inf=0x3f3f3f3f;
int n,M,m;
char s[Maxn+5],b[Maxn+5];
int x[Maxn+5];
bool match(char *a,char *b,int len){
	for(int i=0;i<len;i++){
		if(a[i]!=b[i]){
			return 0;
		}
	}
	return 1;
}
struct Segment_Node{
	int l,r,x;
}seg[Maxn*Maxn+5];
struct Edge{
	int to,nxt,val,cap,flow;
}edge[Maxn*Maxn*20+5];
int num[Maxn+5];
int head[Maxn+5],tot;
void unuse_add_edge(int from,int to,int cap,int val){
	edge[++tot].to=to;
	edge[tot].nxt=head[from];
	edge[tot].val=val;
	edge[tot].cap=cap;
	edge[tot].flow=0;
	head[from]=tot;
}
void add_edge(int from,int to,int cap,int val){
	unuse_add_edge(from,to,cap,val);
	unuse_add_edge(to,from,0,-val);
}
int qu[Maxn+5],qu_f,qu_t;
int dis[Maxn+5];
bool vis[Maxn+5];
bool in_q[Maxn+5];
int S,T;
bool Dinic_bfs(){
	memset(dis,0x3f,sizeof dis);
	qu_f=1,qu_t=0;
	qu[++qu_t]=S;
	in_q[S]=1;
	dis[S]=0;
	while(qu_f!=qu_t+1){
		int u=qu[qu_f++];
		in_q[u]=0;
		qu_f%=(Maxn+1);
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(edge[i].flow==edge[i].cap){
				continue;
			}
			if(dis[u]+edge[i].val<dis[v]){
				dis[v]=dis[u]+edge[i].val;
				if(!in_q[v]){
					in_q[v]=1;
					qu_t++;
					qu_t%=(Maxn+1);
					qu[qu_t]=v;
				}
			}
		}
	}
	return dis[T]!=Inf;
}
int Dinic_dfs(int u,int flow,int &min_cost){
	if(u==T||flow==0){
		return flow;
	}
	vis[u]=1;
	int sum=0;
	for(int i=head[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(dis[v]!=dis[u]+edge[i].val||vis[v]||edge[i].flow==edge[i].cap){
			continue;
		}
		int op=min(flow-sum,edge[i].cap-edge[i].flow),f;
		if(f=Dinic_dfs(v,op,min_cost)){
			edge[i].flow+=f;
			edge[((i-1)^1)+1].flow-=f;
			min_cost+=edge[i].val*f;
			sum+=f;
			if(sum==flow){
				break;
			}
		}
	}
	vis[u]=0;
	if(sum==0){
		dis[u]=Inf;
	}
	return sum;
}
int Dinic(int &min_cost){
	int ans=0;
	min_cost=0;
	while(Dinic_bfs()){
		ans+=Dinic_dfs(S,Inf,min_cost);
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	scanf("%d",&M);
	int sum=0;
	for(int i=1;i<=M;i++){
		scanf("%s",b+1);
		int q;
		scanf("%d",&q);
		int len=0;
		while(b[++len]!='\0');
		len--;
		for(int j=1;j<=n-len+1;j++){
			if(match(s+j,b+1,len)){
				seg[++m].l=j;
				seg[m].r=j+len-1;
				seg[m].x=q;
				num[seg[m].l]++;
				num[seg[m].r+1]--;
				sum+=q;
			}
		}
	}
	int X;
	scanf("%d",&X);
	for(int i=1;i<=n;i++){
		x[i]=X;
	}
	S=n+2;
	T=n+3;
	for(int i=1;i<=n;i++){
		add_edge(i,i+1,x[i],0);
	}
	for(int i=1;i<=m;i++){
		add_edge(seg[i].l,seg[i].r+1,1,seg[i].x);
	}
	for(int i=1;i<=n+1;i++){
		if(num[i]>0){
			add_edge(S,i,num[i],0);
		}
		else{
			add_edge(i,T,-num[i],0);
		}
	}
	int ans;
	Dinic(ans);
	printf("%d\n",sum-ans);
	return 0;
}