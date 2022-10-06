#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
mt19937 R(chrono::system_clock().now().time_since_epoch().count());

const int N = 1005000;
int n,s[N],dep[N],len,bg[N],Log[N],pos[N][20];vector<Pii> e[N];
void dfs(int u, int fa, int d){
	dep[u]=d;s[++len]=u;bg[u]=len;
	rep(i,0,SZ(e[u])-1)if(e[u][i].fi!=fa)dfs(e[u][i].fi,u,d+1),s[++len]=u;
}
inline int LCA(int u, int v){
	int l=bg[u],r=bg[v];if(l>r)swap(l,r);int k=Log[r-l+1];
	return dep[pos[l][k]]<dep[pos[r-(1<<k)+1][k]]?pos[l][k]:pos[r-(1<<k)+1][k];
}
inline int getdis(int u, int v){
	return dep[u]+dep[v]-2*dep[LCA(u,v)];
}
int dl[N],dr[N],idfn[N],num,A[N],B[N],C[N],v[N];
inline void mdy(int p){assert(p);while(p<=n)v[p]^=1,p+=p&-p;}
inline int query(int p){int r=0;while(p)r^=v[p],p-=p&-p;return r;}
int qry(int x){return query(dl[x]);}
void dfs2(int u, int fa){
	dl[u]=++num;idfn[num]=u;
	for(auto v:e[u])if(v.fi!=fa){
		dfs2(v.fi,u);
		if(v.se)mdy(dl[v.fi]),mdy(dr[v.fi]+1);
	}
	dr[u]=num;
}
struct node{
	int x,y,z,w;//x=y=0,z=w=1
}tree[500005<<2];
int lzy[N<<2];
void pushtag(int k){
	lzy[k]^=1;
	swap(tree[k].x,tree[k].z);
	swap(tree[k].y,tree[k].w);
}
void pushdown(int k){
	if(lzy[k]){
		pushtag(k<<1);pushtag(k<<1|1);
		lzy[k]=0;
	}
}
inline node merge(const node&a, const node&b){
	node res=a;int x=!res.x?-1:getdis(res.x,res.y),y=!res.z?-1:getdis(res.z,res.w);
	if(b.x&&getdis(b.x,b.y)>x)x=getdis(b.x,b.y),res.x=b.x,res.y=b.y;
	if(b.z&&getdis(b.z,b.w)>y)y=getdis(b.z,b.w),res.z=b.z,res.w=b.w;
	int t=0;
	if(a.x&&b.x&&(t=getdis(a.x,b.x))>x)x=t,res.x=a.x,res.y=b.x;
	if(a.x&&b.y&&(t=getdis(a.x,b.y))>x)x=t,res.x=a.x,res.y=b.y;
	if(a.y&&b.x&&(t=getdis(a.y,b.x))>x)x=t,res.x=a.y,res.y=b.x;
	if(a.y&&b.y&&(t=getdis(a.y,b.y))>x)x=t,res.x=a.y,res.y=b.y;
	if(a.z&&b.z&&(t=getdis(a.z,b.z))>y)y=t,res.z=a.z,res.w=b.z;
	if(a.w&&b.z&&(t=getdis(a.w,b.z))>y)y=t,res.z=a.w,res.w=b.z;
	if(a.z&&b.w&&(t=getdis(a.z,b.w))>y)y=t,res.z=a.z,res.w=b.w;
	if(a.w&&b.w&&(t=getdis(a.w,b.w))>y)y=t,res.z=a.w,res.w=b.w;
	return res;
}
void build(int k, int l, int r){
	if(l==r){
		if(qry(idfn[l])&1)tree[k].x=tree[k].y=idfn[l];
		else tree[k].z=tree[k].w=idfn[l];
		return;
	}
	int mid=(l+r)/2;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	tree[k]=merge(tree[k<<1],tree[k<<1|1]);
}
void mdy(int k, int l, int r, int L, int R){
	if(l==L&&r==R){pushtag(k);return;}
	int mid=(L+R)>>1;pushdown(k);
	if(r<=mid)mdy(k<<1,l,r,L,mid);
	else if(l>mid)mdy(k<<1|1,l,r,mid+1,R);
	else mdy(k<<1,l,mid,L,mid),mdy(k<<1|1,mid+1,r,mid+1,R);
	tree[k]=merge(tree[k<<1],tree[k<<1|1]);
}
int main() {
	read(n);int rt=1;
	rep(i,1,n-1){
		int u,v,w;read(u);read(v);read(w);e[u].pb(mp(v,w));e[v].pb(mp(u,w));
		A[i]=u;B[i]=v;C[i]=w;
	}
	dfs(rt,0,0);rep(i,1,len){Log[i]=Log[i-1];if(i==(1<<Log[i]+1))Log[i]++;}
	rep(i,1,len)pos[i][0]=s[i];
	rep(j,1,19)rep(i,1,len-(1<<j)+1)
		pos[i][j]=dep[pos[i][j-1]]<dep[pos[i+(1<<j-1)][j-1]]?pos[i][j-1]:pos[i+(1<<j-1)][j-1];
	dfs2(rt,0);
	build(1,1,n);
//	rep(i,1,n)printf("%d:%d %d %d\n",i,dl[i],dep[i],qry(i));
	int q;read(q);
	while(q--){
		int id;read(id);
		int u=A[id],v=B[id];
		if(dep[u]>dep[v])swap(u,v);
		mdy(dl[v]),mdy(dr[v]+1);
		mdy(1,dl[v],dr[v],1,n);
		int res=max(tree[1].x?getdis(tree[1].x,tree[1].y):0,tree[1].z?getdis(tree[1].z,tree[1].w):0);
		printf("%d\n",res);
	}
	return 0;
}