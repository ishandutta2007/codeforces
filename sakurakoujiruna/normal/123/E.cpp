#include <bits/stdc++.h>
using namespace std;

const int N = int(1e5) + 11;
using ll = long long;

int x[N], y[N];
vector <int> e[N];
int sz[N];
ll f[N];

void dfs1(int x, int p = -1) {
	sz[x] = 1;
	for(int i : e[x]) if(i != p) {
		dfs1(i, x);
		sz[x] += sz[i];
	}
}

void dfs2(int x, ll sum, int p = -1) {
	f[x] = sum;
	for(int i : e[x]) if(i != p)
		dfs2(i, sum + ll(y[i]) * (sz[1] - sz[i]) -
			ll(y[x]) * sz[i], x);
}

int main() {
	int n; scanf("%d", &n);
	for(int i = 1; i < n; i ++) {
		int u, v; scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i = 1; i <= n; i ++)
		scanf("%d%d", x + i, y + i);

	dfs1(1);
	ll sum = 0;
	for(int i = 1; i <= n; i ++)
		sum += ll(y[i]) * sz[i];
	dfs2(1, sum);

	ll sx = accumulate(x + 1, x + n + 1, 0LL);
	ll sy = accumulate(y + 1, y + n + 1, 0LL);
	double ans = 0;
	for(int i = 1; i <= n; i ++)
		ans += (sz[1] - double(f[i]) / sy) * x[i];
	ans /= sx;
	printf("%.12f\n", ans);
	return 0;
}