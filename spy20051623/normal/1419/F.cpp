#include <bits/stdc++.h>

using namespace std;

int x[1005], y[1005], fa[1005], n;
map<int, vector<int>> mx, my;

int find(int X) { return X == fa[X] ? X : fa[X] = find(fa[X]); }

bool check(int t) {
	for (int i = 0; i < n; ++i) fa[i] = i;
	for (auto &i: mx) {
		auto &v = i.second;
		for (int j = 0; j < (int) v.size() - 1; ++j) {
			if (y[v[j + 1]] - y[v[j]] <= t) fa[find(v[j + 1])] = find(v[j]);
		}
	}
	for (auto &i: my) {
		auto &v = i.second;
		for (int j = 0; j < (int) v.size() - 1; ++j) {
			if (x[v[j + 1]] - x[v[j]] <= t) fa[find(v[j + 1])] = find(v[j]);
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (fa[i] == i) ++cnt;
	}
	if (cnt == 1) return true;
	if (cnt >= 5) return false;
	if (cnt == 2) {
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (find(i) != find(j) && abs(x[i] - x[j]) <= t && abs(y[i] - y[j]) <= t) return true;
			}
		}
		for (auto &i: mx) {
			auto &v = i.second;
			for (int j = 0; j < (int) v.size() - 1; ++j) {
				if (find(v[j]) != find(v[j + 1]) && y[v[j + 1]] - y[v[j]] - t <= t) return true;
			}
		}
		for (auto &i: my) {
			auto &v = i.second;
			for (int j = 0; j < (int) v.size() - 1; ++j) {
				if (find(v[j]) != find(v[j + 1]) && x[v[j + 1]] - x[v[j]] - t <= t) return true;
			}
		}
		return false;
	}
	if (cnt == 3) {
		for (auto &i: mx) {
			auto &v = i.second;
			for (int j = 0; j < (int) v.size() - 1; ++j) {
				if (find(v[j]) == find(v[j + 1]) || y[v[j + 1]] - y[v[j]] - t > t) continue;
				for (int k = 0; k < n; ++k) {
					if (find(k) == find(v[j]) || find(k) == find(v[j + 1])) continue;
					if (abs(y[k] - y[v[j]]) <= t && abs(y[k] - y[v[j + 1]]) <= t && abs(x[k] - x[v[j]]) <= t)
						return true;
				}
			}
		}
		for (auto &i: my) {
			auto &v = i.second;
			for (int j = 0; j < (int) v.size() - 1; ++j) {
				if (find(v[j]) == find(v[j + 1]) || x[v[j + 1]] - x[v[j]] - t > t) continue;
				for (int k = 0; k < n; ++k) {
					if (find(k) == find(v[j]) || find(k) == find(v[j + 1])) continue;
					if (abs(x[k] - x[v[j]]) <= t && abs(x[k] - x[v[j + 1]]) <= t && abs(y[k] - y[v[j]]) <= t)
						return true;
				}
			}
		}
		return false;
	}
	if (cnt == 4) {
		for (auto &i: mx) {
			auto &v = i.second;
			for (auto &j: my) {
				auto &u = j.second;
				for (int k = 0; k < (int) v.size() - 1; ++k) {
					if (find(v[k]) == find(v[k + 1])) continue;
					for (int l = 0; l < (int) u.size() - 1; ++l) {
						if (find(u[l]) == find(u[l + 1]) || find(v[k]) == find(u[l]) || find(v[k]) == find(u[l + 1]) ||
							find(v[k + 1]) == find(u[l]) || find(v[k + 1]) == find(u[l + 1]))
							continue;
						if (abs(y[v[k]] - y[u[l]]) <= t && abs(y[v[k + 1]] - y[u[l]]) <= t &&
							abs(x[v[k]] - x[u[l]]) <= t && abs(x[v[k]] - x[u[l + 1]]) <= t)
							return true;
					}
				}
			}
		}
		return false;
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		mx[x[i]].push_back(i);
		my[y[i]].push_back(i);
	}
	for (auto &i: mx) {
		auto &v = i.second;
		sort(v.begin(), v.end(), [&](int a, int b) { return y[a] < y[b]; });
	}
	for (auto &i: my) {
		auto &v = i.second;
		sort(v.begin(), v.end(), [&](int a, int b) { return x[a] < x[b]; });
	}
	int l = 1, r = 2e9, ans = -1;
	while (l <= r) {
		int m = ((long long) l + r) >> 1;
		if (check(m)) ans = m, r = m - 1;
		else l = m + 1;
	}
	cout << ans << '\n';
	return 0;
}