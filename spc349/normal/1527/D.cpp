#include <bits/stdc++.h>
using namespace std;

vector <int> from[200010];
int id[200010], sz[200010], TOT;
long long ans[200010];
int be[200010];

void dfs(int x, int last, int B = -1) {
	id[x] = ++TOT, sz[x] = 1, be[x] = B;
	for (auto v : from[x]) {
		if (v == last) continue;
		dfs(v, x, B == -1 ? v : B), sz[x] += sz[v];
	}
}

bool IsAnc(int x, int y) {return id[x] <= id[y] && id[x] + sz[x] > id[y];}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) from[i].clear();
		for (int i = 0; i <= n; i++) ans[i] = 0;
		for (int i = 1; i < n; i++) {
			int x, y; scanf("%d%d", &x, &y);
			from[x].push_back(y), from[y].push_back(x);
		}
		TOT = 0, dfs(0, 0);
		ans[0] = 1ll * n * (n - 1) / 2;
		int cur = 1;
		for (auto x : from[0]) ans[0] -= 1ll * cur * sz[x], cur += sz[x];
		cur = 1;
		for (auto x : from[0]) {
			int tmp = sz[x];
			if (IsAnc(x, 1)) tmp -= sz[1];
			ans[1] += 1ll * cur * tmp, cur += tmp;
		}
		int x = 1, y = 0;
		for (int i = 2; i <= n; i++) {
			if (i == n) {ans[n] = 1; break;}
			if (IsAnc(i, x) || IsAnc(i, y)) ans[i] = 0;
			else {
				int p = sz[x], q = sz[y];
				if (y == 0) q -= sz[be[1]];
				if (IsAnc(x, i)) p -= sz[i];
				if (y != 0 && IsAnc(y, i) || y == 0 && be[i] != be[1]) q -= sz[i];
				ans[i] = 1ll * p * q;
			}
			if (IsAnc(i, x) || IsAnc(i, y)) continue;
			if (IsAnc(x, i)) x = i;
			else if (be[i] == be[x]) break;
			else if (y == 0) y = i;
			else if (IsAnc(y, i)) y = i;
			else break;
		}
		for (int i = 0; i <= n; i++) printf("%I64d ", ans[i]); printf("\n");
	}
	return 0;
}