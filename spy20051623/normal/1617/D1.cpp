#include <bits/stdc++.h>

using namespace std;

int ask(int x, int y, int z) {
	printf("? %d %d %d\n", x, y, z);
	fflush(stdout);
	int res;
	scanf("%d", &res);
	return res;
}

int ans[10005];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i += 3) {
		ans[i] = ask(i, i + 1, i + 2);
	}
	int g0, g1;
	for (int i = 1; i <= n; i += 3) {
		if (ans[i] == 0) {
			g0 = i;
			break;
		}
	}
	for (int i = 1; i <= n; i += 3) {
		if (ans[i] == 1) {
			g1 = i;
			break;
		}
	}
	int p0, p1;
	{
		int x = ask(g0, g0 + 1, g1);
		int y = ask(g0, g0 + 1, g1 + 1);
		int z = ask(g0, g0 + 1, g1 + 2);
		if (x) p0 = g0 + 2, p1 = g1;
		else if (y) p0 = g0 + 2, p1 = g1 + 1;
		else if (z) p0 = g0 + 2, p1 = g1 + 2;
		else {
			p0 = g0;
			x = ask(p0, g1, g1 + 1);
			if (x) p1 = g1;
			else p1 = g1 + 2;
		}
	}
	for (int i = 1; i <= n; i += 3) {
		if (ans[i] == 1) {
			int x = ask(p0, i, i + 1);
			int y = ask(p0, i + 1, i + 2);
			if (!x && !y) {
				ans[i] = 1;
				ans[i + 1] = 0;
				ans[i + 2] = 1;
			}
			if (!x && y) {
				ans[i] = 0;
				ans[i + 1] = 1;
				ans[i + 2] = 1;
			}
			if (x && !y) {
				ans[i] = 1;
				ans[i + 1] = 1;
				ans[i + 2] = 0;
			}
			if (x && y) {
				ans[i] = 1;
				ans[i + 1] = 1;
				ans[i + 2] = 1;
			}
		} else {
			int x = ask(p1, i, i + 1);
			int y = ask(p1, i + 1, i + 2);
			if (!x && !y) {
				ans[i] = 0;
				ans[i + 1] = 0;
				ans[i + 2] = 0;
			}
			if (!x && y) {
				ans[i] = 0;
				ans[i + 1] = 0;
				ans[i + 2] = 1;
			}
			if (x && !y) {
				ans[i] = 1;
				ans[i + 1] = 0;
				ans[i + 2] = 0;
			}
			if (x && y) {
				ans[i] = 0;
				ans[i + 1] = 1;
				ans[i + 2] = 0;
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (!ans[i]) ++cnt;
	}
	printf("! %d", cnt);
	for (int i = 1; i <= n; ++i) {
		if (!ans[i]) printf(" %d", i);
	}
	putchar('\n');
	fflush(stdout);
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
#endif
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}