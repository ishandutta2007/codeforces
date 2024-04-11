#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : (-a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
#define N 1000005
int n,f[N],t[N],size[N],aver,root;
int ans1,ans2;
int head[N],edgenum;
struct Edge { //children
	int to,nxt;
} edge[N];
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
void dfs(int u) {
	size[u]=t[u];
	L(i,u) {dfs(edge[i].to); size[u]+=size[edge[i].to];}
}
void dfs1(int u) { //aver = 0
	L(i,u) dfs1(edge[i].to); //careful!
	if (size[u]==aver&&u!=root) { //careful!
		if (ans1&&ans2) return;
		if (!ans1) ans1=u; else ans2=u;
		for (int i=u; ; i=f[i]) {size[i]-=aver; if (i==root) break;}
		return;
	}
}
int main() {
//	freopen("1.in","r",stdin);
	read(n);
	rep(i,1,n) {read(f[i]); read(t[i]); addedge(f[i],i); aver+=t[i];}
	rep(i,1,n) if (f[i]==0) root=i;
	if (aver%3!=0) {puts("-1"); return 0;}
	aver/=3;
	dfs(root);
	dfs1(root);
//	rep(i,1,n) printf("%d ",size[i]); puts("");
//	printf("%d %d %d\n",aver,ans1,ans2);
	if (!ans1 || !ans2) puts("-1"); else printf("%d %d",ans1,ans2);
	return 0;
}