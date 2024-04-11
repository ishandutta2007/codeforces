#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
const int N = 200300;
int n,m;
int head[N],edgenum=1;
int vis[N], dot[N], dfn, size;
bool Tedge[N<<1], used[N<<1];
Vi vec[N];
struct Ans {
	int a[N],b[N],c[N],len;
	inline void add(int x, int y, int z) {a[++len]=x; b[len]=y; c[len]=z;}
	inline void print() {
		printf("%d\n",len); rep(i,1,len) printf("%d %d %d\n",a[i],b[i],c[i]);
	}
} ans;
struct Union {
	int f[N];
	inline void init(int n) {rep(i,1,n) f[i]=i;}
	inline int find(int x) {
		if (f[x]==x) return x;
		f[x]=find(f[x]); return f[x];
	}
	inline bool merge(int x, int y) {
		int fx=find(x),fy=find(y);
		if (fx!=fy) {f[fx]=fy; return 1;} //succeed.
		return 0;
	}
} Set;
struct Edge {
	int to,nxt;
} edge[N<<1];
inline void add(int u, int v) {
	edge[++edgenum].to=v;
	edge[edgenum].nxt=head[u];
	head[u]=edgenum;
}



inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
inline void dfs(int u) {
	if (!vis[u]) {vis[u]=dfn; dot[++size]=u;}
	L(i,u) if (!vis[edge[i].to]) dfs(edge[i].to);
}
inline void dfs1(int u, int fa) {
	L(i,u) if (edge[i].to!=fa&&Tedge[i]) {
		dfs1(edge[i].to,u);
	}
	if (fa>0)
		if (vec[u].size()&1) vec[u].push_back(fa);
		else vec[fa].push_back(u);
	int len=vec[u].size(); //printf("[%d %d]\n",u,len);
	for (int i=0; i+1<len; i+=2) ans.add(vec[u][i],u,vec[u][i+1]);
}
int main() {
//	freopen("1.in","r",stdin);
	read(n); read(m); Set.init(n);
	rep(i,1,m) {int a,b; read(a); read(b); add(a,b); add(b,a);}
	rep(i,1,n) if (!vis[i]) {
		size=0; dfn++; dfs(i);
	//	printf("[%d]:",size); rep(j,1,size) printf("%d ",dot[j]); puts("");
		rep(u,1,size) L(j,dot[u]) {
			if (Set.merge(dot[u],edge[j].to)) {Tedge[j]=1; Tedge[j^1]=1; used[j^1]=1;}
			else if (!used[j]) {vec[edge[j].to].push_back(dot[u]); used[j^1]=1;}
		}
	//	rep(u,1,n) printf("%d %d\n",u,vec[u].size());
		dfs1(i,-1);
	}
	ans.print();
	return 0;
}