#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn=500000;
const int Maxm=1000000;
int head[Maxn+5],arrive[Maxm<<1|5],nxt[Maxm<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int n,m;
int dep[Maxn+5];
int fa[Maxn+5];
vector<int> lis[Maxn+5];
vector<pair<int,int> > ans;
void dfs(int u){
	dep[u]=dep[fa[u]]+1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(dep[v]==0){
			fa[v]=u;
			dfs(v);
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		tot=0;
		for(int i=1;i<=n;i++){
			head[i]=0;
		}
		for(int i=1;i<=m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			add_edge(u,v);
			add_edge(v,u);
		}
		for(int i=1;i<=n;i++){
			fa[i]=0;
			dep[i]=0;
		}
		dfs(1);
		int root=0;
		for(int i=1;i<=n;i++){
			if(dep[i]>dep[root]){
				root=i;
			}
		}
		for(int i=1;i<=n;i++){
			fa[i]=0;
			dep[i]=0;
		}
		dfs(root);
		for(int i=1;i<=n;i++){
			if(dep[i]>dep[root]){
				root=i;
			}
		}
		if(dep[root]>=((n+1)>>1)){
			puts("PATH");
			printf("%d\n",dep[root]);
			while(root){
				printf("%d ",root);
				root=fa[root];
			}
			puts("");
			continue;
		}
		puts("PAIRING");
		for(int i=1;i<=n;i++){
			lis[dep[i]].push_back(i);
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j+1<(int)lis[i].size();j+=2){
				ans.push_back(make_pair(lis[i][j],lis[i][j+1]));
			}
			lis[i].clear();
		}
		printf("%d\n",(int)ans.size());
		for(int i=0;i<(int)ans.size();i++){
			printf("%d %d\n",ans[i].first,ans[i].second);
		}
		ans.clear();
	}
	return 0;
}