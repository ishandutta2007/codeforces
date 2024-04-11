#include <bits/stdc++.h>

using namespace std;

int a[100];
int n;

bool dfs(int p, int x, bool use) {
	if (p && !x && use)return true;
	if (p == n)return false;
	bool ans = false;
	ans |= dfs(p + 1, x + a[p], true);
	ans |= dfs(p + 1, x, use);
	ans |= dfs(p + 1, x - a[p], true);
	return ans;
}

void solve() {
	scanf("%d", &n);
	bool ok = false;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		if (!a[i])ok = true;
	}
	if (ok) {
		printf("YES\n");
		return;
	}
	ok = dfs(0, 0, false);
	if (ok)printf("YES\n");
	else printf("NO\n");
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