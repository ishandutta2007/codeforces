#pragma GCC target("popcnt,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k, g[7][1000][9];
bool dead[1000];
struct point {
	int x, y;
} p[7], m[1000];

point operator-(const point &a, const point &b) {
	return (point){a.x - b.x, a.y - b.y};
}
ll det(const point &a, const point &b) {
	return 1ll * a.x * b.y - 1ll * b.x * a.y;
}
ll dot(const point &a, const point &b) {
	return 1ll * a.x * b.x + 1ll * a.y * b.y;
}

bool dfs(int nvis, const vector<int> &v) {
	if (v.empty()) return true;
	if (v.size() > __builtin_popcount(nvis)) return false;
	for (int t = nvis; t; t &= t - 1) {
		int j = __builtin_ctz(t & -t);
		auto tmp = v;
		dead[v.back()] = true;
		tmp.pop_back();
		for (int x = 1; x <= g[j][v.back()][0]; ++x) if (!dead[g[j][v.back()][x]]) tmp.push_back(g[j][v.back()][x]);
		sort(tmp.begin(), tmp.end());
		tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
		if (dfs(nvis - (t & -t), tmp)) { dead[v.back()] = false; return true; }
		dead[v.back()] = false;
	}
	return false;
}

int main() {
	scanf("%d%d", &k, &n);
	for (int i = 0; i < k; ++i) scanf("%d%d", &p[i].x, &p[i].y);
	for (int i = 0; i < n; ++i) scanf("%d%d", &m[i].x, &m[i].y);
	for (int i = 0; i < k; ++i)
		for (int x = 0; x < n; ++x)
			for (int y = 0; y < n; ++y)
				if (y != x && !det(m[x] - p[i], m[y] - p[i]) && dot(m[y] - p[i], m[y] - m[x]) < 0) {
					g[i][x][++g[i][x][0]] = y;
					if (g[i][x][0] > k) break;
				}
	int ans = 0;
	for (int i = 0; i < n; ++i) ans += dfs((1 << k) - 1, {i});
	printf("%d\n", ans);
}