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
const int N = 3333;
ll f[N][N],res;int n,sz[N][N],lst[N][N];Vi e[N];vector<Pii> a[N];
void dfs1(int u, int fa, int from, int dis){
	if(from<u)a[dis].pb(Pii(from,u));
	sz[from][u]=1;lst[from][u]=fa;
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa)
		dfs1(e[u][i],u,from,dis+1),sz[from][u]+=sz[from][e[u][i]];
}
int main() {
	read(n);rep(i,1,n-1){
		int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);
	}
	rep(i,1,n)dfs1(i,0,i,0);
	per(d,n,1)rep(dd,0,SZ(a[d])-1){
		int u=a[d][dd].fi,v=a[d][dd].se;ll res=0;
		rep(i,0,SZ(e[u])-1)if(e[u][i]!=lst[v][u])umax(res,f[e[u][i]][v]);
		rep(i,0,SZ(e[v])-1)if(e[v][i]!=lst[u][v])umax(res,f[e[v][i]][u]);
		f[u][v]=f[v][u]=res+sz[v][u]*sz[u][v];
	//	printf("%d %d:%lld\n",u,v,f[u][v]);
	}
	rep(u,2,n)umax(res,f[u][lst[1][u]]);cout<<res;
	return 0;
}