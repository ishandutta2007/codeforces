#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<random>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define int ll
using namespace std;
typedef long long ll;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
const ll inf=10;
struct frac {
	ll x, y;
	inline frac() {}
	inline frac(ll _x, ll _y = 1ll) : x(_x), y(_y) {
		if(y!=0){
			ll g=__gcd(_x,_y);
			x/=g,y/=g;
		}
		if (y < 0) x = -x, y = -y;
	}
	friend frac operator + (frac e, frac b) { return frac(e.x * b.y + e.y * b.x, e.y * b.y); }
	friend frac operator - (frac e, frac b) { return frac(e.x * b.y - e.y * b.x, e.y * b.y); }
	friend frac operator * (frac e, frac b) { return frac(e.x * b.x, e.y * b.y); }
	friend frac operator / (frac e, frac b) { return frac(e.x * b.y, e.y * b.x); }
	friend bool operator < (frac e, frac b) { return e.x * b.y < b.x * e.y; }
	friend bool operator > (frac e, frac b) { return e.x * b.y > b.x * e.y; }
	friend bool operator <= (frac e, frac b) { return e.x * b.y <= b.x * e.y; }
	friend bool operator >= (frac e, frac b) { return e.x * b.y >= b.x * e.y; }
	friend bool operator == (frac e, frac b) { return e.x * b.y == b.x * e.y; }
	friend bool operator != (frac e, frac b) { return e.x * b.y != b.x * e.y; }
};
frac min(frac a,frac b){
	return a<b?a:b;
}
frac max(frac a,frac b){
	return a>b?a:b;
}
long double ans=1e40;
frac Ans=frac{inf,0};
int n,m;
vector<int>vec[100010];
int siz[100010],dep[100010];
int fa[100010],son[100010];
int dfn[100010];
//const long double eps=1e-40;
struct act{
	frac sx,sy,tx,ty,k,b;
	bool operator <(const act &x)const {
		if(sx!=x.sx) return sx<x.sx; 
		else if(sy!=x.sy) return sy<x.sy;
		else if(tx!=x.tx) return tx<x.tx; 
		else if(ty!=x.ty) return ty<x.ty;
		else return 1;
	}
	frac get(frac tm){
		return k*tm+b;
	}
};
void cross(act x,act y){
//	printf("%.7Lf %.7Lf %.7Lf %.7Lf\n",x.sx.x*1.0L/x.sx.y,x.sy.x*1.0L/x.sy.y,x.tx.x*1.0L/x.tx.y,x.ty.x*1.0L/x.ty.y);
//	printf("%.7Lf %.7Lf %.7Lf %.7Lf\n",y.sx.x*1.0L/y.sx.y,y.sy.x*1.0L/y.sy.y,y.tx.x*1.0L/y.tx.y,y.ty.x*1.0L/y.ty.y);
	frac mxx=max(x.sx,y.sx),mnt=min(x.tx,y.tx);
	if(mxx>mnt) return ;
//	printf("%.7Lf %.7Lf %.7Lf %.7Lf\n",x.sx.x*1.0L/x.sx.y,x.sy.x*1.0L/x.sy.y,x.tx.x*1.0L/x.tx.y,x.ty.x*1.0L/x.ty.y);
//	printf("%.7Lf %.7Lf %.7Lf %.7Lf\n",y.sx.x*1.0L/y.sx.y,y.sy.x*1.0L/y.sy.y,y.tx.x*1.0L/y.tx.y,y.ty.x*1.0L/y.ty.y);
	frac k1=x.k,k2=y.k;
	frac b1=x.b,b2=y.b;
	if(k1==k2) {
//		printf("?/fn");
		if(b1==b2) Ans=min(Ans,max(x.sx,y.sx));
		return ;
	}
	frac d=(b2-b1)/(k1-k2);
//	printf("%.7Lf\n",d.x*1.0L/d.y);
//	printf("%lld %lld\n",d.x,d.y);
//	printf("%d %d\n",Ans.x,Ans.y);
	if(d>=x.sx&&d>=y.sx&&d<=x.tx&&d<=y.tx) Ans=min(Ans,d);
//	printf("%d %d\n",Ans.x,Ans.y);
}
int top[100010];
multiset<act>sat[100010];
struct event{
	frac T;
	bool in;
	int id;
	bool operator <(const event &x)const{
		if(T!=x.T) return T<x.T;else if(in!=x.in) return in>x.in;else return id<x.id;
	} 
};
void upd(int x,int l,int r,frac T,int sped){
//	printf("%d %d %d (%d,%d),%d\n",x,l,r,T.x,T.y,sped);
//	printf("x:%d,l:%d,r:%d,T:%.7Lf,s:%d\n",x,l,r,T,sped);
	sat[x].insert(act{T,l,T+frac(abs(r-l),sped),r,frac(r>l?sped:-sped,1),frac(l-T*frac(r>l?sped:-sped,1))});
}
void dfs1(int x,int f){
	siz[x]=1;fa[x]=f;dep[x]=dep[f]+1;
	for(int v:vec[x]){
		if(v==f) continue ;
		dfs1(v,x);
		if(siz[son[x]]<siz[v]) son[x]=v;
		siz[x]+=siz[v]; 
	}
}
int idx;
void dfs2(int x,int topf){
	dfn[x]=++idx;top[x]=topf;
	if(son[x]){
		dfs2(son[x],topf);
	}
	else return ;
	for(int v:vec[x]){
		if(v==fa[x]||v==son[x]) continue ;
		dfs2(v,v);
	}
}
int LCA(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		u=fa[top[u]];
	}
	return dep[u]<dep[v]?u:v;
}
void insert(int t,int c,int u,int v){
	int lca=LCA(u,v);
	int S=u,T=v;
	while(top[u]!=top[lca]){
		upd(top[u],dfn[u],dfn[top[u]]-1,frac(t*c+(dep[S]-dep[u]),c),c);
		u=fa[top[u]];
	}
	while(top[v]!=top[lca]){
		upd(top[v],dfn[top[v]]-1,dfn[v],frac(t*c+(dep[S]-dep[lca]+dep[top[v]]-dep[lca]-1),c),c);
		v=fa[top[v]];
	}
	upd(top[u],dfn[u],dfn[v],frac(t*c+(dep[S]-dep[u]),c),c);
}
act A[100010];
int cnt;
frac tim;
struct cmp{
	bool operator ()(const int &a,const int &b)const{
		return A[a].get(tim)<A[b].get(tim);
	}
};
set<event>St;
set<int,cmp>st;
void solve(int x){
	cnt=0;
	for(auto i:sat[x]) A[++cnt]=i;
	tim=0.0L;
	st.clear();St.clear();
	for(int i=1;i<=cnt;++i){
//		printf("x:%d,i:%d,%.7Lf %.7Lf %.7Lf %.7Lf\n",x,i,A[i].sx,A[i].sy,A[i].tx,A[i].ty);
		event j;j.T=A[i].sx;
		j.in=1;j.id=i;
		St.insert(j);
		j.T=A[i].tx,j.in=0,j.id=i;St.insert(j);
	}
	while(!St.empty()){
		event i=*St.begin();
		if(i.T>=Ans) break ;
//		printf("x:%d,%d %d\n",x,i.in,i.id);
		tim=i.T;
		if(i.in){
			auto it=st.lower_bound(i.id);
			if(it!=st.end()) cross(A[i.id],A[*it]);
			if(it!=st.begin()){
				--it;
				cross(A[i.id],A[*it]);
			}
			st.insert(i.id);
		}
		else{
			auto it=st.lower_bound(i.id);
			if(it!=st.end()&&it!=st.begin()){
				auto l=it,r=it;
				--l,++r;
				if(r!=st.end()) cross(A[*l],A[*r]);
			} 
			st.erase(i.id);
		}
		St.erase(i);
	}
}
signed main(){
//	printf("%d\n",frac(inf,0)>frac(1,1));
//	printf("%d\n",__gcd(1,0));
//	printf("%d\n",__gcd(2,0));
	n=read(),m=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		vec[u].pb(v),vec[v].pb(u);
	}
	dfs1(1,0);
	dfs2(1,1);
	for(int i=1;i<=m;++i){
		int t=read(),c=read(),v=read(),u=read();
		insert(t,c,v,u);
	}
	for(int i=1;i<=n;++i) if(top[i]==i) solve(i);
	printf(Ans.y==0?"-1\n":"%.7Lf\n",Ans.x*1.0L/Ans.y);
}