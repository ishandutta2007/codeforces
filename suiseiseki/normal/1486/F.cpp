#include <map>
#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int Maxp=300000;
const int Maxm=300000;
const int Maxn=900000;
int n,m;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int fa[Maxp+5];
int dep[Maxp+5],sz[Maxp+5],son[Maxp+5],dfn[Maxp+5],top[Maxp+5],seq[Maxn+5],dfn_tot;
void init_dfs_1(int u){
	sz[u]=1;
	dep[u]=dep[fa[u]]+1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[u]){
			continue;
		}
		fa[v]=u;
		init_dfs_1(v);
		sz[u]+=sz[v];
		if(son[u]==0||(sz[son[u]]<sz[v])){
			son[u]=v;
		}
	}
}
void init_dfs_2(int u,int tp){
	top[u]=tp;
	dfn[u]=++dfn_tot;
	seq[dfn[u]]=u;
	if(son[u]){
		init_dfs_2(son[u],tp);
	}
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa[u]||v==son[u]){
			continue;
		}
		init_dfs_2(v,v);
	}
}
int find_lca(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]){
			swap(u,v);
		}
		u=fa[top[u]];
	}
	if(dep[u]>dep[v]){
		swap(u,v);
	}
	return u;
}
int find_son(int u,int v){
	while(1){
		if(fa[u]==v){
			return u;
		}
		if(u==top[u]){
			u=fa[u];
		}
		if(dep[top[u]]>dep[v]){
			u=top[u];
		}
		if(top[u]==top[v]){
			return seq[dfn[v]+1];
		}
	}
}
ll ans;
int tag[Maxn+5];
vector<pair<int,int> > lis[Maxn+5];
void work_dfs(int u,int fa){
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		work_dfs(v,u);
		tag[u]+=tag[v];
	}
	vector<pair<int,int> > &lis=::lis[u];
	static int cnt[Maxn+5];
	map<pair<int,int>,int> t;
	for(int i=0;i<(int)lis.size();i++){
		int &v_1=lis[i].first,&v_2=lis[i].second;
		tag[v_1]--;
		tag[v_2]--;
		tag[u]-=2;
		if(v_1>v_2){
			swap(v_1,v_2);
		}
		ans+=i-cnt[v_1]-cnt[v_2]+t[lis[i]];
		t[lis[i]]++;
		cnt[v_1]++;
		cnt[v_2]++;
	}
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		ans+=1ll*tag[v]*((int)lis.size()-cnt[v]);
	}
	for(int i=0;i<(int)lis.size();i++){
		cnt[lis[i].first]=cnt[lis[i].second]=0;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	init_dfs_1(1);
	init_dfs_2(1,1);
	scanf("%d",&m);
	for(int t=1;t<=m;t++){
		int u,v;
		scanf("%d%d",&u,&v);
		int lca=find_lca(u,v);
		int s_u=(lca==u?n+1:find_son(u,lca));
		n++;
		add_edge(u,n);
		add_edge(n,u);
		u=n;
		int s_v=(lca==v?n+1:find_son(v,lca));
		n++;
		add_edge(v,n);
		add_edge(n,v);
		v=n;
		tag[u]++;
		tag[v]++;
		lis[lca].push_back(make_pair(s_u,s_v));
	}
	work_dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}