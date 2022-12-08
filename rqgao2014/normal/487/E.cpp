#include<bits/stdc++.h>
#define pb push_back
#define ls k<<1
#define rs k<<1|1
using namespace std;

const int N=200005;
struct node{
	int to,next;
}p[N];
int n,m,q,head[N],tot,w[N],up[N],fa[N],si[N],dep[N];
int son[N];
inline void add(int x,int y){
//	printf("%d %d\n",x,y);
	p[++tot].to=y;p[tot].next=head[x];head[x]=tot;
}
bool tag[N];
multiset<int> s[N];
vector<int> g[N];
int dfn[N],low[N],sta[N],bel[N],num[N],top,TOT,cnt;
inline void tarjan(int x,int fa){
	dfn[x]=low[x]=++TOT;sta[++top]=x;
	int t=g[x].size();
	for(int i=0;i<t;i++){
		int y=g[x][i];
		if(y==fa) continue;
		if(dfn[y]) low[x]=min(low[x],dfn[y]); else{
			tarjan(y,x);
			if(low[y]>=dfn[x]){
				++cnt;int k=0;
				do{
					k=sta[top--];bel[k]=cnt;
					add(cnt,k);s[cnt].insert(w[k]);
				}while(k!=y);
				add(x,cnt);
			}
			else low[x]=min(low[x],low[y]);
		}
	}
}
inline void dfs(int x){
	si[x]=1;
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		dfs(y);
		si[x]+=si[y];
		if(si[y]>si[son[x]]) son[x]=y;
	}
}
inline void dfs2(int x){
//	printf("%d ",x);
	num[x]=++tot;up[num[x]]=num[x];
	if(x>n) tag[num[x]]=1;
	if(son[x]){
		dfs2(son[x]);
		up[num[son[x]]]=num[x];
		fa[num[son[x]]]=num[x];
	}
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		if(y==son[x]) continue;
		dfs2(y);
		fa[num[y]]=num[x];
	}
}
inline int find(int x){
	if(up[x]!=x) up[x]=find(up[x]);
	return up[x];
}
int c[N<<2];
inline void change(int l,int r,int x,int k,int b){
	if(l==r){
		c[k]=b;return;
	}
	int mid=l+r>>1;
	if(x<=mid) change(l,mid,x,ls,b);
	else change(mid+1,r,x,rs,b);
	c[k]=min(c[ls],c[rs]);
}
inline int get(int l,int r,int x,int y,int k){
	if(l==x&&y==r) return c[k];
	int mid=l+r>>1,res=1<<30;
	if(x<=mid) res=min(res,get(l,mid,x,min(y,mid),ls));
	if(y>mid) res=min(res,get(mid+1,r,max(mid+1,x),y,rs));
	return res;
}

int main(){
	scanf("%d%d%d",&n,&m,&q);cnt=n;
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].pb(y);g[y].pb(x);
	}
	TOT=0;tarjan(1,0);
	dfs(1);tot=0;dfs2(1);
//	puts("");for(int i=1;i<=cnt;i++) printf("%d ",tag[i]);puts("");
	for(int i=1;i<=cnt;i++) up[i]=find(up[i]);
	for(int i=1;i<=cnt;i++) dep[i]=dep[fa[i]]+1;
	for(int i=1;i<=n;i++) change(1,cnt,num[i],1,w[i]);
	for(int i=n+1;i<=cnt;i++) change(1,cnt,num[i],1,*s[i].begin());
//	return 0;
	while(q--){
		char tmp[10];int u,v;
		scanf("%s",tmp);
		scanf("%d%d",&u,&v);
		if(tmp[0]=='A'){
			u=num[u];v=num[v];
			int ans=1<<30;
			while(up[u]!=up[v]){
				if(dep[up[u]]<dep[up[v]]) swap(u,v);
				ans=min(ans,get(1,cnt,up[u],u,1));
				u=fa[up[u]];
			}
//			printf("%d %d\n",u,v);
			if(dep[u]>dep[v]) swap(u,v);
			ans=min(ans,get(1,cnt,u,v,1));
			if(tag[u]) ans=min(ans,get(1,cnt,fa[u],fa[u],1));
			printf("%d\n",ans);
		}
		else{
			change(1,cnt,num[u],1,v);
			int k=bel[u];
			if(!k) continue;
			s[k].erase(s[k].find(w[u]));
			w[u]=v;s[k].insert(v);
			change(1,cnt,num[k],1,*s[k].begin());
		}
	}
	return 0;
}
/*
7 9 4
1
2
3
4
5
6
7
1 2
2 5
1 5
2 3
3 4
2 4
5 6
6 7
5 7
A 2 3
A 6 4
A 6 7
A 3 3
*/