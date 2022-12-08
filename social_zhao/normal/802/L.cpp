#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e6 + 5, P = 1e9 + 7;
int n;
struct Edge {
	int v, nxt, w;
} edge[N << 1];
int head[N], tot = 1, A[N], B[N];

void add(int u, int v, int w) {
	edge[++tot].v = v, edge[tot].w = w, edge[tot].nxt = head[u], head[u] = tot;
} 

int qpow(int x, int y) {
	int res = 1;
	while(y) {
		if(y & 1) res = res * x % P;
		x = x * x % P;
		y >>= 1;
	}
	return res;
}

void dfs(int u, int fa) {
	int Deg = 0, SumA = 0, SumB = 0, SumW = 0, isleaf = 1;
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v, w = edge[i].w;
		Deg++, SumW = (SumW + w) % P;
		if(v == fa) continue;
		isleaf = 0;
		dfs(v, u);
		SumA = (SumA + A[v]) % P, SumB = (SumB + B[v]) % P;
	}
	if(isleaf) return; 
	A[u] = qpow(Deg - SumA, P - 2), B[u] = (SumB + SumW) * qpow(Deg - SumA, P - 2) % P;
}

signed main() {
	n = get();
	for(int i = 1, u, v, w; i < n; i++) u = get(), v = get(), w = get(), add(u, v, w), add(v, u, w);
	dfs(0, -1);
	printf("%lld\n", (B[0] + P) % P);
	return 0;
}