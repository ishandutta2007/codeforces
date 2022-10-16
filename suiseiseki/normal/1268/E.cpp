#include <vector>
#include <cstdio>
#include <algorithm>
const int Maxn=1000000;
const int Inf=0x3f3f3f3f;
std::vector<std::pair<int,int> > g[Maxn+5];
int cir[Maxn+5],maxn[Maxn+5],minn[Maxn+5],id[Maxn+5];
bool able[Maxn+5];
int cnt;
void work(){
	if(cir[0]==1){
		return;
	}
	int x,y;
	cnt++;
	maxn[cnt]=0,minn[cnt]=Inf;
	for(int i=1;i<=cir[0];i++){
		id[cir[i]]=cnt;
		if(cir[i]>maxn[cnt]){
			maxn[cnt]=cir[i];
			x=i;
		}
		if(cir[i]<minn[cnt]){
			minn[cnt]=cir[i];
			y=i;
		}
	}
	able[cnt]=1;
	for(int i=1;i<=cir[0];i++){
		cir[i+cir[0]]=cir[i];
	}
	int tmp_x=x,tmp_y=y;
	if(x>y){
		tmp_y+=cir[0];
	}
	for(int i=tmp_x;i<tmp_y;i++){
		if(cir[i]<cir[i+1]){
			able[cnt]=0;
		}
	}
	tmp_x=x,tmp_y=y;
	if(x<y){
		tmp_x+=cir[0];
	}
	for(int i=tmp_x;i>tmp_y;i--){
		if(cir[i]<cir[i-1]){
			able[cnt]=0;
		}
	}
}
int fa[Maxn+5],fa_val[Maxn+5];
int dfn[Maxn+5],dfn_tot;
int f_1[Maxn+5],f_2[Maxn+5];
void init_dfs(int u){
	dfn[u]=++dfn_tot;
	f_2[u]=1;
	for(std::pair<int,int> cur_v:g[u]){
		int v=cur_v.first,w=cur_v.second;
		if(v==fa[u]){
			continue;
		}
		if(dfn[v]==0){
			fa[v]=u,fa_val[v]=w;
			init_dfs(v);
		}
		else if(dfn[v]==-1){
			cir[0]=0;
			for(int x=v;x!=u;x=fa[x]){
				cir[++cir[0]]=fa_val[x];
			}
			cir[++cir[0]]=w;
			work();
		}
	}
	dfn[u]=-1;
}
struct Edge{
	int u,v;
	Edge(int _u=0,int _v=0){
		u=_u,v=_v;
	}
}edge[Maxn+5];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=m;i>0;i--){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(std::make_pair(v,i)),g[v].push_back(std::make_pair(u,i));
		edge[i]=Edge(u,v);
	}
	init_dfs(1);
	for(int i=1;i<=m;i++){
		int u=edge[i].u,v=edge[i].v;
		f_1[i]=f_2[u]+f_2[v];
		if(able[id[i]]&&i==maxn[id[i]]){
			f_1[i]-=f_1[minn[id[i]]];
		}
		f_2[u]=f_1[i],f_2[v]=f_1[i];
	}
	for(int i=1;i<=n;i++){
		printf("%d ",f_2[i]-1);
	}
	puts("");
	return 0;
}