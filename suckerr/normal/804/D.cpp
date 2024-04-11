#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

int n, m, q;
int father[N], num[N], vnum[N];
vector<int> adj[N];

int find(int u) {
	return u == father[u] ? u : father[u] = find(father[u]);
}

bool is_tree(int u) {
	return vnum[u] == num[u] + 1;
}

int dep[N], dia[N], far[N];
vector<int> block[N], cnt[N];
vector<double> ss[N];

void dfs(int u, int from) {
	for (auto v : adj[u]) {
		if (v != from) {
			dep[v] = dep[u] + 1;
			dfs(v, u);
		}
	}
}

int farest(int u, const vector<int> &bak) {
	dep[u] = 0;
	dfs(u, 0);
	int mv = -1, who = -1;
	for (auto v : bak) {
		if (dep[v] > mv) {
			mv = dep[v];
			who = v;
		}
	}
	return who;
}

int main() {
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n; i++) father[i] = i, vnum[i] = 1;
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
		u = find(u), v = find(v);
		if (u != v) {
			num[u] += num[v]; num[v] = 0;
			vnum[u] += vnum[v]; vnum[v] = 0;
			father[v] = u;
		}
		num[u]++;
	}
	for (int i = 1; i <= n; i++) {
		block[find(i)].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		if (father[i] == i && is_tree(i)) {
			int u = farest(i, block[i]);
			int v = farest(u, block[i]);
			for (auto w : block[i]) {
				far[w] = max(far[w], dep[w]);
			}
			farest(v, block[i]);
			for (auto w : block[i]) {
				far[w] = max(far[w], dep[w]);
			}
			dia[i] = dep[u];
			cnt[i].resize(block[i].size() + 1);
			ss[i].resize(block[i].size() + 1);
			for (auto w : block[i]) {
				cnt[i][far[w]] ++;
				ss[i][far[w]] += far[w];
			}
			for (int j = cnt[i].size() - 2; j >= 0; j--) {
				cnt[i][j] += cnt[i][j + 1];
				ss[i][j] += ss[i][j + 1];
			}
		}
	}
	map<pair<int, int>, double> ans;
	for (int i = 0; i < q; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u = find(u), v = find(v);
		if (u == v || !is_tree(u) || !is_tree(v)) {
			puts("-1");
			continue;
		}
		if (vnum[u] > vnum[v] || (vnum[u] == vnum[v] && u > v)) swap(u, v);
		if (ans.count(make_pair(u, v))) {
			printf("%.12f\n", ans[{u, v}]);
			continue;
		}
		double& ret = ans[{u, v}];
		int d = max(dia[u], dia[v]);
		ret = 1. * d * block[u].size() * block[v].size();
		for (auto w : block[u]) {
			int least = max(0, d - far[w] - 1);
			int num = 0; double sum = 0;
			if (least < cnt[v].size()) {
				num = cnt[v][least];
				sum = ss[v][least];
			}
			ret -= 1. * num * d;
			ret += sum + 1. * num * (far[w] + 1);
		}
		ret /= 1. * block[u].size() * block[v].size();
		printf("%.12f\n", ret);
	}
	return 0;
}