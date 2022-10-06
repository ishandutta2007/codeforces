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
#define N 200005
int n,ans=1,col[N];
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
void dfs(int u, int fa) {
	int cnt=0;
	for (int i=head[u]; i!=0; i=edge[i].nxt) 
	if (edge[i].to!=fa) {
		cnt++;
		while (col[u]==cnt||col[fa]==cnt) cnt++;
		col[edge[i].to]=cnt; dfs(edge[i].to,u);
		ans=max(ans,cnt);
	}
}
int main()
{
	read(n);
	rep(i,1,n-1) {
		int a,b; read(a); read(b);
		addedge(a,b); addedge(b,a);
	}
	col[1]=1; dfs(1,0);
	printf("%d\n",ans);
	rep(i,1,n) printf("%d ",col[i]);
	return 0;
}