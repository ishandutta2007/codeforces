#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e6 + 5;
int n, a[N], b[N], fa[N], deg[N];
struct Edge { int v, nxt, a, b; } edge[N << 1];
int head[N], tot = 1;
int vis[N << 1];
int bin[N], top;

void clear() {
	memset(head, 0, sizeof(head)), tot = 1;
	memset(vis, 0, sizeof(vis));
	top = 0;
	memset(deg, 0, sizeof(deg));
}

int find(int x) { return x == fa[x]? x : fa[x] = find(fa[x]); }

void add(int u, int v, int a, int b) { 
	edge[++tot] = (Edge){ v, head[u], a, b }, head[u] = tot; 
	if(find(u) != find(v)) fa[find(u)] = find(v);
	++deg[v];
}

void Heracer(int u) {
	for(int &i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v, a = edge[i].a, b = edge[i].b;
		if(vis[i]) continue;
		vis[i] = vis[i ^ 1] = 1, Heracer(v);
		bin[++top] = b, bin[++top] = a;
	}
}

void solve(int x) {
	clear();	
	int base = (1 << x) - 1;
	for(int i = 0; i < 1 << x; i++) fa[i] = i;
	for(int i = 1; i <= n; i++) 
		add(a[i] & base, b[i] & base, 2 * i - 1, 2 * i),
		add(b[i] & base, a[i] & base, 2 * i, 2 * i - 1);
	int rt = find(a[1] & base);
	for(int i = 1; i <= n; i++) if(find(a[i] & base) != rt) return;
//	cout << "con" << endl;
	for(int i = 1; i <= n; i++) if(deg[a[i] & base] & 1 || deg[b[i] & base] & 1) return;
	Heracer(rt);
	printf("%d\n", x);
	for(int i = 1; i <= top; i++) printf("%d ", bin[i]);
	exit(0);
}

int main() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get(), b[i] = get();
	for(int i = 20; i >= 0; i--) 
		solve(i);
	return 0;
}