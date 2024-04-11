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
#define int long long
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
int n,k;
int siz[100010],maxs[100010],sz[100010];
int rt;
int dep[100010],son[100010],fa[100010];
int top[100010];
vector<int>vec[100010],ans;
set<PII>nod[100010],st;
void getrt(int x,int f){
	siz[x]=1;
	for(int v:vec[x]){
		if(v==f) continue ;
		getrt(v,x);
		siz[x]+=siz[v];
		maxs[x]=max(maxs[x],siz[v]);
	}
	maxs[x]=max(maxs[x],n-siz[x]);
	if(maxs[x]<maxs[rt]) rt=x;
//	printf("x:%d,siz:%d,maxs:%d\n",x,siz[x],maxs[x]);
}
long long maxn,minn;
void dfs1(int x,int f){
	siz[x]=1,dep[x]=dep[f]+1,fa[x]=f;
	for(int v:vec[x]){
		if(v==f) continue ;
		dfs1(v,x);
		if(siz[v]>siz[son[x]]) son[x]=v;
		siz[x]+=siz[v];
		maxn+=siz[v];minn+=(siz[v]&1);++sz[x];
	}
}
void dfs2(int x,int topf){
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
void dfs3(int x,int f,int r){
	if(sz[x]) nod[r].insert(mp(dep[x],x));
	for(int v:vec[x]){
		if(v==f) continue ;
		if(siz[v]==1) continue ;
		dfs3(v,x,r);
	}
}
bool vis[100010];
void getans(int x,int f){
	if(!vis[x]) ans.pb(x);
	for(int v:vec[x]){
		if(v==f) continue ;
		getans(v,x);
	}
}
void del(int x,int r){
	if(!--sz[fa[x]]) nod[r].erase(mp(dep[fa[x]],fa[x])); 
}
signed main(){
	n=read(),k=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		vec[u].pb(v),vec[v].pb(u);
	}
	maxs[0]=0x3f3f3f3f;
	getrt(1,1);dep[rt]=-1;
//	printf("rt:%d\n",rt);
	dfs1(rt,rt);
	dfs2(rt,rt);
//	printf("maxn:%lld,minn:%lld\n",maxn,minn);
	if(k<minn||k>maxn||(k&1)!=(maxn&1)){
		printf("NO\n");return 0;
	}
	printf("YES\n");
	for(int v:vec[rt]){
		dfs3(v,rt,v);
		if(siz[v]>1) st.insert(mp(siz[v],v));
	}
	int rem=maxn-k;
	while(rem){
		auto it=st.end();--it;
		int r=(*it).se;
		st.erase(it);
		it=nod[r].end();--it;
		int lca=(*it).se;
		if(2*dep[lca]>rem){
			rem>>=1;
			lca=nod[r].lower_bound(mp(rem,0))->second;
			vector<int>V;
			V.clear();
			for(int v:vec[lca]){
				if(v==fa[lca]||vis[v]) continue ;
				V.pb(v);
			}
			if(V.size()<2) V.pb(lca);
			printf("%lld %lld\n",V[0],V[1]);
			vis[V[0]]=vis[V[1]]=1;
			del(V[0],r);del(V[1],r);
			break ;
		}
		else{
			vector<int>V;V.clear();
			for(int v:vec[lca]){
				if(v==fa[lca]||vis[v]) continue ;
				V.pb(v);
			}
			if(V.size()<2) V.pb(lca);
			printf("%lld %lld\n",V[0],V[1]);
			del(V[0],r);del(V[1],r);
			vis[V[0]]=vis[V[1]]=1;
			rem-=2*dep[lca];
		}
		siz[r]-=2;
		if(siz[r]>1) st.insert(mp(siz[r],r));
	}
	getans(rt,rt);
	int T=ans.size()>>1;
	for(int i=1;i<=T;++i) printf("%lld %lld\n",ans[i-1],ans[i+T-1]);
	return 0;
}