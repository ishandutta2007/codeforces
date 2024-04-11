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
int n,m,r[N];
int x[N][3];
int head[N],edgenum;
struct Edge {
	int to,nxt,v;
} edge[N<<1];
inline void addedge(int u, int v, int dis) {
	edge[++edgenum].to=v;
	edge[edgenum].nxt=head[u];
	edge[edgenum].v=dis;
	head[u]=edgenum;
}
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
int v[N];
bool dfs(int u) {
	L(i,u) 
		if (v[edge[i].to]==-1) {
			v[edge[i].to]=v[u]^edge[i].v;
			if (dfs(edge[i].to)==0) return 0;
		}
		else {
			if (v[edge[i].to]^v[u]!=edge[i].v)
				return 0;
		}
	return 1;
}
int s[N],len;
bool vis[N];
void dfs1(int u) {
	s[++len]=u; vis[u]=1;
	L(i,u) if (!vis[edge[i].to])
		dfs1(edge[i].to);
}
int main() {
//	freopen("1.in","r",stdin);
	read(n); read(m);
	rep(i,1,n) read(r[i]);
	rep(i,1,m) {
		int a,b; read(a);
		rep(j,1,a) {
			read(b);
			if (x[b][1]) x[b][2]=i;
			else x[b][1]=i;
		}
	}
	rep(i,1,n) {
		addedge(x[i][1],x[i][2],r[i]^1);
		addedge(x[i][2],x[i][1],r[i]^1);
	}
	bool flag=1;
	memset(v,-1,sizeof(v));
	rep(i,1,m) if (v[i]==-1) {
		len=0; dfs1(i);
		bool ok=0;
		v[i]=0; if (dfs(i)) ok=1;
		rep(j,1,len) v[s[j]]=-1;
		v[i]=1; if (dfs(i)) ok=1;
		if (!ok) {flag=0; break;}
	}
	/*v[1]=0; if (dfs(1)) flag=1;
	memset(v,-1,sizeof(v));
	v[1]=1; if (dfs(1)) flag=1;*/
	if (flag) puts("YES"); else puts("NO");
	return 0;
}