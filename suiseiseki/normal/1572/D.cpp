#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
typedef long long ll;
const int Maxn=(1<<15);
const int Maxm=(1<<22);
const int Inf_int=0x3f3f3f3f;
const ll Inf_ll=0x3f3f3f3f3f3f3f3fll;
int S,T;
struct Edge{
	int to;
	int flow,cap,val,nxt;
}edge[Maxm<<1|5];
int head[Maxn+5],tot;
void unuse_add_edge(int from,int to,int cap,int val){
	edge[++tot].to=to;
	edge[tot].cap=cap;
	edge[tot].val=val;
	edge[tot].flow=0;
	edge[tot].nxt=head[from];
	head[from]=tot;
}
void add_edge(int from,int to,int cap,int val){
	unuse_add_edge(from,to,cap,val);
	unuse_add_edge(to,from,0,-val);
}
ll dis[Maxn+5],h[Maxn+5];
int pre_node[Maxn+5],pre_edge[Maxn+5];
std::priority_queue<std::pair<ll,int>,std::vector<std::pair<ll,int> >,std::greater<std::pair<ll,int> > > q;
bool all_first;
bool in_q[Maxn+5];
bool MCMF_dij(){
	memset(dis,0x3f,sizeof dis);
	memset(pre_node,-1,sizeof pre_node);
	memset(pre_edge,-1,sizeof pre_edge);
	if(all_first){
		std::queue<int> q;
		q.push(S);
		dis[S]=0,in_q[S]=1;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			in_q[u]=0;
			for(int i=head[u];i;i=edge[i].nxt){
				int v=edge[i].to;
				if(edge[i].flow==edge[i].cap){
					continue;
				}
				if(dis[u]+edge[i].val<dis[v]){
					pre_node[v]=u;
					pre_edge[v]=i;
					dis[v]=dis[u]+edge[i].val;
					if(!in_q[v]){
						q.push(v);
						in_q[v]=1;
					}
				}
			}
		}
		all_first=0;
		return pre_node[T]!=-1;
	}
	while(!q.empty()){
		q.pop();
	}
	dis[S]=0;
	q.push(std::make_pair(dis[S],S));
	while(!q.empty()){
		std::pair<ll,int> u=q.top();
		q.pop();
		if(dis[u.second]!=u.first){
			continue;
		}
		for(int i=head[u.second];i;i=edge[i].nxt){
			int v=edge[i].to;
			if(edge[i].flow==edge[i].cap){
				continue;
			}
			if(dis[u.second]+edge[i].val-h[v]+h[u.second]<dis[v]){
				dis[v]=dis[u.second]+edge[i].val-h[v]+h[u.second];
				pre_node[v]=u.second;
				pre_edge[v]=i;
				q.push(std::make_pair(dis[v],v));
			}
		}
	}
	return pre_node[T]!=-1;
}
int MCMF_path(ll &min_cost){
	int min_flow=Inf_int;
	int u=T;
	while(u!=S){
		min_flow=std::min(min_flow,edge[pre_edge[u]].cap-edge[pre_edge[u]].flow);
		u=pre_node[u];
	}
	ll ans=0;
	u=T;
	while(u!=S){
		ans+=1ll*min_flow*edge[pre_edge[u]].val;
		edge[pre_edge[u]].flow+=min_flow;
		edge[((pre_edge[u]-1)^1)+1].flow-=min_flow;
		u=pre_node[u];
	}
	min_cost+=ans;
	return min_flow;
}
int n,k;
int re_id[1<<20|5],re_id_tot;
int MCMF(ll &min_cost){
	all_first=1;
	int ans=0;
	while(MCMF_dij()&&ans<k){
		ans+=MCMF_path(min_cost);
		for(int i=1;i<=re_id_tot;i++){
			h[i]+=dis[i];
		}
	}
	return ans;
}
int a[1<<20|5];
bool vis[1<<20|5];
std::vector<std::pair<int,std::pair<int,int> > > v_lis;
int main(){
	scanf("%d%d",&n,&k);
	k=std::min(k,(1<<n)>>1);
	int max_a=0;
	for(int i=0;i<(1<<n);i++){
		scanf("%d",&a[i]);
		max_a=std::max(max_a,a[i]);
	}
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if((i>>j)&1){
				int k=i^(1<<j);
				if(__builtin_popcount(i)&1){
					v_lis.push_back(std::make_pair(-a[i]-a[k],std::make_pair(i,k)));
				}
				else{
					v_lis.push_back(std::make_pair(-a[i]-a[k],std::make_pair(k,i)));
				}
			}
		}
	}
	int num=std::min((int)v_lis.size(),2*n*k);
	std::nth_element(v_lis.begin(),v_lis.begin()+num,v_lis.end());
	v_lis.resize(num);
	for(int i=0;i<(int)v_lis.size();i++){
		vis[v_lis[i].second.first]=vis[v_lis[i].second.second]=1;
	}
	for(int i=0;i<(1<<n);i++){
		if(vis[i]){
			re_id[i]=++re_id_tot;
		}
	}
	S=++re_id_tot;
	T=++re_id_tot;
	for(int i=0;i<(1<<n);i++){
		if(vis[i]){
			if(__builtin_popcount(i)&1){
				add_edge(S,re_id[i],1,max_a-a[i]);
			}
			else{
				add_edge(re_id[i],T,1,max_a-a[i]);
			}
		}
	}
	for(int i=0;i<(int)v_lis.size();i++){
		add_edge(re_id[v_lis[i].second.first],re_id[v_lis[i].second.second],1,0);
	}
	ll sum=0;
	MCMF(sum);
	printf("%lld\n",2ll*k*max_a-sum);
	return 0;
}