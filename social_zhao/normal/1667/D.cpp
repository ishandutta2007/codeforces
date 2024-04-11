#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
int n;
struct Edge { int v, nxt; } edge[N << 1];
int head[N], tot, flag;
int deg[N], prt[N];

void add(int u, int v) { edge[++tot] = (Edge){ v, head[u] }, head[u] = tot, deg[v] ^= 1; }

void dfs(int u, int lst) {
	int cnt[2] = { 0, 0 };
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(v == lst) continue;
		dfs(v, u), ++cnt[prt[v]];
	}
	prt[u] = cnt[0] >= cnt[1];
	if(u != 1) ++cnt[prt[u]];
	if(cnt[0] + deg[u] != cnt[1]) flag = 1;
}

void print(int u, int lst) {
	queue<int> bin[2];
	vector<int> son;
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(v != lst) bin[prt[v]].push(v);
	}
	if(u != 1) bin[prt[u]].push(lst);
	
	int now = deg[u];
	
	while(bin[now].size()) {
		int v = bin[now].front(); bin[now].pop();
		son.emplace_back(v), now ^= 1;
	}
	
	for(auto v : son) {
		if(v == lst) printf("%d %d\n", u, lst);
		else print(v, u);
	}
}

void solve() {
	n = get();
	
	for(int i = 1; i <= n; i++) deg[i] = 0, prt[i] = 0, head[i] = 0;
	tot = 0;
	
	for(int i = 1, u, v; i < n; i++) u = get(), v = get(), add(u, v), add(v, u);
	
	flag = 0, dfs(1, 0);
	if(flag) return printf("NO\n"), void();
	
	printf("YES\n");
	print(1, 0);
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}