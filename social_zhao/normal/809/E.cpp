#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5, P = 1e9 + 7;
int n, pos[N], a[N];
int pri[N], ptot, phi[N], mu[N], vis[N], F[N];
int dfn[N], tim;
int key[N], cnt, bin[N], st[N], top;
struct Edge { int v, nxt; } edge[N << 1];
int head[N], tot, f[N][18], dep[N];
vector<int> adj[N];
int sze[N], g[N], ans = 0;

int qpow(int x, int y) {
	int res = 1;
	while(y) res = res * ((y & 1)? x : 1) % P, x = x * x % P, y >>= 1;
	return res;
}

void inc(int &x, int y) { x = (x + y) % P; }
void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot; }

void init(int n) {
	phi[1] = 1, mu[1] = 1;
	for(int i = 2; i <= n; i++) {
		if(!vis[i]) pri[++ptot] = i, phi[i] = i - 1, mu[i] = -1;
		for(int j = 1; j <= ptot && i * pri[j] <= n; j++) {
			vis[i * pri[j]] = 1;
			if(i % pri[j] == 0) { phi[i * pri[j]] = phi[i] * pri[j]; break; }
			phi[i * pri[j]] = phi[i] * (pri[j] - 1), mu[i * pri[j]] = -mu[i];
		}
	}
	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; j += i)
			inc(F[j], i * qpow(phi[i], P - 2) % P * mu[j / i] % P);
}

void GetDfn(int u, int lst) {
	dfn[u] = ++tim, dep[u] = dep[lst] + 1, f[u][0] = lst;
	for(int i = 1; i <= 17; i++) f[u][i] = f[f[u][i - 1]][i - 1];
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(v == lst) continue;
		GetDfn(v, u);
	}
}

int lca(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 17; i >= 0; i--) if(dep[f[x][i]] >= dep[y]) x = f[x][i];
	if(x == y) return x;
	for(int i = 17; i >= 0; i--) if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
}

void dfs(int u, int lst) {
	if(key[u]) sze[u] = phi[a[u]], g[u] = 0;
	else sze[u] = 0, g[u] = 0;
	for(auto v : adj[u]) {
		int w = dep[v] - dep[u];
		if(v == lst) continue;
		dfs(v, u), inc(sze[u], sze[v]), inc(g[u], g[v] + w * sze[v]);
	}
}

void df5(int u, int lst, int gl, int sl) {
	if(key[u]) inc(ans, phi[a[u]] * (g[u] + gl));
	for(auto v : adj[u]) {
		int w = dep[v] - dep[u];
		if(v == lst) continue;
		int ns = (sze[u] + sl - sze[v] + P) % P, ng = (gl + g[u] - g[v] - sze[v] * w + ns * w) % P;
		df5(v, u, ng, ns);
	}
}

int Solve(int T) {
	top = cnt = 0;
	for(int i = 1; i <= n / T; i++) bin[++cnt] = pos[i * T], key[pos[i * T]] = 1;
	sort(bin + 1, bin + 1 + cnt, [](int x, int y) { return dfn[x] < dfn[y]; });
	adj[1].clear(), st[++top] = 1;
	for(int i = 1; i <= cnt; i++) {
		if(bin[i] == 1) continue;
		int l = lca(bin[i], st[top]);
		if(l != st[top]) {
			while(dfn[l] < dfn[st[top - 1]]) adj[st[top - 1]].push_back(st[top]), --top;
			if(dfn[l] != dfn[st[top - 1]]) adj[l].clear(), adj[l].push_back(st[top]), st[top] = l;
			else adj[l].push_back(st[top]), top--;
		}
		adj[bin[i]].clear(), st[++top] = bin[i]; 
	}
	for(int i = 1; i < top; i++) adj[st[i]].push_back(st[i + 1]);
	ans = 0;
	dfs(1, 0), df5(1, 0, 0, 0);
	for(int i = 1; i <= cnt; i++) key[bin[i]] = 0, bin[i] = 0;
	return ans;
}

main() {
	n = get();
	for(int i = 1; i <= n; i++) a[i] = get(), pos[a[i]] = i;
	for(int i = 1, u, v; i < n; i++) u = get(), v = get(), add(u, v), add(v, u);
	init(n);
	GetDfn(1, 0);
	int res = 0;
	for(int i = 1; i <= n; i++) inc(res, F[i] * Solve(i));
	res = (res % P + P) % P;
	res = res * qpow(n * (n - 1) % P, P - 2) % P;
	printf("%lld\n", res);
	return 0;
}

/*
5
1 3 2 4 5
2 5
3 2
2 4
1 2
*/