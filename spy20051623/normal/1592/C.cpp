#include <bits/stdc++.h>

using namespace std;

int a[100005];
vector<int> g[100005];
int cnt, sum;

int dfs(int p, int f) {
	int res = a[p];
	for (int i: g[p]) {
		if (i != f) res ^= dfs(i, p);
	}
	if (res == sum) {
		++cnt;
		return 0;
	}
	return res;
}

void solve() {
	int n, k;
	scanf("%d%d", &n, &k);
	sum = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		sum ^= a[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	if (sum == 0) {
		printf("YES\n");
	} else if (k == 2) {
		printf("NO\n");
	} else {
		cnt = 0;
		dfs(1, 0);
		if (cnt > 1) printf("YES\n");
		else printf("NO\n");
	}
	for (int i = 1; i <= n; ++i) {
		g[i].clear();
	}
}
	
int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}