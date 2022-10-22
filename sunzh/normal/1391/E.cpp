#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) x=~x+1,putchar('-');
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int T;
int n,m;
int tot;
bool vis[500010];
int dep[500010];
int fa[500010];
vector<int>vec[500010];
vector<PII>ans;
int head[500010],nxt[2000010],to[2000010];
void dfs(int x,int f){
	dep[x]=dep[f]+1;fa[x]=f;vis[x]=1;vec[dep[x]].pb(x);
	for(int i=head[x];i;i=nxt[i]){
		int v=to[i];
		if(vis[v]) continue ;
		dfs(v,x);
	}
}
void getpth(int x){
	printf("PATH\n"); 
	printf("%d\n",dep[x]);
	while(x){
		printf("%d ",x);
		x=fa[x];
	}
}
void add(int x,int y){
	nxt[++tot]=head[x],head[x]=tot;to[tot]=y;
}
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		tot=0;
		for(int i=1;i<=n;++i) head[i]=vis[i]=fa[i]=0,vec[i].clear();
		for(int i=1;i<=m;++i){
			int u=read(),v=read();add(u,v),add(v,u);
		}
		int p;
		dfs(1,0);
		for(p=1;p<=n;++p){
			if((dep[p]<<1)>=n){
				getpth(p);
				break ;
			}
		}
		if(p==n+1){
			ans.clear();
			int p=-1;
			for(int i=1;i<=(n>>1);++i){
				p=-1;
				for(auto j:vec[i]){
					if(p==-1) p=j;
					else{
						ans.pb(mp(j,p));
						p=-1;
					}
				}
			}
			printf("PAIRING\n");
			printf("%d\n",ans.size());
			for(auto i:ans) printf("%d %d\n",i.fi,i.se);
		}
	}
}