#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define N 200100
const int inf = 1000000000;

vector <int> v[N];
int n, x, y, fa[N], f[N], g[N], son[N];

void dfs(int r) {
	int mn = inf, sum = 0, id;
	for(int i = 0; i < v[r].size(); i ++) {
		int k = v[r][i];
		if(k == fa[r]) continue;
		fa[k] = r;
		dfs(k);
		if(mn > g[k] - f[k]) mn = g[k] - f[k], id = k;
		sum += f[k];
		son[r] ++;
	}
	if(mn == inf) f[r] = g[r] = 1;
	else {
		g[r] = sum + mn;
		if(son[r] == 1) f[r] = g[r];
		else {
			mn = inf;
			for(int i = 0; i < v[r].size(); i ++) {
				int k = v[r][i];
				if(k == fa[r] || k == id) continue;
				if(mn > g[k] - f[k]) mn = g[k] - f[k];
			}
			if(mn > 1) f[r] = g[r]; else f[r] = g[r] + mn - 1;
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &x, &y);
	for(int a, b, i = 1; i < n; i ++) {
		scanf("%d%d", &a, &b);
		v[a].push_back(b); v[b].push_back(a);
	}
	dfs(1);
	if(x <= y) {
		printf("%I64d\n", 1LL * x * (n - f[1]) + 1LL * y * (f[1] - 1));
	} else {
		int k;
		for(k = 1; k <= n; k ++) if(v[k].size() == n - 1) break;
		if(k > n) printf("%I64d\n", 1LL * y * (n - 1));
		else printf("%I64d\n", 1LL * y * (n - 2) + x);
	}
	return 0;
}