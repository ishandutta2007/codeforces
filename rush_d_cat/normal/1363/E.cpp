#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int n;
vector<int> g[N];
int mn[N],a[N],b[N],c[N];
int s1[N],s2[N];
void dfs(int u, int p) {
	mn[u] = min(a[u], mn[p]);
	if (u == 1) mn[u] = a[u];
	if (b[u] == 1) s1[u] = 1;
	if (c[u] == 1) s2[u] = 1; 
	for (auto v: g[u]) {
		if (v == p) continue;
		dfs(v, u);
		s1[u] += s1[v]; 
		s2[u] += s2[v];
	}
}
long long ans = 0;
void solve(int u, int p) {
	int A=0,B=0;
	if(b[u]==1 && c[u]==0) A++;
	if(b[u]==0 && c[u]==1) B++;
	for (auto v: g[u]) {
		if (v == p) continue;
		solve(v, u);
		if (s1[v] > s2[v]) A += s1[v]-s2[v];
		else B += s2[v]-s1[v];
	}
	// printf("mn[%d] = %d\n", u, mn[u]);
	ans += 2LL * min(A, B) * mn[u];
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d%d%d", &a[i],&b[i],&c[i]);
	}
	for (int i = 1; i < n; i ++) {
		int u, v; scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1, 1);
	if (s1[1] != s2[1]) {
		return !printf("-1\n");
	}
	solve(1, 1);
	cout << ans << endl;
}