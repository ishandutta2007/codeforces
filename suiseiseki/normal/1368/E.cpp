#include <queue>
#include <cstdio>
#include <cassert>
#include <algorithm>
const int Maxn=200000;
int n,m;
struct Edge{
	int u,v;
}edge[Maxn*2+5];
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int deg[Maxn+5],num[Maxn+5],dis[Maxn+5];
int qu[Maxn+5],qu_f,qu_t;
bool del[Maxn+5];
/*struct Queue{
	std::priority_queue<int,std::vector<int>,std::greater<int> > q,p;
	int top(){
		return q.empty()?0:q.top();
	}
	int del(int x){
		p.push(x);
		while(!p.empty()&&q.top()==p.top()){
			p.pop(),q.pop();
		}
	}
	int push(int x){
		q.push(x);
	}
	void clear(){
		while(!q.empty()){
			q.pop();
		}
		while(!p.empty()){
			p.pop();
		}
	}
}q[Maxn+5];*/
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		head[i]=0;
		del[i]=0;
		deg[i]=0;
		dis[i]=0;
		num[i]=0;
		// q[i].clear();
	}
	tot=0;
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		deg[v]++;
		edge[i].u=u,edge[i].v=v;
	}
	qu_f=1,qu_t=0;
	for(int i=1;i<=n;i++){
		if(deg[i]==0){
			qu[++qu_t]=i;
		}
	}
	while(qu_f<=qu_t){
		int u=qu[qu_f++];
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			deg[v]--;
			if(deg[v]==0){
				qu[++qu_t]=v;
			}
		}
	}
	for(int i=1;i<=m;i++){
		deg[edge[i].v]++;
	}
	for(int i=1;i<=n;i++){
		int u=qu[i];
		for(int j=head[u];j;j=nxt[j]){
			int v=arrive[j];
			dis[v]=std::max(dis[v],dis[u]+1);
			if(dis[u]>0){
				num[v]++;
			}
		}
	}
	qu_f=1,qu_t=0;
	for(int i=1;i<=n;i++){
		if(num[i]==0&&deg[i]!=0){
			qu[++qu_t]=i;
		}
	}
	auto del_node_1=[&](int u){
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			if(del[v]){
				continue;
			}
			if(dis[u]>0){
				num[v]--;
				if(num[v]==0&&deg[v]!=0){
					qu[++qu_t]=v;
				}
			}
		}
	};
	auto del_node_2=[&](int u){
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			if(del[v]){
				continue;
			}
			deg[v]--;
			if(dis[u]>0){
				num[v]--;
				if(num[v]==0&&deg[v]!=0){
					qu[++qu_t]=v;
				}
			}
			if(deg[v]==0){
				del_node_1(v);
			}
		}
	};
	while(qu_f<=qu_t){
		int u=qu[qu_f++];
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			if(del[v]){
				continue;
			}
			del[v]=1;
			del_node_2(v);
		}
	}
	int sz=0;
	for(int i=1;i<=n;i++){
		if(del[i]){
			sz++;
		}
	}
	assert(7*sz<=4*n);
	printf("%d\n",sz);
	for(int i=1;i<=n;i++){
		if(del[i]){
			printf("%d ",i);
		}
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}