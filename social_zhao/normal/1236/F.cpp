#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 5e5 + 5, P = 1e9 + 7, inv2 = (P + 1) / 2;
int n, m, ans;
struct Edge { int v, nxt; } edge[N << 1];
int head[N], tot, deg[N];
int V, E, C, V2, E2, C2, VC, EC, VE;
int bin[N], out[N], top, lst[N], dep[N];
vector<int> cir[N];
map<int, int> mp[N];

int qpow(int x, int y) {
	int res = 1;
	while(y) res = res * ((y & 1)? x : 1) % P, x = x * x % P, y >>= 1;
	return res;
}

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot, ++deg[v]; }
void inc(int &x, int y) { x = (x + y) % P; }
void dec(int &x, int y) { x = (x - y + P) % P; }

void dfs(int u, int fa) {
	dep[u] = dep[fa] + 1, lst[u] = fa;
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(v == fa) continue;
		if(!mp[u][v]) {
			inc(E2, inv2 * inv2 % P); // 
			inc(E2, (deg[u] + deg[v] - 2) * inv2 % P * inv2 % P * inv2 % P); // 
			inc(E2, (m - deg[u] - deg[v] + 1) * inv2 % P * inv2 % P * inv2 % P * inv2 % P); //  
			mp[u][v] = mp[v][u] = 1;
		}
		
		if(dep[v]) {
			if(dep[v] > dep[u]) continue;
			int sze = 1, cnt = deg[v];
			for(int i = u; i != v; i = lst[i]) ++sze, cnt += deg[i];
			bin[++top] = sze, out[top] = cnt - 2 * sze;
			for(int i = u; i != v; i = lst[i]) cir[i].push_back(top);
			cir[v].push_back(top);
		}
		else {
			dfs(v, u);
		}
	}
}

main() {
	n = get(), m = get();
	for(int i = 1, u, v; i <= m; i++) u = get(), v = get(), add(u, v), add(v, u);
	dfs(1, 0);
	V = n * inv2 % P, E = m * inv2 % P * inv2 % P;
	for(int i = 1; i <= top; i++) {
		inc(C, qpow(inv2, bin[i]));
		inc(C2, qpow(inv2, bin[i]));
		
		inc(VC, qpow(inv2, bin[i]) * bin[i] % P);
		inc(VC, qpow(inv2, bin[i] + 1) * (n - bin[i]) % P);
		
		inc(EC, qpow(inv2, bin[i]) * bin[i] % P);
		inc(EC, qpow(inv2, bin[i] + 1) * out[i] % P);
		inc(EC, qpow(inv2, bin[i] + 2) * (m - bin[i] - out[i]) % P);
	}
	for(int i = 1; i <= top; i++) 
		inc(C2, (C - qpow(inv2, bin[i]) + P) * qpow(inv2, bin[i]) % P); 
	V2 = n * (n + 1) % P * inv2 % P * inv2 % P;
	VE = m * (2 * inv2 % P * inv2 % P + (n - 2) * inv2 % P * inv2 % P * inv2 % P) % P;
	for(int i = 1; i <= n; i++) {
		int sum = 0;
		for(auto j : cir[i]) 
			inc(sum, qpow(inv2, bin[j]));
		for(auto j : cir[i]) 
			inc(C2, (sum - qpow(inv2, bin[j]) + P) % P * qpow(inv2, bin[j]) % P);
	}
	int ans = V2 + E2 + C2 - 2 * VE - 2 * EC + 2 * VC - (V - E + C) * (V - E + C) % P;
//	cout << V2 << " " << E2 << " " << C2 << " " << VC << " " << EC << " " << VE << " " << (V - E + C) * (V - E + C) % P << endl; 
	ans = (ans % P + P) % P;
	cout << ans; 
	return 0;
}