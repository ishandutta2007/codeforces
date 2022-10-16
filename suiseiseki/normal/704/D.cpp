#include <cstdio>
#include <cstring>
#include <algorithm>
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
typedef long long ll;
const int Maxn=100005;
const int Inf_int=0x7fffffff;
const ll Inf_ll=0x7ffffffffffffffll;
int n,m;
int r,b;
bool col_flag;
int e_id[Maxn+5];
struct Node{
	int x,y;
}a[Maxn+5];
int d_x[Maxn+5],d_x_len,d_y[Maxn+5],d_y_len;
struct Edge{
	int to,nxt,cap,flow;
}edge[Maxn*10+5];
int head[Maxn<<1|5],cur_h[Maxn<<1|5],tot;
int id_tot;
int S,T,super_S,super_T;
int id_x[Maxn+5],id_y[Maxn+5];
int num_x[Maxn+5],num_y[Maxn+5];
void unuse_unuse_add_edge(int from,int to,int cap){
	edge[++tot].to=to;
	edge[tot].nxt=head[from];
	edge[tot].cap=cap;
	edge[tot].flow=0;
	head[from]=tot;
}
void unuse_add_edge(int from,int to,int cap){
    if(cap==0){
        return;
    }
	unuse_unuse_add_edge(from,to,cap);
	unuse_unuse_add_edge(to,from,0);
}
int deg_sum[Maxn<<1|5];
void add_edge(int from,int to,int min_cost,int max_cost){
	unuse_add_edge(from,to,max_cost-min_cost);
	deg_sum[from]-=min_cost,deg_sum[to]+=min_cost;
}
ll all_sum;
void init_graph(){
	for(int i=1;i<=id_tot;i++){
		if(i==super_S||i==super_T){
			continue;
		}
		if(deg_sum[i]<0){
			unuse_add_edge(i,super_T,-deg_sum[i]);
		}
		else if(deg_sum[i]>0){
			all_sum+=deg_sum[i];
			unuse_add_edge(super_S,i,deg_sum[i]);
		}
	}
}
int val_x[Maxn+5],val_y[Maxn+5];
int qu[Maxn<<1|5],qu_f,qu_t;
int dep[Maxn<<1|5];
bool Dinic_bfs(int S,int T){
	qu_f=1,qu_t=0;
	memset(dep,0,sizeof dep);
	qu[++qu_t]=S;
	dep[S]=1;
	while(qu_f<=qu_t){
		int u=qu[qu_f++];
		for(int i=head[u];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(dep[v]>0||edge[i].flow==edge[i].cap){
				continue;
			}
			dep[v]=dep[u]+1;
			qu[++qu_t]=v;
		}
	}
	return dep[T]>0;
}
ll Dinic_dfs(int u,ll flow,int T){
	if(u==T||flow==0){
		return flow;
	}
	ll sum=0;
	for(int &i=cur_h[u];i;i=edge[i].nxt){
		int v=edge[i].to;
		if(dep[v]!=dep[u]+1||edge[i].flow==edge[i].cap){
			continue;
		}
		ll op=std::min(0ll+edge[i].cap-edge[i].flow,flow-sum),f;
		if((f=Dinic_dfs(v,op,T))){
			edge[i].flow+=f;
			edge[((i-1)^1)+1].flow-=f;
			sum+=f;
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
ll Dinic(int S,int T){
	ll ans=0;
	while(Dinic_bfs(S,T)){
        memcpy(cur_h,head,sizeof head);
		ans+=Dinic_dfs(S,Inf_ll,T);
	}
	return ans;
}
int main(){
	read(n),read(m),read(r),read(b);
	if(r>b){
		std::swap(r,b);
		col_flag=1;
	}
	for(int i=1;i<=n;i++){
		read(a[i].x),read(a[i].y);
		d_x[++d_x_len]=a[i].x,d_y[++d_y_len]=a[i].y;
	}
	std::sort(d_x+1,d_x+1+d_x_len);
	std::sort(d_y+1,d_y+1+d_y_len);
	d_x_len=std::unique(d_x+1,d_x+1+d_x_len)-d_x-1;
	d_y_len=std::unique(d_y+1,d_y+1+d_y_len)-d_y-1;
	for(int i=1;i<=d_x_len;i++){
		id_x[i]=++id_tot;
	}
	for(int i=1;i<=d_y_len;i++){
		id_y[i]=++id_tot;
	}
	S=++id_tot,T=++id_tot;
	for(int i=1;i<=n;i++){
		a[i].x=std::lower_bound(d_x+1,d_x+1+d_x_len,a[i].x)-d_x;
		a[i].y=std::lower_bound(d_y+1,d_y+1+d_y_len,a[i].y)-d_y;
		e_id[i]=tot+1;
		num_x[a[i].x]++,num_y[a[i].y]++;
		unuse_add_edge(id_x[a[i].x],id_y[a[i].y],1);
	}
	for(int i=1;i<=d_x_len;i++){
		val_x[i]=Inf_int;
	}
	for(int i=1;i<=d_y_len;i++){
		val_y[i]=Inf_int;
	}
	for(int i=1;i<=m;i++){
		int t,l,d;
		read(t),read(l),read(d);
		int val_l=l;
		if(t==1){
			l=std::lower_bound(d_x+1,d_x+1+d_x_len,l)-d_x;
			if(d_x[l]!=val_l){
				continue;
			}
			val_x[l]=std::min(val_x[l],d);
		}
		else{
			l=std::lower_bound(d_y+1,d_y+1+d_y_len,l)-d_y;
			if(d_y[l]!=val_l){
				continue;
			}
			val_y[l]=std::min(val_y[l],d);
		}
	}
	super_S=++id_tot,super_T=++id_tot;
	for(int i=1;i<=d_x_len;i++){
		int tmp_val=std::min(val_x[i],num_x[i]);
		int min_val=(num_x[i]-tmp_val+1)>>1,max_val=(num_x[i]+tmp_val)>>1;
		if(min_val>max_val){
			puts("-1");
			return 0;
		}
		add_edge(S,id_x[i],min_val,max_val);
	}
	for(int i=1;i<=d_y_len;i++){
		int tmp_val=std::min(val_y[i],num_y[i]);
		int min_val=(num_y[i]-tmp_val+1)>>1,max_val=(num_y[i]+tmp_val)>>1;
		if(min_val>max_val){
			puts("-1");
			return 0;
		}
		add_edge(id_y[i],T,min_val,max_val);
	}
	init_graph();
	unuse_add_edge(T,S,Inf_int);
	if(Dinic(super_S,super_T)!=all_sum){
		puts("-1");
		return 0;
	}
	ll ans=Dinic(S,T);
	printf("%lld\n",1ll*ans*r+1ll*(n-ans)*b);
	for(int i=1;i<=n;i++){
		if(edge[e_id[i]].flow==col_flag){
			putchar('b');
		}
		else{
			putchar('r');
		}
	}
	puts("");
	return 0;
}