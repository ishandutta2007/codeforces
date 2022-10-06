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
#define N 200005
#define M (1<<24)
int n,a[N],p[N],head[N],edgenum;
int dis[N],buc[M];
struct Edge {
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
	if (head[u]==0) {dis[u]=0; return;}
	L(i,u) {dfs(edge[i].to); dis[u]=dis[edge[i].to]^1;}
}
int main() {
	read(n);
	rep(i,1,n) read(a[i]);
	rep(i,2,n) {read(p[i]); addedge(p[i],i);}
	dfs(1);
	int cnt=0,XOR=0;
	rep(i,1,n) if (dis[i]==0) {cnt++; XOR^=a[i];}
	if (XOR==0) {
		rep(i,1,n) if (dis[i]) buc[a[i]]++;
		ll ans=(ll)cnt*(cnt-1)/2+(ll)(n-cnt)*(n-cnt-1)/2;
		rep(i,1,n) if (dis[i]==0) ans+=buc[a[i]];
		printf("%lld",ans);
	}
	else {
		rep(i,1,n) if (dis[i]) buc[a[i]]++;
		ll ans=0;
		rep(i,1,n) if (dis[i]==0) ans+=buc[a[i]^XOR];
		printf("%lld",ans);
	}
	return 0;
}