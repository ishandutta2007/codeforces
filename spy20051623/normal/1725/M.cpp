#include <bits/stdc++.h>

using i64 = long long;
using pii = std::pair<i64, i64>;
const int N = 1e5 + 5;
std::vector<pii> g1[N], g2[N];
i64 dis1[N], dis2[N];
int n, m;

void bfs1() {
	memset(dis1, 63, sizeof dis1);
	std::priority_queue<pii, std::vector<pii>, std::greater<>> q;
	q.emplace(0, 1);
	while (!q.empty()) {
		pii p = q.top();
		q.pop();
		i64 x = p.first, y = p.second;
		if (x >= dis1[y]) continue;
		dis1[y] = x;
		for (pii i: g1[y]) {
			q.emplace(x + i.second, i.first);
		}
	}
}

void bfs2() {
	memset(dis2, 63, sizeof dis2);
	std::priority_queue<pii, std::vector<pii>, std::greater<>> q;
	for (int i = 1; i <= n; ++i) {
		q.emplace(dis1[i], i);
	}
	while (!q.empty()) {
		pii p = q.top();
		q.pop();
		i64 x = p.first, y = p.second;
		if (x >= dis2[y]) continue;
		dis2[y] = x;
		for (pii i: g2[y]) {
			q.emplace(x + i.second, i.first);
		}
	}
}

void solve() {
	std::cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y, z;
		std::cin >> x >> y >> z;
		g1[x].emplace_back(y, z);
		g2[y].emplace_back(x, z);
	}
	bfs1();
	bfs2();
	for (int i = 2; i <= n; ++i) {
		if (dis2[i] > 1e18) std::cout << "-1 ";
		else std::cout << dis2[i] << ' ';
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#else
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
#endif
	int t = 1;
//	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}