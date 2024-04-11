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

const int N = 6e5+55;
int n,s,t,cd,l,r;Vi e[N];
int f[N],g[N],dep[N],vis[N],fa[N],a[N],len,dp[N];bool ok[N];
void dfs1(int u, int Fa, int Dep){
	dep[u]=Dep;f[u]=Dep;fa[u]=Fa;
	for(int v:e[u])if(v!=Fa)
		dfs1(v,u,Dep+1),umax(f[u],f[v]);
}
void dfs2(int u, int Fa){
	int mx=0,mx2=0;
	int gs=0;
	for(int v:e[u])if(v!=Fa){
		if(f[v]>mx)mx2=mx,mx=f[v];
		else if(f[v]>mx2)mx2=f[v];
		gs+=f[v]-dep[u]>=cd;
	}
	for(int v:e[u])if(v!=Fa){
		g[v]=max(g[u],-dep[u]+(mx!=f[v]?mx:mx2))+1;
		dfs2(v,u);
	}
	gs+=g[u]>=cd;ok[u]=gs>=3;
}
int suc,ans[N];
int getans(int u, int fa){
	int res=ok[u];dp[u]=0;
	for(int v:e[u])if(v!=fa&&!vis[v])res|=getans(v,u),umax(dp[u],dp[v]+1);
	return res;
}
void dfs(int tp, int p){
	suc|=ans[a[p]];
	if(!tp){
		while(r-1>l&&r-1-p+dp[a[p]]>=len-1)
			r--,dfs(1,r);
	}
	else{
		while(l+1<r&&p-(l+1)+dp[a[p]]>=len-1)
			l++,dfs(0,l);
	}
}
int main() {
	int TT;read(TT);while(TT--){
		read(n);read(s);read(t);
		rep(i,0,n+1){
			e[i].clear();dep[i]=f[i]=g[i]=vis[i]=ans[i]=dp[i]=0;
			len=0;
		}
		rep(i,1,n-1){
			int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);
		}
		dfs1(s,0,0);cd=dep[t];dfs2(s,0);
		bool fd=0;rep(i,1,n)fd|=ok[i];if(!fd){puts("NO");continue;}
		for(int u=t;;u=fa[u]){vis[u]=1;a[++len]=u;if(u==s)break;}
		for(int u=t;;u=fa[u]){ans[u]=getans(u,0);if(u==s)break;}
		if(ans[s]||ans[t]){puts("YES");continue;}
		reverse(a+1,a+len+1);assert(len==dep[t]+1);
		l=1;r=len;suc=0;
		dfs(0,1);
		dfs(1,len);
		if(suc)puts("YES");else puts("NO");
	}
	return 0;
}