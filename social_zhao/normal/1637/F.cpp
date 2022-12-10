#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n, h[N], rt, f[N], g[N];
struct Edge { int v, nxt; } edge[N << 1];
int head[N], tot;

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot; }

void dfs(int u, int lst) {
	vector<int> son;
	son.push_back(0);
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(v == lst) continue;
		dfs(v, u), f[u] += f[v], son.push_back(g[v]);
	}
	sort(son.begin(), son.end(), greater<int>());
	int ber = lst? 0 : 1;
	for(int i = 0; i <= ber; i++) f[u] += max(0ll, h[u] - son[i]);
	g[u] = max(h[u], son[0]);
}

main() {
	n = get();
	for(int i = 1; i <= n; i++) h[i] = get(), rt = h[i] > h[rt]? i : rt;
	for(int i = 1, u, v; i < n; i++) u = get(), v = get(), add(u, v), add(v, u);
	dfs(rt, 0); 
	cout << f[rt] << endl;
	return 0;
}