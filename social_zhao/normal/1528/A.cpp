#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 1e5 + 5;
int n, l[N], r[N], f[N][2];
vector<int> son[N];

void add(int u, int v) { son[u].push_back(v); }

void dfs(int u, int fa) {
	for(int i = 0; i < son[u].size(); ++i) {
		int v = son[u][i];
		if(v == fa) continue;
		dfs(v, u);
		f[u][0] += max(abs(l[u] - l[v]) + f[v][0], abs(l[u] - r[v]) + f[v][1]);
		f[u][1] += max(abs(r[u] - l[v]) + f[v][0], abs(r[u] - r[v]) + f[v][1]);
	}
}

void clear(int n) {
	for(int i = 1; i <= n; i++) l[i] = r[i] = f[i][0] = f[i][1] = 0, son[i].clear();
}

void solve() {
	n = get();
	for(int i = 1; i <= n; i++) l[i] = get(), r[i] = get();
	for(int i = 1, u, v; i < n; i++) u = get(), v = get(), add(u, v), add(v, u);
	dfs(1, 0);
	printf("%lld\n", max(f[1][0], f[1][1]));
	clear(n);
}

signed main() {
	int T = get();
	while(T--) solve(); 
	return 0;
}

/*
1
3
1 3
4 6
7 9
1 2
2 3
*/