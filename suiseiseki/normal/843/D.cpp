#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
typedef long long ll;
const int Maxn=100000;
const ll Inf_ll=0x3f3f3f3f3f3f3f3fll;
int n,m,q;
struct Edge{
	int u,v,w;
}edge[Maxn+5];
std::vector<int> g[Maxn+5];
ll dis[Maxn+5];
namespace Normal{
	void dij(){
		std::priority_queue<std::pair<ll,int>,std::vector<std::pair<ll,int> >,std::greater<std::pair<ll,int> > > q;
		memset(dis,0x3f,sizeof dis);
		dis[1]=0;
		q.push(std::make_pair(0ll,1));
		while(!q.empty()){
			std::pair<ll,int> cur_u=q.top();
			q.pop();
			int u=cur_u.second;
			if(dis[u]!=cur_u.first){
				continue;
			}
			for(int i:g[u]){
				int v=edge[i].v;
				if(dis[u]+edge[i].w<dis[v]){
					dis[v]=dis[u]+edge[i].w;
					q.push(std::make_pair(dis[v],v));
				}
			}
		}
		for(int i=1;i<=m;i++){
			edge[i].w=dis[edge[i].u]+edge[i].w-dis[edge[i].v];
		}
	}
}
namespace Special{
	std::vector<int> buc[Maxn+5];
	int delta[Maxn+5];
	void dij(std::vector<int> lis){
		for(int i:lis){
			edge[i].w++;
		}
		for(int i=1;i<=n;i++){
			delta[i]=n+1;
		}
		delta[1]=0;
		buc[0].push_back(1);
		for(int i=0;i<=std::min(n-1,(int)lis.size());i++){
			for(int U=0;U<(int)buc[i].size();U++){
				int u=buc[i][U];
				if(delta[u]!=i){
					continue;
				}
				for(int i:g[u]){
					int v=edge[i].v;
					if(delta[u]+edge[i].w<delta[v]){
						delta[v]=delta[u]+edge[i].w;
						buc[delta[v]].push_back(v);
					}
				}
			}
			buc[i].clear();
		}
		for(int i=1;i<=m;i++){
			edge[i].w=delta[edge[i].u]+edge[i].w-delta[edge[i].v];
		}
		for(int i=1;i<=n;i++){
			dis[i]+=delta[i];
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
		g[edge[i].u].push_back(i);
	}
	Normal::dij();
	for(int i=1;i<=q;i++){
		int op;
		scanf("%d",&op);
		if(op==1){
			int u;
			scanf("%d",&u);
			if(dis[u]>=Inf_ll){
				puts("-1");
			}
			else{
				printf("%lld\n",dis[u]);
			}
		}
		else{
			int len;
			scanf("%d",&len);
			std::vector<int> lis;
			for(int j=1;j<=len;j++){
				int id;
				scanf("%d",&id);
				lis.push_back(id);
			}
			Special::dij(lis);
		}
	}
	return 0;
}