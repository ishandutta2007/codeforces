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
int n,m;
int dep[400010],fa[400010];
int siz[400010],son[400010],top[400010];
int tot;
int belong[200010];
int cnt[200010];
int head[400010],nxt[800010],to[800010];
int fath[400010];
void add(int x,int y){
	nxt[++tot]=head[x],head[x]=tot,to[tot]=y;
}
void dfs1(int p,int f){
	dep[p]=dep[f]+1;
	fa[p]=f;
	siz[p]=1;
	for(int i=head[p];i;i=nxt[i]){
		if(to[i]==f) continue ;
		dfs1(to[i],p);
		siz[p]+=siz[to[i]];
		if(siz[to[i]]>siz[son[p]]) son[p]=to[i];
	}
}
void dfs2(int x,int topf){
	top[x]=topf;
	if(!son[x]) return ;
	dfs2(son[x],topf);
	for(int i=head[x];i;i=nxt[i]){
		if(to[i]==fa[x]||to[i]==son[x]) continue ;
		dfs2(to[i],to[i]);
	}
}
inline int LCA(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	return x;
}
inline int find(int x){
	if(fath[x]==x) return x;
	return fath[x]=find(fath[x]);
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i) belong[i]=read();
	for(int i=1;i<=m+m;++i) fath[i]=i;
	for(int i=1;i<m;++i){
		int x=read(),y=read();
		int fx=find(x),fy=find(y);
		add(i+m,fx);add(i+m,fy);
		fath[fx]=fath[fy]=i+m;
	}
	dfs1(m+m-1,m+m-1);
	dfs2(m+m-1,m+m-1);
	for(int i=1;i<n;++i){
		int lca=LCA(belong[i],belong[i+1]);
		if(lca<=m) ++cnt[0];
		else ++cnt[lca-m];
	}
	for(int i=0;i<m-1;++i) cnt[i+1]+=cnt[i];
	for(int i=0;i<m;++i) printf("%d\n",n-1-cnt[i]);
	return 0;
}