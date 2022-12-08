#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 6e5 + 5;
int n, m, x, a[N], vis[N], bin[N], l, r; 
struct Edge { int v, nxt; } edge[N];
int head[N], tot;

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot; }

void dfs(int u) {
	vis[u] = 1;
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(vis[v]) continue;
		dfs(v);
		if(a[u] + a[v] >= x) a[u] = a[u] + a[v] - x, bin[l++] = (i + 1) >> 1;
		else bin[r--] = (i + 1) >> 1;
	}
}

signed main() {
	n = get(), m = get(), x = get();
	int sum = 0;
	for(int i = 1; i <= n; i++) a[i] = get(), sum += a[i];
	if(sum < (n - 1) * x) return printf("NO\n"), 0;
	for(int i = 1, u, v; i <= m; i++) u = get(), v = get(), add(u, v), add(v, u);
	l = 1, r = n - 1, dfs(1);
	printf("YES\n");
	for(int i = 1; i <= n - 1; i++) printf("%lld\n", bin[i]);
	return 0;
}