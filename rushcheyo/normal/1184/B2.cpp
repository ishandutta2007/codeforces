#include <bits/stdc++.h>
using namespace std;
int n,m,s,b,k,h;
#define ll long long
namespace Flow {
	const int N=10005,E=3000005;
	int Head[N],Next[E],Adj[E],Flow[E],tot=1;
	inline void addedge(int u,int v,int w) {
		Next[++tot]=Head[u],Head[u]=tot,Adj[tot]=v,Flow[tot]=w;
		Next[++tot]=Head[v],Head[v]=tot,Adj[tot]=u,Flow[tot]=0;
	}
	int S,T,level[N];
	int Q[N];
	inline bool bfs() {
		memset (level,-1,sizeof(level));
		int l=1,r=0;
		Q[++r]=S,level[S]=0;
		while (l<=r) {
			int x=Q[l++];
			for (int e=Head[x]; e; e=Next[e])
				if (level[Adj[e]]==-1&&Flow[e])
					level[Adj[e]]=level[x]+1,Q[++r]=Adj[e];
		}
		return level[T]!=-1;
	}
	inline int dfs(int x,int flow) {
		if (x==T||!flow) return flow;
		int ret=0,c;
		for (int e=Head[x]; e; e=Next[e])
			if (level[Adj[e]]==level[x]+1&&Flow[e]&&(c=dfs(Adj[e],min(flow,Flow[e])))) {
				ret+=c;
				Flow[e]-=c,Flow[e^1]+=c;
				if (ret==flow) break;
			}
		if (!ret) level[x]=-1;
		return ret;
	}
	inline int work() {
		int ans=0;S=0,T=s+b+1;
		for (int i=1;i<=s;i++) addedge(S,i,1);
		for (int i=1;i<=b;i++) addedge(i+s,T,1);
		while (bfs()) ans+=dfs(S,1<<30);
		return ans;
	}
}
struct S {
	int x,a,f;
} A[1005];
struct B {
	int x,d;
} B[1005];
int e[105][105];
int main () {
	scanf ("%d%d",&n,&m);
	memset (e,0x3f,sizeof(e));
	for (int i=1; i<=n; i++) e[i][i]=0;
	for (int i=1,u,v; i<=m; i++)
		scanf ("%d%d",&u,&v),e[u][v]=e[v][u]=min(e[u][v],1);
	for (int k=1; k<=n; k++)
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				if (i==j||j==k||i==k) continue;
				else e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
	scanf ("%d%d%d%d",&s,&b,&k,&h);
	for (int i=1; i<=s; i++)
		scanf ("%d%d%d",&A[i].x,&A[i].a,&A[i].f);
	for (int i=1; i<=b; i++)
		scanf ("%d%d",&B[i].x,&B[i].d);
	for (int i=1; i<=s; i++)
		for (int j=1; j<=b; j++)
			if (e[A[i].x][B[j].x]<=A[i].f&&A[i].a>=B[j].d)
				Flow::addedge(i,j+s,1);
	int cnt=Flow::work();
	printf ("%I64d",min(1ll*cnt*k,1ll*h*s));
	return 0;
}