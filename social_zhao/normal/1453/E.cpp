#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 2e5 + 5;
struct Edge { int v, nxt; } edge[N << 1];
int head[N], tot, ans;
int n, f[N], g[N];

void add(int u, int v) {
	edge[++tot].v = v, edge[tot].nxt = head[u], head[u] = tot;
}

int dfs(int u, int fa) {
	vector<int> s;
	for(int i = head[u]; i; i = edge[i].nxt) {
		int v = edge[i].v;
		if(v == fa) continue;
		s.push_back(dfs(v, u));
	}
	sort(s.begin(), s.end());
	int len = s.size();
	if(len) ans = max(ans, s[0]);
	if(len > 1) {
		if(u == 1) ans = max(ans, max(s[len - 1], s[len - 2] + 1));
		else ans = max(ans, s[len - 1] + 1);
	}
	if(!len) return 1;
	else return s[0] + 1;
}

void solve() {
	n = get();
	for(int i = 1, u, v; i < n; i++) u = get(), v = get(), add(u, v), add(v, u);
	dfs(1, 0);
	printf("%d\n", ans);
	for(int i = 1; i <= n; i++) head[i] = 0, f[i] = g[i] = 0;
	for(int i = 1; i <= tot; i++) edge[i].nxt = edge[i].v = 0;
	ans = 0;
}

int main() {
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
4
2 1
1 3
4 3
*/