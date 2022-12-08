#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 114514, M = 1e6 + 5, inf = 0x3f3f3f3f;
const char mpc[] = { 'D', 'U', 'L', 'R' };
const int dx[] = { 1, -1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };
int n, m, s, t, ss, tt, sum;
int a[N], lim[N];
struct Edge { int v, nxt, f; } edge[M];
int head[N], tot = 1, deg[N];
int d[N], cur[N];
int ans[N];
char dir[N];

void clear() {
	for(int i = 0; i <= tt; i++) {
		a[i] = lim[i] = head[i] = deg[i] = d[i] = cur[i] = ans[i] = dir[i] = 0;
	}
	sum = 0, tot = 1;
}

void addedge(int u, int v, int f) { edge[++tot] = (Edge){ v, head[u], f }, head[u] = tot; }
void insedge(int u, int v, int lo, int hi) { addedge(u, v, hi - lo), addedge(v, u, 0), deg[u] -= lo, deg[v] += lo; }
int id(int x, int y) { return (x - 1) * m + y; }
int chk(int x, int y) { return 1 <= x && x <= n && 1 <= y && y <= m; }

queue<int> q;
int bfs() {
	for(int i = 0; i <= tt; i++) d[i] = 0, cur[i] = head[i];
	d[ss] = 1, q.push(ss);
	while(q.size()) {
		int u = q.front(); q.pop();
		for(int i = head[u]; i; i = edge[i].nxt) {
			int v = edge[i].v, f = edge[i].f;
			if(d[v] || !f) continue;
			d[v] = d[u] + 1, q.push(v);
		}
	}
	return d[tt];
}

int dfs(int u, int flow) {
	if(u == tt || !flow) return flow;
	int rest = flow;
	for(int& i = cur[u]; i; i = edge[i].nxt) {
		int v = edge[i].v, f = edge[i].f;
		if(d[v] != d[u] + 1 || !f) continue;
		int x = dfs(v, min(rest, f));
		if(!x) d[v] = 0;
		else edge[i].f -= x, edge[i ^ 1].f += x, rest -= x;
		if(!rest) break;
	}
	return flow - rest;
}

int Dinic() {
	int res = 0;
	while(bfs())
		res += dfs(ss, inf);
	return res;
}

void solve() {
	n = get(), m = get();
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= m; j++)
			a[id(i, j)] = get();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			int flag = 0;
			for(int k = 0; k < 4; k++) if(chk(i + dx[k], j + dy[k])) 
				flag |= a[id(i, j)] > a[id(i + dx[k], j + dy[k])];
			lim[id(i, j)] = !flag;
		}
	
	s = 0, t = n * m + 1, ss = t + 1, tt = ss + 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			if((i + j) & 1) {
				insedge(s, id(i, j), lim[id(i, j)], 1);
				for(int k = 0; k < 4; k++) {
					int nx = i + dx[k], ny = j + dy[k];
					if(chk(nx, ny) && a[id(i, j)] == a[id(nx, ny)]) insedge(id(i, j), id(nx, ny), 0, inf);
				}
			}
			else {
				insedge(id(i, j), t, lim[id(i, j)], 1);
			}
		}
	for(int i = 0; i <= t; i++) {
		if(deg[i] > 0) sum += deg[i], insedge(ss, i, 0, deg[i]);
		if(deg[i] < 0) insedge(i, tt, 0, -deg[i]); 
	}
	insedge(t, s, 0, inf);
	int flow = Dinic();
	// no solution
	if(flow != sum) return printf("NO\n"), void();
	// construct
	for(int x = 1; x <= n; x++) {
		for(int y = 1; y <= m; y++) {
			if(!((x + y) & 1)) continue;
			int u = id(x, y);
			for(int i = head[u]; i; i = edge[i].nxt) {
				int v = edge[i].v, f = edge[i ^ 1].f;
				if(!f) continue;
				for(int k = 0; k < 4; k++) {
					int nx = x + dx[k], ny = y + dy[k];
					if(!chk(nx, ny)) continue;
					if(id(nx, ny) == v) {
						dir[id(x, y)] = mpc[k], dir[id(nx, ny)] = mpc[k ^ 1];
						ans[id(x, y)] = 1, ans[id(nx, ny)] = a[id(x, y)] - 1;
					}
				}
			}
		}
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			if(ans[id(i, j)]) continue;
			for(int k = 0; k < 4; k++) {
				int nx = i + dx[k], ny = j + dy[k];
				if(!chk(nx, ny)) continue;
				if(a[id(nx, ny)] < a[id(i, j)]) {
					dir[id(i, j)] = mpc[k];
					ans[id(i, j)] = a[id(i, j)] - a[id(nx, ny)];
				}
			}
			assert(ans[id(i, j)]);
		}
	// print
	printf("YES\n");
	for(int i = 1; i <= n; i++, printf("\n"))
		for(int j = 1; j <= m; j++)
			printf("%d ", ans[id(i, j)]);
	for(int i = 1; i <= n; i++, printf("\n"))
		for(int j = 1; j <= m; j++)
			printf("%c ", dir[id(i, j)]);
}

int main() {
	int T = get();
	while(T--) clear(), solve(); 
	return 0;
}

/*
3
3 4
7 6 7 8
5 5 4 4
5 7 4 4
1 1
5
3 4
7 6 7 8
5 5 4 4
5 7 4 4
*/