#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 102000;
int n,q,fa[N],dep[N],sz[N],son[N],top[N],dl[N],dr[N],idfn[N],num;Vi e[N];
int a[N];set<int>Set;
void dfs1(int u, int Dep){
	dep[u]=Dep;sz[u]=1;
	rep(i,0,SZ(e[u])-1){
		dfs1(e[u][i],Dep+1),sz[u]+=sz[e[u][i]];
		if(sz[e[u][i]]>sz[son[u]])son[u]=e[u][i];
	}
}
void dfs2(int u, int Top){
	top[u]=Top;dl[u]=++num;idfn[num]=u;
	if(son[u])dfs2(son[u],Top);
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=son[u])dfs2(e[u][i],e[u][i]);
	dr[u]=num;
}
int lzy[N<<2],mn[N<<2];
inline void push(int k, int x){lzy[k]+=x;mn[k]+=x;}
inline void pushdown(int k){
	if(lzy[k]){
		push(k<<1,lzy[k]);push(k<<1|1,lzy[k]);
		lzy[k]=0;
	}
}
inline void upd(int k){
	mn[k]=min(mn[k<<1],mn[k<<1|1]);
}
void modify(int k, int l, int r, int val, int L, int R){//add
	if(l==L&&r==R){push(k,val);return;}
	int mid=(L+R)>>1;pushdown(k);
	if(r<=mid)modify(k<<1,l,r,val,L,mid);
	else if(l>mid)modify(k<<1|1,l,r,val,mid+1,R);
	else modify(k<<1,l,mid,val,L,mid),modify(k<<1|1,mid+1,r,val,mid+1,R);
	upd(k);
}
int query(int k, int l, int r, int L, int R){//qmin
	if(l==L&&r==R)return mn[k];
	int mid=(L+R)>>1;pushdown(k);
	if(r<=mid)return query(k<<1,l,r,L,mid);
	if(l>mid)return query(k<<1|1,l,r,mid+1,R);
	return min(query(k<<1,l,mid,L,mid),query(k<<1|1,mid+1,r,mid+1,R));
}
inline void modify(int x, int val){
	modify(1,dl[x],dr[x],val,1,n);
}
inline int query(int x){
	int ori=query(1,dl[x],dl[x],1,n),res=0;
	for(x=fa[x];x;x=fa[top[x]])umin(res,query(1,dl[top[x]],dl[x],1,n));
	return ori-res;
}
int main() {
	read(n);read(q);
	rep(i,2,n)read(fa[i]),e[fa[i]].pb(i);
	dfs1(1,0);dfs2(1,1);
	rep(i,1,n)a[i]=-1,modify(i,-1);Set.clear();
	while(q--){
		int op,x;read(op);read(x);
		if(op==1){a[x]++;Set.insert(dl[x]);modify(x,1);}
		if(op==2){
			set<int>::iterator it=Set.lower_bound(dl[x]);
			for(;it!=Set.end()&&(*it)<=dr[x];){
				int u=idfn[*it];modify(u,-1-a[u]);a[u]=-1;it=Set.erase(it);
			}
			int val=query(x);
			a[x]+=-1-val;modify(x,-1-val);Set.insert(dl[x]);
		}
		if(op==3)printf("%s\n",query(x)>=0?"black":"white");
	}
	return 0;
}