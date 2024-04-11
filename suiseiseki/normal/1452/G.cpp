#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
const int Maxn=200000;
const int Inf=0x3f3f3f3f;
int n,k;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
queue<int> q;
int a[Maxn+5];
int dis[Maxn+5];
void init_bfs(){
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=k;i++){
		dis[a[i]]=0;
		q.push(a[i]);
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			if(dis[v]!=Inf){
				continue;
			}
			dis[v]=dis[u]+1;
			q.push(v);
		}
	}
}
int ans[Maxn+5];
bool del[Maxn+5];
int sz[Maxn+5];
int st[Maxn+5],top;
int dep[Maxn+5];
void size_dfs(int u,int fa){
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa||del[v]){
			continue;
		}
		size_dfs(v,u);
		sz[u]+=sz[v];
	}
}
int get_weight(int x){
	size_dfs(x,0);
	int num=sz[x];
	top=0;
	st[++top]=x;
	int maxn;
	int root=x,root_mx=sz[x]-1;
	while(top>0){
		int u=st[top--];
		maxn=num-sz[u];
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			if(del[v]||sz[v]>sz[u]){
				continue;
			}
			st[++top]=v;
			maxn=max(maxn,sz[v]);
		}
		if(maxn<root_mx){
			root=u;
			root_mx=maxn;
		}
	}
	return root;
}
void dep_sz_dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(del[v]||v==fa){
			continue;
		}
		dep_sz_dfs(v,u);
		sz[u]+=sz[v];
	}
}
int lis[Maxn+5],len;
int tot_sz;
void lis_dfs(int u,int fa){
	if(dis[u]-1-dep[u]>=0){
		lis[min(dis[u]-1-dep[u],tot_sz)]=max(lis[min(dis[u]-1-dep[u],tot_sz)],dis[u]);
	}
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(del[v]||v==fa){
			continue;
		}
		lis_dfs(v,u);
	}
}
void calc_dfs(int u,int fa){
	ans[u]=max(ans[u],lis[dep[u]]);
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(del[v]||v==fa){
			continue;
		}
		calc_dfs(v,u);
	}
}
void calc(int u){
	u=get_weight(u);
	dep_sz_dfs(u,0);
	tot_sz=sz[u];
	for(int i=0;i<=sz[u];i++){
		lis[i]=-Inf;
	}
	lis_dfs(u,0);
	for(int i=sz[u]-1;i>=0;i--){
		lis[i]=max(lis[i],lis[i+1]);
	}
	calc_dfs(u,0);
	del[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(del[v]){
			continue;
		}
		calc(v);
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
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		scanf("%d",&a[i]);
	}
	init_bfs();
	dep[0]=-1;
	calc(1);
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	puts("");
	return 0;
}