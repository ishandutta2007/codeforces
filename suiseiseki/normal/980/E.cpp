#include <cstdio>
#include <vector>
using namespace std;
#define Maxn 1000000
vector<int> ed[Maxn+5];
int n,m;
int fa[Maxn+5];
bool can[Maxn+5];
int sz[Maxn+5];
int f[Maxn+5];
int dfn[Maxn+5];
int dep[Maxn+5];
void add(int x,int a){
	for(int i=x;i<=n;i+=(i&(-i))){
		f[i]+=a;
	}
}
int sum(int x){
	int ans=0;
	for(int i=x;i>0;i-=(i&(-i))){
		ans+=f[i];
	}
	return ans;
}
int tot;
void dfs(int x){
	sz[x]=1;
	dep[x]=dep[fa[x]]+1;
	dfn[x]=++tot;
	for(int i=0;i<(int)ed[x].size();i++){
		if(ed[x][i]!=fa[x]){
			fa[ed[x][i]]=x;
			dfs(ed[x][i]);
			sz[x]+=sz[ed[x][i]];
		}
	}
}
int find(int x){
	return dep[x]+sum(dfn[x]);
}
void work(int x){
	if(can[x]){
		return;
	}
	work(fa[x]);
	can[x]=1;
	add(dfn[x],-1);
	add(dfn[x]+sz[x],1);
}
int ans[Maxn+5];
int main(){
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		ed[u].push_back(v);
		ed[v].push_back(u);
	}
	can[0]=1;
	dfs(n);
	work(n);
	int now=1,tmp;
	int len=0;
	for(int i=n-1;i>0;i--){
		if(can[i]){
			continue;
		}
		tmp=find(i);
		if(now+tmp<=n-m){
			now+=tmp;
			work(i);
		}
		else{
			ans[++len]=i;
		}
	}
	for(int i=len;i>0;i--){
		printf("%d ",ans[i]);
	}
	puts("");
	return 0;
}