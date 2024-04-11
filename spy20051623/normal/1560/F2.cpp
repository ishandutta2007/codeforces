#include <bits/stdc++.h>

using namespace std;

char s[15];
int vis[10];
long long len, ans;

void dfs(int p, int k, long long n, int f) {
	if (k == -1) return;
	if (p >= len) {
		ans = min(ans, n);
		return;
	}
	if (f) {
		int minm;
		if (k) minm = 0;
		else {
			for (int i = 0; i < 10; ++i) {
				if (vis[i]) {
					minm = i;
					break;
				}
			}
		}
		for (int i = p; i < len; ++i) n = n * 10 + minm;
		ans = min(ans, n);
		return;
	}
	++vis[s[p] - '0'];
	dfs(p + 1, k - (vis[s[p] - '0'] == 1), n * 10 + s[p] - '0', 0);
	--vis[s[p] - '0'];
	if (s[p] != '9') {
		++vis[s[p] - '0' + 1];
		dfs(p + 1, k - (vis[s[p] - '0' + 1] == 1), n * 10 + s[p] - '0' + 1, 1);
		--vis[s[p] - '0' + 1];
	}
	int fd = 0;
	for (int i = s[p] - '0' + 2; i < 10; ++i) {
		if (vis[i]) {
			fd = i;
			break;
		}
	}
	if (fd) {
		++vis[fd];
		dfs(p + 1, k, n * 10 + fd, 1);
		--vis[fd];
	}
}

void solve() {
	int n, k;
	scanf("%d%d", &n, &k);
	sprintf(s, "%d", n);
	len = strlen(s), ans = 2e9;
	memset(vis, 0, sizeof vis);
	dfs(0, k, 0, 0);
	printf("%lld\n", ans);
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