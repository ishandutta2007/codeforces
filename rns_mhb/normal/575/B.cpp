#include <bits/stdc++.h>
using namespace std;

#define N 100010

typedef long long ll;
ll expmod(ll a, ll b, ll mod) {
	ll rlt = 1;
	for (a %= mod; b; a = a * a % mod, b >>= 1) if (b & 1) rlt = rlt * a % mod;
	return rlt;
}
const int mod = 1e9 + 7;

int n;
vector<int> g[N];

map<int, int> bad[N];

int dp[N];
int p[N][18];

void dfs(int u, int pa = 0) {
    p[u][0] = pa;
    dp[u] = dp[pa] + 1;
    for (int v:g[u]) {
        if (v == pa) continue;
        dfs(v, u);
    }
}

int anc(int x, int d) {
    for (int i = 31 - __builtin_clz(d); i >= 0; i --) if (d & (1 << i)) x = p[x][i];
    return x;
}

int lca(int x, int y) {
    if (dp[x] > dp[y]) x = anc(x, dp[x] - dp[y]);
    else if (dp[y] > dp[x]) y = anc(y, dp[y] - dp[x]);
    if (x == y) return x;
    for (int i = 31 - __builtin_clz(dp[x]); i >= 0; i --) {
        if (p[x][i] != p[y][i]) x = p[x][i], y = p[y][i];
    }
    return p[x][0];
}

int up[N], down[N];

void finish(int u) {
	for (int v:g[u]) {
		if (v == p[u][0]) continue;
		finish(v);
		up[u] += up[v];
		down[u] += down[v];
	}
}

int main() {
    scanf("%d", &n);
    for (int i = 1, x, y, c; i < n; i ++) {
        scanf("%d%d%d", &x, &y, &c);
        g[x].push_back(y);
        g[y].push_back(x);
        if (c) bad[y][x] = 1;
    }
    dfs(1);
	for (int j = 1; j <= 31 - __builtin_clz(n); j ++) {
		for (int i = 1; i <= n; i ++) p[i][j] = p[p[i][j-1]][j-1];
	}
	int a = 1, b;
	int k;
	scanf("%d", &k);
	while (k --) {
		scanf("%d", &b);
		if (a == b) continue;
		int rt = lca(a, b);
		up[a] ++;
		up[rt] --;
		down[b] ++;
		down[rt] --;
		a = b;
	}
	finish(1);
	int ans = 0;
	for (int i = 2; i <= n; i ++) {
		int j = p[i][0];
		if (bad[i][j]) ans = (ans + expmod(2, up[i], mod) - 1) % mod;
		else if (bad[j][i]) ans = (ans + expmod(2, down[i], mod) - 1) % mod;
	}
	cout<<ans<<endl;
}