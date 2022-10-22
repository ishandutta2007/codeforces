#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define pb push_back
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) print(x/10);
	putchar(x%10+48);
}
bool vis[200010];
int n,m;
int tot;
int head[200010],nxt[400010],to[400010];
pair<int,int>e[200010];
int dep[200010],fath[200010];
bool flag;
vector<int>path;
int LCA(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y]) x=fath[x];
	while(x!=y) x=fath[x],y=fath[y];
	return x;
} 
void add(int x,int y){
	nxt[++tot]=head[x],head[x]=tot,to[tot]=y;
}
void getans(int x,int y,int u,int v){
	printf("YES\n");
	int lca=LCA(y,v);
	int fa=(dep[x]>dep[u]?x:u);
	for(int j=lca;j!=fa;j=fath[j]) path.pb(j);
	path.pb(fa);
	printf("%d ",path.size());
	for(int i=path.size()-1;i>=0;--i) printf("%d ",path[i]);
	path.clear();printf("\n");
	
	for(int j=fa;j!=x;j=fath[j]) path.pb(j);
	path.pb(x);
	for(int j=y;j!=lca;j=fath[j]) path.pb(j);
	path.pb(lca);
	printf("%d ",path.size());
	for(auto i:path) printf("%d ",i);
	path.clear();printf("\n");
	
	for(int j=fa;j!=u;j=fath[j]) path.pb(j);
	path.pb(u);
	for(int j=v;j!=lca;j=fath[j]) path.pb(j);
	path.pb(lca);
	printf("%d ",path.size());
	for(auto i:path) printf("%d ",i);
	printf("\n");
	exit(0);
}
void dfs(int x,int fa){
	vis[x]=1;fath[x]=fa;
	dep[x]=dep[fa]+1;
	for(int i=head[x];i;i=nxt[i]){
		int v=to[i];
		if(v==fa) continue ;
		if(!vis[v]){
			dfs(v,x);
		}
		else if(dep[v]<dep[x]){
			for(int j=x;j!=v;j=fath[j]){
				if(e[j].fi&&e[j].se){
					getans(e[j].fi,e[j].se,v,x);
					flag=1;
					return ;
				}
				else e[j].fi=v,e[j].se=x;
			}
		}
		if(flag) return ;
	}
//	vis[x]=0;
}
int main(){
	memset(e,0,sizeof(e));
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	for(int i=1;i<=n;++i) if(!vis[i]) dfs(i,0);
	if(!flag) printf("NO\n");
}