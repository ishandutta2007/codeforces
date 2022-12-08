#include <bits/stdc++.h>

using namespace std;

int vis[50];
int val[50];
int n, x, y;
int ans = 0;

void dfs(int p, int m) {
	if (p == x + y)
		ans = max(ans, m);
	vis[p] = 1;
	for (int i = p + 1; i <= x + y; ++i) {
		if ((i >= x && vis[i - x]) || (i >= y && vis[i - y]))
			continue;
		dfs(i, m + val[p]);
	}
	vis[p] = 0;
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d%d%d", &n, &x, &y);
	--n;
	for (int i = 0; i < x + y; ++i) {
		val[i] = n / (x + y) + (n % (x + y) >= i);
	}
	if (x == y) {
		for (int i = 0; i < x; ++i) {
			ans += val[i];
		}
	} else {
		dfs(0, 0);
	}
	printf("%d\n", ans);
	return 0;
}