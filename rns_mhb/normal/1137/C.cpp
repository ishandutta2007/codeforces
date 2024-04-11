#include <bits/stdc++.h>
using namespace std;

#define N 100010
template <class T> chkmax(T &a, T b) {if (a < b) a = b;}

int n, m, d;
vector<int> v[N], rv[N];

int C, col[N], ord[N], ft;
bool vis[N];
vector<int> cp[N];

void init() {
	for (int i = 1; i <= n; i ++) v[i].clear(), rv[i].clear(), col[i] = 0;
}
void dfs(int x) {
	vis[x] = 1;
	for (int i = 0; i < v[x].size(); i ++) if (!vis[v[x][i]]) dfs(v[x][i]);
	ord[ft--] = x;
}
void rdfs(int x) {
	col[x] = C;
	cp[C].push_back(x);
	for (int i = 0; i < rv[x].size(); i ++) if (!col[rv[x][i]]) rdfs(rv[x][i]);
}

bool a[N][55];

void SCC() {
	ft = n;
	for (int i = 1; i <= n; i ++) if (!vis[i]) dfs(i);
	C = 0;
	for (int i = 1; i <= n; i ++) if (!col[ord[i]]) C ++, rdfs(ord[i]);
}

int dp[N][55], dep[N];

int g;
void dfs_cycle(int x) {
	vis[x] = 1;
	for (int y:v[x]) {
		if (col[x] != col[y]) continue;
		if (vis[y]) {
			int old = dep[x] + 1;
			int cur = dep[y];
			if (old != cur) g = __gcd(g, abs(old - cur));
		}
		else {
			dep[y] = dep[x] + 1;
			dfs_cycle(y);
		}
	}
}

void func(int c) {
	g = d;
	dep[cp[c][0]] = 0;
	dfs_cycle(cp[c][0]);
	int max_val[55];
	fill_n(max_val, g, -1e9);
	for (int i = 0; i < g; i ++) {
		for (int u:cp[c]) {
			for (int j = (i + dep[u]) % g; j < d; j += g) chkmax(max_val[i], dp[u][j]);
		}
	}
	for (int i = 0; i < g; i ++) if (max_val[i] >= 0) {
		for (int x: cp[c]) {
			for (int j = i; j < d; j += g) if (a[x][(j+dep[x])%d]) {
				max_val[i] ++;
				break;
			}
		}
	}
	for (int u:cp[c]) for (int i = 0; i < d; i ++) {
		chkmax(dp[u][i], max_val[(i+g-dep[u]%g)%g]);
	}
	for (int u:cp[c]) for (int y:v[u]) if (col[y] != c) {
		for (int i = 0; i < d; i ++) chkmax(dp[y][(i+1)%d], dp[u][i]);
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &d);
	int x, y;
	while (m --) {
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		rv[y].push_back(x);
	}
	char s[55];
	for (int i = 1; i <= n; i ++) {
		scanf("%s", s);
		for (int j = 0; j < d; j ++) a[i][j] = s[j]-'0';
	}
	SCC();
	for (int i = 1; i <= n; i ++) for (int j = 0; j < d; j ++) dp[i][j] = -1e9;
	dp[1][0] = 0;
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= C; i ++) func(i);
	int ans = 0;
	for (int i = 1; i <= n; i ++) for (int j = 0; j < d; j ++) chkmax(ans, dp[i][j]);
	cout<<ans<<endl;
}