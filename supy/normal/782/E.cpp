#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
#include<cmath>
#define MAXN 20005
#define MAXM 200050
#define INF 0x7f7f7f7f
#define ll long long
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define clr(x) memset(x,0,sizeof(x));
using namespace std;
#define N 400005
int stack[N],top,mx;
int n,m,k,a[N],b[N];
int f[N];
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
	x=0; int f=1; char c=getchar();
	while (c<'0'||c>'9'){if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9'){x=10*x+c-'0'; c=getchar();} x*=f;
}
int find(int x) {
	if (f[x]==x) return x;
	f[x]=find(f[x]); return f[x];
}
inline void gettree() {
	rep(i,1,n) f[i]=i;
	int cnt=n;
	rep(i,1,m) {
		int fx=find(a[i]),fy=find(b[i]);
		if (fx!=fy) {
			f[fx]=fy; cnt--;
			addedge(a[i],b[i]); addedge(b[i],a[i]);
		}
		if (cnt==1) break;
	}
}
void dfs(int u, int fa) {
//	printf("== %d %d\n",u,fa);
	stack[++top]=u;
	for (int i=head[u]; i!=0; i=edge[i].nxt)
		if (edge[i].to!=fa) {
			dfs(edge[i].to,u);
			stack[++top]=u;		
		}
}
int main()
{
//	freopen("1.in","r",stdin);
	read(n); read(m); read(k);
	rep(i,1,m) {read(a[i]); read(b[i]);}
	gettree();
	dfs(1,0); mx=(2*n-1)/k+1;
//	rep(u,1,n){for (int i=head[u]; i!=0; i=edge[i].nxt) printf("%d ",edge[i].to);puts("");}
//	rep(i,1,top) printf("%d ",stack[i]); puts("");
	rep(i,1,k) {
		if (top>=mx) {
			printf("%d",mx);
			rep(j,1,mx) printf(" %d",stack[top--]);
			puts("");
		}
		else if (top>0) {
			printf("%d",top);
			while (top) printf(" %d",stack[top--]); //!!!!!!!!
			puts("");
		}
		else printf("1 1\n");
	}
	return 0;
}