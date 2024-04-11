#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Maxn=200000;
const int Maxm=200000;
const ll Inf=0x3f3f3f3f3f3f3f3fll;
int head[Maxn+5],arrive[Maxm<<1|5],nxt[Maxm<<1|5],val[Maxm<<1|5],tot;
void add_edge(int from,int to,int w){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	val[tot]=w;
	head[from]=tot;
}
int n,m,Q;
struct Edge{
	int u,v,w;
}edge[Maxm+5];
bool in_e[Maxm+5];
ll dis[2][Maxn+5];
int lst[2][Maxn+5];
bool in[Maxn+5];
int lis[Maxn+5],lis_len;
int id[Maxn+5];
int pre[2][Maxn+5];
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
void dij(int S,ll *dis,int *lst,int *pre){
	memset(dis,0x3f,(sizeof (long long))*(n+1));
	while(!q.empty()){
		q.pop();
	}
	dis[S]=0;
	q.push(make_pair(0,S));
	while(!q.empty()){
		int u=q.top().second;
		if(q.top().first!=dis[u]){
			q.pop();
			continue;
		}
		q.pop();
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			if(dis[u]+val[i]<dis[v]){
				dis[v]=dis[u]+val[i];
				lst[v]=u;
				pre[v]=((i+1)>>1);
				q.push(make_pair(dis[v],v));
			}
		}
	}
}
void work_bfs(int *lst){
	static vector<int> g[Maxn+5];
	static int qu[Maxn+5],qu_f,qu_t;
	qu_f=1,qu_t=0;
	for(int i=1;i<=n;i++){
		g[i].clear();
	}
	for(int i=1;i<=n;i++){
		if(in[i]){
			lst[i]=i;
			qu[++qu_t]=i;
			continue;
		}
		g[lst[i]].push_back(i);
	}
	while(qu_f<=qu_t){
		int u=qu[qu_f++];
		while(!in[lst[u]]){
			lst[u]=lst[lst[u]];
		}
		for(int i=0;i<(int)g[u].size();i++){
			int v=g[u][i];
			qu[++qu_t]=v;
		}
	}
}
ll minn[Maxn<<2|5];
void update(int l,int r,ll a,int root=1,int left=1,int right=lis_len-1){
	if(l>right||r<left||l>r){
		return;
	}
	if(l<=left&&r>=right){
		minn[root]=min(minn[root],a);
		return;
	}
	int mid=(left+right)>>1;
	update(l,r,a,root<<1,left,mid);
	update(l,r,a,root<<1|1,mid+1,right);
}
ll query(int x,int root=1,int left=1,int right=lis_len-1){
	if(left==right){
		return minn[root];
	}
	int mid=(left+right)>>1;
	if(x<=mid){
		return min(minn[root],query(x,root<<1,left,mid));
	}
	else{
		return min(minn[root],query(x,root<<1|1,mid+1,right));
	}
}
bool vis[Maxn+5];
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
		edge[i].u=u;
		edge[i].v=v;
		edge[i].w=w;
	}
	dij(1,dis[0],lst[0],pre[0]);
	dij(n,dis[1],lst[1],pre[1]);
	{
		int u=n;
		while(u){
			in[u]=1;
			lis[++lis_len]=u;
			in_e[pre[0][u]]=1;
			u=lst[0][u];
		}
	}
	reverse(lis+1,lis+1+lis_len);
	for(int i=1;i<=lis_len;i++){
		id[lis[i]]=i;
	}
	work_bfs(lst[0]);
	work_bfs(lst[1]);
	memset(minn,0x3f,sizeof minn);
	for(int i=1;i<=m;i++){
		if(dis[0][edge[i].u]>dis[0][edge[i].v]){
			swap(edge[i].u,edge[i].v);
		}
		if(in_e[i]){
			if(id[edge[i].u]>id[edge[i].v]){
				swap(edge[i].u,edge[i].v);
			}
			continue;
		}
		update(id[lst[0][edge[i].u]],id[lst[1][edge[i].v]]-1,dis[0][edge[i].u]+dis[1][edge[i].v]+edge[i].w);
		update(id[lst[0][edge[i].v]],id[lst[1][edge[i].u]]-1,dis[0][edge[i].v]+dis[1][edge[i].u]+edge[i].w);
	}
	for(int i=1;i<=Q;i++){
		int t,x;
		scanf("%d%d",&t,&x);
		ll ans;
		if(in_e[t]){
			ans=query(id[edge[t].u]);
			ans=min(ans,dis[0][edge[t].u]+dis[1][edge[t].v]+x);
			ans=min(ans,dis[0][edge[t].v]+dis[1][edge[t].u]+x);
		}
		else{
			ans=dis[0][n];
			ans=min(ans,dis[0][edge[t].u]+dis[1][edge[t].v]+x);
			ans=min(ans,dis[0][edge[t].v]+dis[1][edge[t].u]+x);
		}
		printf("%lld\n",ans);
	}
	return 0;
}