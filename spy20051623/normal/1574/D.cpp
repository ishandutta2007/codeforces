#include <bits/stdc++.h>

using namespace std;

vector<int> g[15];
set<vector<int>> b;
int n;
long long s;
vector<int> res;

bool dfs(int x, long long num, long long mx, vector<int> cur) {
	if (x == n) {
		if (b.find(cur) == b.end()) {
			res = cur;
			return true;
		} else return false;
	}
	for (int i = 1; i <= g[x].size(); ++i) {
		if (mx - g[x].back() + g[x][g[x].size() - i] >= num) {
			cur[x] = i;
			if (dfs(x + 1, num, mx - g[x].back() + g[x][g[x].size() - i], cur)) return true;
		} else return false;
	}
	return false;
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int k;
		scanf("%d", &k);
		while (k--) {
			int p;
			scanf("%d", &p);
			g[i].push_back(p);
		}
		s += g[i].back();
	}
	int m;
	scanf("%d", &m);
	while (m--) {
		vector<int> v;
		for (int i = 0; i < n; ++i) {
			int p;
			scanf("%d", &p);
			v.push_back(g[i].size() - p + 1);
		}
		b.insert(v);
	}
	vector<int> ans;
	long long l = 0, r = s;
	while (l <= r) {
		long long mid = (l + r) >> 1;
		if (dfs(0, mid, s, vector<int>(n))) l = mid + 1;
		else r = mid - 1;
	}
	for (int i = 0; i < n; ++i) {
		printf("%d ", g[i].size() - res[i] + 1);
	}
	return 0;
}