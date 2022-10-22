#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
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
int n,m;
vector<PII>vec[100010];
vector<int>ans;
int sum[100010];
bool vis[100010],tree[100010];
int dep[100010];
int siz[100010],fa[100010],top[100010],son[100010],egn[100010];;
int id[100010],idx;
void dfs1(int x,int f){
	vis[x]=1;
	dep[x]=dep[f]+1;
	siz[x]=1;
	for(auto v:vec[x]){
		if(v.fi==f) continue ;
		if(vis[v.fi]) continue ;
		fa[v.fi]=x,egn[v.fi]=v.se;tree[v.se]=1;
		dfs1(v.fi,x);
		siz[x]+=siz[v.fi];
		if(siz[v.fi]>siz[son[x]]) son[x]=v.fi;
	}
}
void dfs2(int x,int topf){
	id[x]=++idx;top[x]=topf;
	if(son[x]){
		dfs2(son[x],topf);
	}
	for(auto v:vec[x]){
		if(v.fi==fa[x]||v.fi==son[x]) continue ;
		if(!tree[v.se]) continue ;
		dfs2(v.fi,v.fi);
	}
}

int tag[400010],maxn[400010];

void pushup(int p){
	maxn[p]=max(maxn[p<<1],maxn[p<<1|1]);
}

void pushdown(int p){
	if(tag[p]){
		tag[p<<1]+=tag[p];
		tag[p<<1|1]+=tag[p];
		maxn[p<<1]+=tag[p],maxn[p<<1|1]+=tag[p];
		tag[p]=0;
	}
}

void update(int p,int l,int r,int L,int R,int k){
	if(l>=L&&r<=R){
		maxn[p]+=k,tag[p]+=k;return ;
	}
	pushdown(p);
	int mid=l+r>>1;if(L<=mid) update(p<<1,l,mid,L,R,k);if(R>mid) update(p<<1|1,mid+1,r,L,R,k);
	pushup(p);
}
int query(int p,int l,int r,int L,int R){
	if(l>=L&&r<=R){
		return maxn[p];
	}
	pushdown(p);
	int mid=l+r>>1;
	int res=0;
	if(L<=mid) res=max(res,query(p<<1,l,mid,L,R));
	if(R>mid) res=max(res,query(p<<1|1,mid+1,r,L,R));
	pushup(p);
	return res;
}
void upd(int x,int y,int k){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		update(1,1,idx,id[top[x]],id[x],k);
		x=fa[top[x]];
	}
	if(x==y) return ;
	if(dep[x]>dep[y]) swap(x,y);
	update(1,1,idx,id[x]+1,id[y],k);
}

int qry(int x,int y){
	int res=0;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		res=max(res,query(1,1,idx,id[top[x]],id[x]));
		x=fa[top[x]];
	}
	if(x==y) return res;
	if(dep[x]>dep[y]) swap(x,y);
	res=max(res,query(1,1,idx,id[x]+1,id[y]));
	return res;
} 
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		vec[u].pb(mp(v,i)),vec[v].pb(mp(u,i));
	} 
	for(int i=1;i<=n;++i) if(!vis[i]) dfs1(i,i),dfs2(i,i);
	for(int i=1;i<=n;++i){
		for(auto j:vec[i]){
			if(i>j.fi) continue ;
			if(tree[j.se]) continue ;
			upd(i,j.fi,1);
		}
	}
	for(int i=1;i<=n;++i){
		for(auto j:vec[i]){
			if(i>j.fi) continue ;
			if(tree[j.se]) continue ;
			int mx=qry(i,j.fi);
			if(mx==1){
				ans.pb(j.se);
				int t=(dep[i]>dep[j.fi]?i:j.fi),f=i+j.fi-t;
				while(t!=f){
					ans.pb(egn[t]);t=fa[t];
				}
			}
		}
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());for(int i:ans) printf("%d ",i);
}