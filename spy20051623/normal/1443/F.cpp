#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
const int mod = 998244353;
int a[N], b[N], lst[N], nxt[N], vis[N];

void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	a[n + 1] = 0;
	for (int i = 1; i <= n; ++i) {
		lst[a[i]] = a[i - 1];
		nxt[a[i]] = a[i + 1];
		vis[i] = 0;
	}
	for (int i = 0; i < m; ++i) scanf("%d", &b[i]), vis[b[i]] = 1;
	vis[0] = vis[n + 1] = 1;
	long long ans = 1;
	for (int i = 0; i < m; ++i) {
		int cnt = 0;
		if (vis[lst[b[i]]]) ++cnt;
		if (vis[nxt[b[i]]]) ++cnt;
		if (cnt == 2) {
			puts("0");
			return;
		} else if (cnt == 1) {
			if (vis[lst[b[i]]]) {
				lst[nxt[nxt[b[i]]]] = b[i];
				nxt[b[i]] = nxt[nxt[b[i]]];
			} else {
				nxt[lst[lst[b[i]]]] = b[i];
				lst[lst[b[i]]] = lst[b[i]];
			}
		} else ans = ans * 2 % mod;
		vis[b[i]] = 0;
	}
	printf("%lld\n", ans);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}