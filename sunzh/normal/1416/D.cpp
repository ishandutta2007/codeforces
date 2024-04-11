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
int n,m,q;
int val[800010];
int fa[800010],siz[800010];
struct edge{
	int u,v;
}e[600010];
struct que{
	int op,x;
}Q[1000010];
bool used[600010];
vector<int>vec[800010];
int maxn[4000010];
int dfn[800010],pos[800010];
int idx;
int ps[400010];
inline int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy) return ;
	++n;
	vec[n].pb(fx),vec[n].pb(fy);
	fa[n]=fa[fx]=fa[fy]=n;siz[n]=siz[fx]+siz[fy]+1;
}
void dfs(int x){
	dfn[x]=++idx;pos[idx]=x;
	for(int i:vec[x]) dfs(i);
}
void pushup(int p){
	maxn[p]=max(maxn[p<<1],maxn[p<<1|1]);
}
void build(int p,int l,int r){
	if(l==r){
		maxn[p]=val[pos[l]];return ;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);build(p<<1|1,mid+1,r);
	pushup(p);
}
void update(int p,int l,int r,int pos,int k){
	if(l==r){
		maxn[p]=k;return ;
	}
	int mid=l+r>>1;
	if(pos<=mid) update(p<<1,l,mid,pos,k);
	else update(p<<1|1,mid+1,r,pos,k);
	pushup(p); 
}
int query(int p,int l,int r,int L,int R){
	if(l>=L&&r<=R){
		return maxn[p];
	}
	int mid=l+r>>1;
	int res=0;
	if(L<=mid) res=max(res,query(p<<1,l,mid,L,R));
	if(R>mid) res=max(res,query(p<<1|1,mid+1,r,L,R));
	return res;
}
int main(){
	n=read(),m=read(),q=read();
	for(int i=1;i<=n;++i){
		val[i]=read();fa[i]=i,siz[i]=1;ps[val[i]]=i;
	}
	for(int i=1;i<=m;++i) e[i].u=read(),e[i].v=read();
	for(int i=1;i<=q;++i){
		Q[i].op=read(),Q[i].x=read();
		if(Q[i].op==2) used[Q[i].x]=1;
	}
	for(int i=1;i<=m;++i){
		if(!used[i]) merge(e[i].u,e[i].v);
	}
	for(int i=q;i;--i){
		if(Q[i].op==2){
			merge(e[Q[i].x].u,e[Q[i].x].v);
		}
		else{
			Q[i].x=find(Q[i].x);
		}
	}
	fa[n+1]=n+1;
	for(int i=1;i<=n;++i) if(fa[i]==i){
		fa[i]=n+1;vec[n+1].pb(i);
	}
	++n;
	for(int i=1;i<=n;++i) if(fa[i]==i) dfs(i);
	build(1,1,idx);
	
	for(int i=1;i<=q;++i){
		if(Q[i].op==1){
			int ans=query(1,1,idx,dfn[Q[i].x],dfn[Q[i].x]+siz[Q[i].x]-1);
			printf("%d\n",ans);
			if(ans==0) continue ;
			update(1,1,idx,dfn[ps[ans]],0);
		}
	}
	return 0;
}