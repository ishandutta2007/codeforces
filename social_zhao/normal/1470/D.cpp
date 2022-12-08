#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 3e5 + 5;
int n, m, fa[N], col[N], inq[N];
struct Edge { int v, nxt; } edge[N << 1];
int head[N], tot;

void clear(int n) { for(int i = 0; i <= n; i++) fa[i] = i, head[i] = col[i] = inq[i] = 0; tot = 0; }
void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot; }
int find(int x) { return x == fa[x]? x : fa[x] = find(fa[x]); }
void merge(int x, int y) { x = find(x), y = find(y); if(x != y) fa[x] = y; }

queue<int> q;

void solve() {
	n = get(), m = get();
	clear(n);
	for(int i = 1, u, v; i <= m; i++) u = get(), v = get(), add(u, v), add(v, u), merge(u, v);
	for(int i = 1; i <= n; i++) if(find(i) != find(1)) { printf("NO\n"); return; }
	printf("YES\n");
	while(q.size()) q.pop();
	q.push(1), inq[1] = 1;
	while(q.size()) {
		int u = q.front(); q.pop();
		int now = 1;
		for(int i = head[u]; i; i = edge[i].nxt) {
			int v = edge[i].v;
			if(!inq[v]) q.push(v), inq[v] = 1;
			else if(col[v]) now = 0;
		}
		col[u] = now;
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++) cnt += col[i];
	printf("%d\n", cnt);
	for(int i = 1; i <= n; i++) if(col[i]) printf("%d ", i); printf("\n");
}

int main() {
	int T = get();
	while(T--) solve(); 
	return 0;
}