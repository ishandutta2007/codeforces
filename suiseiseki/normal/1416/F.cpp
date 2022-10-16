#include <cstdio>
#include <cstring>
void read(int &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
template<typename Elem_1,typename Elem_2>
Elem_1 min(Elem_1 a,Elem_2 b){
	return a<b?a:b;
}
const int Maxn=100000;
const int Maxm=1000000;
const int Inf=0x3f3f3f3f;
const int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char D[4]={'R','L','D','U'};
struct Edge{
	int to,nxt,val;
	int cap,flow;
}edge[Maxm<<1|5];
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
int n,m;
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
		if((f=Dinic_dfs(v,op,min_cost))){
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
bool _in[Maxn+5];
char _s[Maxn+5];
int _a[Maxn+5],_id[Maxn+5],_w[Maxn+5];
int *a[Maxn+5],*id[Maxn+5],*w[Maxn+5];
bool *in[Maxn+5];
char *s[Maxn+5];
int id_tot;
void init(){
	int last=0;
	for(int i=1;i<=n;i++){
		a[i]=_a+last;
		id[i]=_id+last;
		w[i]=_w+last;
		s[i]=_s+last;
		in[i]=_in+last;
		last+=m;
	}
	id_tot=tot=0;
	for(int i=1;i<=n*m+2;i++){
		_a[i]=_id[i]=_w[i]=head[i]=0;
		_in[i]=0;
		_s[i]='\0';
	}
}
char find_c(int nx,int ny){
	for(int i=0;i<4;i++){
		if(d[i][0]==nx&&d[i][1]==ny){
			return D[i];
		}
	}
	return '?';
}
int get_x(int id){
	return (id-1)/m+1;
}
int get_y(int id){
	return id%m==0?m:id%m;
}
void solve(){
	read(n),read(m);
	if(n==1&&m==1){
		puts("NO");
		return;
	}
	init();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			read(a[i][j]);
			id[i][j]=++id_tot;
		}
	}
	S=++id_tot;
	T=++id_tot;
	int num=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			in[i][j]=1;
			for(int k=0;k<4;k++){
				int nx=i+d[k][0],ny=j+d[k][1];
				if(nx<1||ny<1||nx>n||ny>m){
					continue;
				}
				if(a[nx][ny]<a[i][j]){
					in[i][j]=0;
					break;
				}
			}
			num+=in[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if((i+j)&1){
				continue;
			}
			for(int k=0;k<4;k++){
				int nx=i+d[k][0],ny=j+d[k][1];
				if(nx<1||ny<1||nx>n||ny>m){
					continue;
				}
				if(a[nx][ny]==a[i][j]){
					add_edge(id[i][j],id[nx][ny],1,0);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if((i+j)&1){
				add_edge(id[i][j],T,1,-(int)in[i][j]);
			}
			else{
				add_edge(S,id[i][j],1,-(int)in[i][j]);
			}
		}
	}
	int ans_2;
	Dinic(ans_2);
	ans_2=-ans_2;
	if(ans_2<num){
		puts("NO");
		return;
	}
	for(int i=head[S];i;i=edge[i].nxt){
		if(edge[i].flow==1){
			int u=edge[i].to;
			for(int j=head[u];j;j=edge[j].nxt){
				if(edge[j].flow==1){
					int v=edge[j].to;
					int u_x=get_x(u),u_y=get_y(u),v_x=get_x(v),v_y=get_y(v);
					s[u_x][u_y]=find_c(v_x-u_x,v_y-u_y);
					s[v_x][v_y]=find_c(u_x-v_x,u_y-v_y);
					w[u_x][u_y]=1;
					w[v_x][v_y]=a[u_x][u_y]-1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]=='\0'){
				for(int k=0;k<4;k++){
					int nx=i+d[k][0],ny=j+d[k][1];
					if(nx<1||ny<1||nx>n||ny>m||a[nx][ny]>=a[i][j]){
						continue;
					}
					s[i][j]=D[k];
					w[i][j]=a[i][j]-a[nx][ny];
					break;
				}
			}
		}
	}
	puts("YES");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%d ",w[i][j]);
		}
		puts("");
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			putchar(s[i][j]);
			putchar(' ');
		}
		puts("");
	}
}
int main(){
	int T;
	read(T);
	while(T--){
		solve();
	}
	return 0;
}
/*
I forget it Again...
*/