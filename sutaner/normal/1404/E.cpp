#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define maxs 200020
#define maxn 420
#define maxm 800020
using namespace std;

const int inf = 2000000000;

int n, m, S, T, all;
char g[maxn][maxn];
struct edge{
	int next, to, flow;
	edge(int next, int to, int flow) : next(next), to(to), flow(flow){}
	edge(){}
}e[maxm << 1];
int cnt = 1, h[maxs];
void Add_Edge(int x, int y, int z){
	e[++cnt] = edge(h[x], y, z);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x, 0);
	h[y] = cnt;
}
int d[maxs], cur[maxs], bfs[maxs], head, tail;
bool BFS(){
	rep(i, 1, all) d[i] = -1, cur[i] = h[i]; head = tail = 0;
	bfs[++head] = S, d[S] = 0;
	while (head != tail) {
		int x = bfs[++tail];
		erep(i, x) {
			if (!e[i].flow || d[e[i].to] != -1) continue;
			d[e[i].to] = d[x] + 1;
			bfs[++head] = e[i].to;
		}
	}
	return d[T] != -1;
}
int DFS(int x, int flow) {
	if (x == T) return flow;
	int rest = flow;
	erep2(i, x) { 
		if (!e[i].flow || d[e[i].to] != d[x] + 1) continue;
		int k = DFS(e[i].to, min(rest, e[i].flow));
		e[i].flow -= k, e[i ^ 1].flow += k, rest -= k;
		if (!rest) return flow;
	}
	return flow - rest;
}
void Dinic(int& maxflow){
	while (BFS()) maxflow += DFS(S, inf);
}
void recover(){
	rep(i, 1, all) h[i] = 0; cnt = 1;
}
int good[maxn][maxn];
int main(){
	scanf("%d%d", &n, &m);
	rep(i, 1, n) scanf("%s", g[i] + 1);
	int num = 0;
	rep(i, 1, n) rep(j, 1, m) if (g[i][j] == '#') num++;
	S = 1, T = 2, all = 2;
	srep(i, 1, n) rep(j, 1, m) {
		if (g[i][j] == '#' && g[i + 1][j] == '#') {
			Add_Edge(S, ++all, 1);
			good[i][j] = all;
		}
	}
	srep(j, 1, m) rep(i, 1, n){
		if (g[i][j] == '#' && g[i][j + 1] == '#') {
			Add_Edge(++all, T, 1);
			if (good[i - 1][j]) Add_Edge(good[i - 1][j], all, 1);
			if (good[i - 1][j + 1]) Add_Edge(good[i - 1][j + 1], all, 1);
			if (good[i][j]) Add_Edge(good[i][j], all, 1);
			if (good[i][j + 1]) Add_Edge(good[i][j + 1], all, 1);
		}
	}
	int maxflow = 0; Dinic(maxflow);
	cout << num - (all - 2 - maxflow); 
	return 0;
}