#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n;
vector<int>vec[200010],Vec[5000010];
int fa[200010],top[200010];
int siz[200010],son[200010];
int dep[200010],dfn[200010];
int Dfn[5000010],low[5000010];
int belong[5000010],stk[5000010];
int Top,scc;
bool vis[5000010];
vector<int>pas[400010];
int idx;
int m;
int nod;
void dfs1(int x,int f){
	fa[x]=f;
	dep[x]=dep[f]+1;
	siz[x]=1;
	for(int v:vec[x]){
		if(v==f) continue ;
		dfs1(v,x);
		if(siz[v]>siz[son[x]]) son[x]=v;
		siz[x]+=siz[v];
	}
}
void dfs2(int x,int topf){
//	printf("x:%d,topf:%d,son:%d,fa:%d\n",x,topf,son[x],fa[x]);
	dfn[x]=++idx;
	top[x]=topf;
	if(son[x]){
		dfs2(son[x],topf);
	}
	else return ;
	for(int v:vec[x]){
		if(v==son[x]||v==fa[x]) continue ;
		dfs2(v,v);
	}
}
void upd(int p,int l,int r,int L,int R,int id){
	if(l>=L&&r<=R){
		pas[p].pb(id);return ;
	}
	int mid=l+r>>1;
	if(L<=mid) upd(p<<1,l,mid,L,R,id);
	if(R>mid) upd(p<<1|1,mid+1,r,L,R,id);
}
void build(int p,int l,int r,int las){
	for(int i:pas[p]){
		int v=i;
		if(!las) las=v;
		else{
			nod+=2;
			Vec[las].pb(v^1);Vec[v].pb(nod);
			Vec[nod^1].pb(las^1),Vec[nod^1].pb(v^1),Vec[v].pb(las^1);
			Vec[las].pb(nod);
			las=nod;
		}
	}
	if(l==r) return ;
	int mid=l+r>>1;
	build(p<<1,l,mid,las);
	build(p<<1|1,mid+1,r,las);
}
void tarjan(int x){
	Dfn[x]=low[x]=++idx;vis[x]=1;stk[++Top]=x;
	for(int v:Vec[x]){
//		printf("x:%d,v:%d\n",x,v);
		if(!Dfn[v]){
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}
		else if(vis[v]) low[x]=min(low[x],Dfn[v]);
	}
	if(low[x]==Dfn[x]){
		++scc;
		while(stk[Top]!=x){
			belong[stk[Top]]=scc;vis[stk[Top]]=0;
			--Top;
		}
		belong[x]=scc,vis[x]=0;--Top;
	}
}
void addpth(int x,int y,int id){
//	printf("x:%d,y:%d\n",x,y);
	while(top[x]!=top[y]){
//		printf("x:%d,y:%d\n",x,y);
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		upd(1,1,idx,dfn[top[x]],dfn[x],id);
		x=fa[top[x]];
	}
	if(x==y) return ;
	if(dep[x]>dep[y]) swap(x,y);
	upd(1,1,idx,dfn[x]+1,dfn[y],id);
	return ;
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		vec[u].pb(v);vec[v].pb(u);
	}
	dfs1(1,1);
	dfs2(1,1);nod=0;
	m=read();
	for(int i=1;i<=m;++i){
		int a=read(),b=read(),c=read(),d=read();
		nod+=2;
		addpth(a,b,nod);
		addpth(c,d,nod^1);
	}
	build(1,1,idx,0);
	idx=0;//printf("nod:%d\n",nod);
	for(int i=2;i<nod+2;++i) if(!Dfn[i]) tarjan(i);
	for(int i=1;i<=m;++i)
	if(belong[i<<1]==belong[i<<1|1]){
//		printf("i:%d,belong:%d\n",i,belong[i<<1]);
		printf("NO\n");return 0;
	}
	printf("YES\n");
	for(int i=1;i<=m;++i){
//		printf("%d %d\n",belong[i<<1],belong[i<<1|1]);
		if(belong[i<<1]<belong[i<<1|1]){
			printf("1\n");
		}
		else printf("2\n");
	}
	return 0;
}