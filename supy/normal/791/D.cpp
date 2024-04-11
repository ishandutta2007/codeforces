#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
#define N 200005
#define K 6
ll tot,l[K],g[N][K];
int n,k;
int f[N][K],size[N];
int head[N],edgenum;
struct Edge {
	int to,nxt;
} edge[N<<1];
inline void addedge(int u, int v) {
	edge[++edgenum].to=v;
	edge[edgenum].nxt=head[u];
	head[u]=edgenum;
}

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
inline void dfs(int u, int fa) {
	size[u]=1;
	for (int i=head[u]; i!=0; i=edge[i].nxt)
		if (edge[i].to!=fa) {
			dfs(edge[i].to,u);
			size[u]+=size[edge[i].to];
		}
}
inline void dfs1(int u, int fa) {
	for (int i=head[u]; i!=0; i=edge[i].nxt)
		if (edge[i].to!=fa) {
			dfs1(edge[i].to,u);
			tot+=(ll)size[edge[i].to]*(n-size[edge[i].to]);
		}
}
inline int Mo(int x) {return x>=k ? x-k : x;}
inline void dp(int u, int fa) {
	f[u][0]=1;
	int tmp[7]={0};
	for (int i=head[u]; i!=0; i=edge[i].nxt)
		if (edge[i].to!=fa) {
			dp(edge[i].to,u);
			rep(j,0,k-1) f[u][Mo(j+1)]+=f[edge[i].to][j]; //line1
			rep(j,0,k-1) rep(p,0,k-1)
				g[u][Mo(j+p+2)]+=(ll)tmp[j]*f[edge[i].to][p];
			rep(j,0,k-1) tmp[j]+=f[edge[i].to][j];
		}
}
int main() {
//	freopen("1.in","r",stdin);
	read(n); read(k);
	rep(i,1,n-1) {
		int a,b; read(a); read(b);
		addedge(a,b); addedge(b,a);
	}
	dfs(1,-1); dfs1(1,-1);
	dp(1,-1);
//	printf("%lld\n",tot);
	rep(i,1,n) rep(j,0,k-1) l[j]+=f[i][j]+g[i][j];
//	rep(i,1,k-1) printf("%lld ",l[i]); puts("");
	rep(i,1,k-1) tot+=l[i]*(k-i);
	printf("%lld",tot/k);
	return 0;
}