#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 4e5 + 5;
int n, fib[N], mx, sze[N], vis[N << 1];
struct Edge { int v, nxt; } edge[N << 1];
int head[N], tot = 1, node, mid;

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot; }

void GetMid(int u, int fa, int now) {
	sze[u] = 1;
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(vis[i] || v == fa) continue;
		GetMid(v, u, now), sze[u] += sze[v];
		if(sze[v] == fib[now - 1]) mid = i;
		if(sze[v] == fib[now - 2]) mid = i ^ 1;
	}
}

int judge(int u, int now) {
	mid = 0;
	GetMid(u, 0, now);
	if(sze[u] <= 3) return 1;
	if(!mid || sze[u] != fib[now]) return 0;
	vis[mid] = vis[mid ^ 1] = 1;
	int x = edge[mid].v, y = edge[mid ^ 1].v;
	return judge(x, now - 1) && judge(y, now - 2);
}

int main() {
	n = get();
	if(n == 1) return 0 * printf("YES\n");
	fib[0] = fib[1] = 1;
	for(int i = 2; i <= n && fib[i - 1] + fib[i - 2] <= n; i++) fib[i] = fib[i - 1] + fib[i - 2], mx = i;
	if(n != fib[mx]) return 0 * printf("NO\n");
	for(int i = 1, u, v; i < n; i++) u = get(), v = get(), add(u, v), add(v, u);
	int res = judge(1, mx);
	if(res == 1) printf("YES\n");
	else printf("NO\n");
	return 0;
}