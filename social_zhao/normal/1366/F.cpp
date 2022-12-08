#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2005, inf = 0x3f3f3f3f3f3f3f3f, P = 1e9 + 7, inv2 = (P + 1) / 2;
int n, m, q, _u[N], _v[N], _w[N];
struct Edge { int v, nxt, w; } edge[N << 1];
int head[N], tot;
int f[N][N], L[N], R[N], st[N], top;
struct Line { int k, b; } ln[N];

void add(int u, int v, int w) { edge[++tot] = (Edge){ v, head[u], w }, head[u] = tot; }
double Inter(Line a, Line b) { return 1.0 * (b.b - a.b) / (a.k - b.k); }
int F(Line L, int x) { return (L.k * x % P + L.b) % P; }
int S(Line L, int l, int r) { 
	if(l > r) return 0; 
	return (F(L, l) + F(L, r)) % P * (r - l + 1) % P * inv2 % P; 
}

signed main() {
	n = get(), m = get(), q = get();
	for(int i = 1; i <= m; i++) _u[i] = get(), _v[i] = get(), _w[i] = get(), add(_u[i], _v[i], _w[i]), add(_v[i], _u[i], _w[i]);
	if(n == 2 && m == 1) { printf("%lld", q * (q + 1) / 2 % P * _w[1] % P); return 0; }
	memset(f, -0x3f, sizeof(f)), f[0][1] = 0;
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
			for(int k = head[j]; k; k = edge[k].nxt)
				f[i][j] = max(f[i][j], f[i - 1][edge[k].v] + edge[k].w);
	for(int i = 1; i <= m; i++) {
		ln[i].k = _w[i], ln[i].b = -inf;
		for(int j = 1; j <= m; j++) 
			ln[i].b = max(ln[i].b, max(f[j][_u[i]] - j * _w[i], f[j][_v[i]] - j * _w[i]));
	}
	sort(ln + 1, ln + 1 + m, [](Line x, Line y) { return x.k == y.k? x.b > y.b : x.k < y.k; });
	for(int i = 1; i <= m; i++) {
		if(i && ln[i].k == ln[i - 1].k) continue;
		while(top > 1 && Inter(ln[st[top - 1]], ln[st[top]]) >= Inter(ln[st[top]], ln[i])) --top;
		st[++top] = i;
	}
	L[1] = m + 1, R[1] = floor(Inter(ln[st[1]], ln[st[2]]));
	for(int i = 2; i < top; i++) {
		L[i] = max(R[i - 1] + 1, (int)ceil(Inter(ln[st[i - 1]], ln[st[i]])));
		R[i] = min((int)floor(Inter(ln[st[i]], ln[st[i + 1]])), q);
	}
	L[top] = max(R[top - 1] + 1, (int)ceil(Inter(ln[st[top - 1]], ln[st[top]]))), R[top] = q;
	int ans = 0;
	for(int i = 1; i <= top; i++) 
		ans = (ans + S(ln[st[i]], max(L[i], m + 1), min(R[i], q)));
	for(int i = 1; i <= m; i++) {
		int mx = 0;
		for(int j = 1; j <= n; j++) mx = max(mx, f[i][j]);
		ans = (ans + mx) % P;
	}
	printf("%lld\n", ans);
	return 0;
}

/*
4 3 21
1 4 999
1 2 1
2 3 1000
*/