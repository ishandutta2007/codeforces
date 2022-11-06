//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
using namespace std;
typedef long long ll;
const int N = 2e3+5;

int n, a[N][N], tot, flg, dis[N][N];
struct Edge {
	int u, v, w;
	Edge(int a=0, int b=0, int c=0) : u(a), v(b), w(c) {}
	~Edge() {}
	friend bool operator < (const Edge &a, const Edge &b) {return a.w < b.w;}
}e[N*N];
void add(int u, int v, int w) {e[++tot] = Edge(u, v, w);}
struct Edge2 {
	int v, w, nxt;
	Edge2(int a=0, int b=0, int c=0) : v(a), w(b), nxt(c) {}
	~Edge2() {}
}e2[N<<1];
int ne = 1, h[N];
void add2(int u, int v, int w) {
//	printf("ADD %d <-> %d (%d)\n", u, v, w);
	e2[++ne] = Edge2(v, w, h[u]); h[u] = ne;
	e2[++ne] = Edge2(u, w, h[v]); h[v] = ne;
}

int fa[N];
void initDSU(int x) {rep(i, 1, x) fa[i] = i;}
int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
bool merge(int x, int y) {int u = find(x), v = find(y); if(u == v) return 0; fa[u] = v; return 1;}
void kruskal() {
	initDSU(n);
	sort(e+1, e+1+tot);
	int con = n;
	rep(i, 1, tot) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if(merge(u, v)) {add2(u, v, w); if(--con == 1) break;}
	}
}
void dfs(int u, int f, int s) {
	for(int i=h[u];i;i=e2[i].nxt) {
		int v = e2[i].v, w = e2[i].w;
		if(v != f) {dis[s][v] = dis[s][u] + w; dfs(v, u, s);}
	}
}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) rep(j, 1, n) {
		scanf("%d", &a[i][j]);
		if(a[i][j]) flg = 1;
		if(i < j) add(i, j, a[i][j]);
		else if(i == j) {if(a[i][j]) return puts("NO")&0;}
		else {if(a[i][j] != a[j][i]) return puts("NO")&0;}
	}
	if(!flg && n != 1) return puts("NO")&0;
	kruskal();
	rep(i, 1, n) dfs(i, 0, i);
//	rep(i, 1, n) rep(j, 1, n) printf("%d%c", dis[i][j], " \n"[j==n]);
	rep(i, 1, tot) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if(dis[u][v] != w) return puts("NO")&0;
	}
	puts("YES");
	return 0;
}