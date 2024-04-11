//Vertices which have the i-th (1<=i<=m) type of ice cream form a connected subgraph.
//u,vcolorfau,v()
//
#include<cstdio>
#include<vector>
#include<cstring>
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define N 300005
using namespace std;
int n,m,mx;
int head[N],edgenum;
vector<int> Vec[N];
struct Edge {
	int to,nxt;
} edge[N<<1];
inline void add(int u, int v) {
	edge[++edgenum].to=v;
	edge[edgenum].nxt=head[u];
	head[u]=edgenum;
}
int col[N],used[N],num;
inline void dfs(int u, int fa) {
	num++;
	int Size=Vec[u].size();
	rep(i,0,Size-1) if (col[Vec[u][i]]) 
		used[col[Vec[u][i]]]=num;
	int x=1;
	rep(i,0,Size-1) if (!col[Vec[u][i]]) {
		while (used[x]==num) x++;
		col[Vec[u][i]]=x++;
	}
	for (int i=head[u]; i!=0; i=edge[i].nxt)
		if (edge[i].to!=fa) dfs(edge[i].to,u);
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n) {
		int k,x; scanf("%d",&k); mx=max(mx,k);
		rep(j,1,k) {scanf("%d",&x); Vec[i].push_back(x);}
	}
	rep(i,1,n-1) {
		int a,b; scanf("%d%d",&a,&b);
		add(a,b); add(b,a);
	}
	dfs(1,0);
	memset(used,0,sizeof(used));
	rep(i,1,m) {if (!col[i]) col[i]=1; used[col[i]]=1;}
	int ans=0;
	rep(i,1,m) ans+=used[i]; //0mx=0
	printf("%d\n",ans);
	rep(i,1,m) printf("%d ",col[i]);
	return 0;
}