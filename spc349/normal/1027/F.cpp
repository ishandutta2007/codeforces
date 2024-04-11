#include <bits/stdc++.h>
using namespace std;

vector <int> all;
vector <int> pos[2000010];
int a[2000010], b[2000010];
int used[2000010], vis[2000010];
int n, lim;

bool dfs(int x, int ban) {
	vis[x] = 1;
	int need = a[x] + b[x] - ban;
	if (used[need]) return 0;
	used[need] = 1;
	for (int i = 0; i < pos[need].size(); i++) {
		int v = pos[need][i];
		if (v != x) {
			if (!dfs(v, need)) return 0;
		}
	}
	return 1;
}

struct UF {
	int fa[2000010], can[2000010];
	void init() {
		for (int i = 0; i <= 2000000; i++) {
			fa[i] = i, can[i] = 1;
		}
	}
	int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
	bool merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) {
			if (!can[x]) return 0;
			can[x] = 0;
			return 1;
		}
		fa[x] = y, can[y] &= can[x];
		return 1;
	}
}uf;

bool check(int mid) {
	lim = mid;
	for (int i = 0; i < all.size(); i++) {
		used[i] = i <= mid ? 0 : 1;
	}
	for (int i = 0; i < n; i++) {
		vis[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		if (b[i] > mid) {
			if (vis[i]) return 0;
			if (!dfs(i, b[i])) return 0;
		}
	}
	uf.init();
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			if (!uf.merge(a[i], b[i])) return 0;
		}
	}
	return 1;
}

int main () {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i], &b[i]);
		all.push_back(a[i]), all.push_back(b[i]);
	}
	sort(all.begin(), all.end()), all.resize(unique(all.begin(), all.end()) - all.begin());
	for (int i = 0; i < n; i++) {
		a[i] = lower_bound(all.begin(), all.end(), a[i]) - all.begin();
		b[i] = lower_bound(all.begin(), all.end(), b[i]) - all.begin();
		pos[a[i]].push_back(i), pos[b[i]].push_back(i);
	}
	int l = 0, r = (int)all.size();
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l == all.size() ? -1 : all[l]);
	return 0;
}