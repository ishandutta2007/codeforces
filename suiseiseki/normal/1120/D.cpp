#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Maxn=200000;
ll ans;
int cnt;
int L,R;
int u,v;
int n,T;
int w[Maxn+5],fa[Maxn+5],sz[Maxn+5];
bool vis[Maxn+5];
int head[Maxn+5];
int l[Maxn+5],r[Maxn+5];
int f[Maxn+5];
struct Edge{
	int v,nxt;
}edge[Maxn<<1|5];
struct Node{
    int u,v,w,o;
}E[Maxn+5];
bool cmp(Node p1,Node p2){
	return p1.w<p2.w;
}
int getfa(int x){
	return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
void add_edge(int u,int v){
	edge[++cnt]=(Edge){v,head[u]};
	head[u]=cnt;
}
void dfs(int x){
	sz[x]=1;
	vis[x]=1;
	for(int i=head[x];i;i=edge[i].nxt){
		int v=edge[i].v;
		if(!vis[v]){
			dfs(v);
			sz[x]+=sz[v];
			l[x]=min(l[x],l[v]);
			r[x]=max(r[x],r[v]);
		}
	}
	if(sz[x]==1){
		l[x]=r[x]=++T;
	}
	E[x]=(Node){l[x],r[x]+1,w[x],x};
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	memset(l,0x3f,sizeof l);
	dfs(1);
	sort(E+1,E+n+1,cmp);
	for(int i=1;i<=T+1;i++){
		fa[i]=i;
	}
	int sum=0;
	for(L=1;L<=n;L=R+1){
		R=L;
		while(E[R+1].w==E[L].w&&R<n){
			R++;
		}
		for(int i=L;i<=R;i++){
			u=E[i].u,v=E[i].v;
			if(getfa(u)!=getfa(v)){
				f[E[i].o]=1;
				sum++;
			}
		}
		for(int i=L;i<=R;i++){
			u=E[i].u,v=E[i].v;
			if(getfa(u)!=getfa(v)){
				ans+=1ll*E[i].w;
				fa[fa[u]]=fa[v];
			}
		}
	}
	printf("%lld %d\n",ans,sum);
	for(int i=1;i<=n;i++){
		if(f[i]){
			printf("%d ",i);
		}
	}
	puts("");
	return 0;
}