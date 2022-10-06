#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
#define N 1005
#define M 4000400
int n,k,mx;
int a[M],q[M],dis[2005];
bool vis[2005];
int head[2005],edgenum;
struct Edge {
	int to,nxt;
} edge[M];
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
inline void build() {
	rep(i,-1000,1000) rep(j,1,k)
		if (i+a[j]>=-1000&&i+a[j]<=1000) 
			add(i+1000,i+a[j]+1000);
}
inline int bfs() {
	memset(dis,0x3f3f3f3f,sizeof(dis));
	int f=0,r=1; q[f]=1000; dis[1000]=0;
	while (f!=r) {
		int u=q[f++]; //printf("%d : %d\n",u,dis[u]);
		for (int i=head[u]; i!=0; i=edge[i].nxt)
			if (dis[edge[i].to]>dis[u]+1) {
				dis[edge[i].to]=dis[u]+1;
			//	printf("%d ",edge[i].to);			
				q[r++]=edge[i].to;
			}
			else if (edge[i].to==1000) return dis[u]+1;
	}
	return -1;
}
int main() {
//	freopen("1.in","r",stdin);
	read(n); read(k);
	rep(i,1,k) read(a[i]); //a[i]-=n;
	rep(i,1,k) vis[a[i]]=1;
	int l=0; rep(i,0,1000) if (vis[i]) a[++l]=i;
	rep(i,1,l) a[i]-=n; k=l;
	/*bool xy=0,dy=0;
	rep(i,1,k)
		if (a[i]>0) dy=1;
		else if (a[i]<0) xy=1;
	if (!xy||!dy) {puts("-1"); return 0;}*/
	build();
	printf("%d",bfs());
	return 0;
}