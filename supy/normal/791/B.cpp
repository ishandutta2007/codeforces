#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
#define N 150005
bool vis[N];
int s[N];
int n,m,ans;
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
void dfs(int u) {
	vis[u]=1; ans++; s[ans]=u;
	for (int i=head[u]; i!=0; i=edge[i].nxt)
		if (!vis[edge[i].to]) dfs(edge[i].to);
}
bool judge() {
	rep(i,1,n) if (!vis[i]) {
		ans=0; dfs(i);
		if (ans<=2) continue;
		rep(j,1,ans) {
			int cnt=0;
			for (int i=head[s[j]]; i!=0; i=edge[i].nxt)
				cnt++;
			if (cnt!=ans-1) return 0;
		}
	}
	return 1;
}
int main() {
	read(n); read(m);
	rep(i,1,m) {
		int x,y; read(x); read(y);
		addedge(x,y); addedge(y,x);
	}
	if (judge()) puts("YES"); else puts("NO");
	return 0;
}