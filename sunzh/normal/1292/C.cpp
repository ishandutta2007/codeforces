#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
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
int n;
int tot;
int head[3010],nxt[6010],to[6010];
int fa[3010][3010];
int siz[3010][3010];
int f[3010][3010];
void add(int x,int y){
	nxt[++tot]=head[x],head[x]=tot,to[tot]=y;
}
void dfs(int x,int f,int ff){
	fa[ff][x]=f;siz[ff][x]=1;
	for(int i=head[x];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue ;
		dfs(v,x,ff);
		siz[ff][x]+=siz[ff][v];
	}
}
int dp(int u,int v){
	if(u==v) return 0;
	if(f[u][v]!=-1) return f[u][v];
	return f[u][v]=siz[u][v]*siz[v][u]+max(dp(fa[v][u],v),dp(u,fa[u][v]));
}

signed main(){
	memset(f,-1,sizeof(f));
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		add(u,v),add(v,u);
	}
	for(int i=1;i<=n;++i) dfs(i,0,i);
	int ans=0;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j) ans=max(ans,dp(i,j));
	print(ans);
	return 0;
}