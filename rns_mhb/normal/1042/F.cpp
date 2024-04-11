#include <bits/stdc++.h>
using namespace std;

inline char nc(){
  static char buf[100000],*p1=buf,*p2=buf;
  if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }
  return *p1++;
}

inline int getint(){
  int x;
  char c=nc(),b=1;
  if(c == -1)
	return 0;
  for (;!(c>='0' && c<='9');c=nc()) if (c=='-') b=-1;
  for (x=0;c>='0' && c<='9';x=x*10+c-'0',c=nc()); x*=b;
  return x;
}

const int INF = 1e9;

const int R = 100;
#define N 1010101
const int K = 20;

int f[K][N], fa[N], dp[N];

int n, m, rt;

vector <int> v[N];

void dfs(int x, int y = 0) {
	fa[x] = y;
	dp[x] = dp[y] + 1;
	for (int i = 0, z; i < v[x].size(); i ++) {
		z = v[x][i];
		if (z == y) continue;
		dfs(z, x);
	}
}

int bit[N];

void prep_lca() {
	for (int i = 1; i <= n; i ++) f[0][i] = fa[i];
	for (int k = 1; k < K; k ++) for (int i = 1; i <= n; i ++) f[k][i] = f[k-1][f[k-1][i]];
	for (int k = 0; k < K; k ++) bit[1<<k] = k;
}

int kth_father(int x, int y) {
	while (y) {
		x = f[bit[y&-y]][x];
		y -= y & -y;
	}
	return x;
}

int LCA(int x, int y) {
	if (dp[x] < dp[y]) y = kth_father(y, dp[y] - dp[x]);
	if (dp[x] > dp[y]) x = kth_father(x, dp[x] - dp[y]);
	if (x == y) return x;
	for (int k = K - 1; k >= 0; k --) if (f[k][x] != f[k][y]) x = f[k][x], y = f[k][y];
	return fa[x];
}

int ans;

int e;
int leaf[N];

bool cmp(int i, int j) {
	return dp[i] > dp[j];
}

void calc_leaves() {
	for (int i = 1; i <= n; i ++) if ((int)v[i].size() == 1) leaf[++e] = i;
	sort(leaf + 1, leaf + e + 1, cmp);
}

int d[N];
int q[N];

void use(int st) {
	ans ++;
	int e = 0;
	q[++e] = st;
	d[st] = 0;
	for (int f = 1; f <= e; f ++) {
		int x = q[f];
		if (d[x] == m) break;
		for (int i = 0, y; i < v[x].size(); i ++) {
			y = v[x][i];
			if (d[y] <= d[x] + 1) continue;
			d[y] = d[x] + 1;
			q[++e] = y;
		}
	}
}

void solve() {
	for (int i = 1; i <= n; i ++) d[i] = INF;
	for (int i = 1; i <= e; i ++) {
		if (d[leaf[i]] == INF) {
			use(leaf[i]);
		}
	}
}

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1, x, y; i < n; i ++) {
		x = getint(), y = getint();
		v[x].push_back(y);
		v[y].push_back(x);
	}
	rt = 0;
	for (int i = 1; i <= n; i ++) if ((int)v[i].size() >= 2) rt = i;
	assert(rt);
	dfs(rt);
	//prep_lca();
	calc_leaves();
	solve();
	printf("%d\n", ans);

	return 0;
}