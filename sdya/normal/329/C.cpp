#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
vector < int > g[maxN];
int n, m;

int cnt[maxN];

int getRand() {
	int res = rand() * rand() + rand();
	if (res < 0) {
		res = -res;
	}
	return res;
}

bool neighbours(int u, int v) {
	for (int i = 0; i < g[u].size(); ++i) {
		if (g[u][i] == v) {
			return true;
		}
	}
	return u == v;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int tests = 0;
	while (true) {
		++tests;
		if (tests % 10 == 0) {
			if ((double)(clock()) / (double)(CLOCKS_PER_SEC) > 1.3) {
				break;
			}
		}
		vector < int > a(n);
		for (int i = 0; i < n; ++i) {
			a[i] = i;
			cnt[i] = 0;
		}

		int v = getRand() % n;
		vector < bool > used(n, false);
		used[v] = true;
		swap(a[v], a.back());
		a.pop_back();
		vector < pair < int, int > > edges;
		set < pair < int, int > > visited;

		vector < int > f;
		f.push_back(v);
		while (edges.size() != m) {
			if (a.size() == 0) {
				break;
			}

			int iters = 10;
			while (iters) {
				--iters;
				int v = getRand() % a.size();
				if (neighbours(f.back(), a[v])) {
					continue;
				}
				if (visited.count(make_pair(f.back(), a[v])) || visited.count(make_pair(a[v], f.back()))) {
					continue;
				}
				++cnt[f.back()];
				edges.push_back(make_pair(f.back(), a[v]));
				visited.insert(make_pair(f.back(), a[v]));
				used[a[v]] = true;
				f.push_back(a[v]);
				swap(a[v], a[a.size() - 1]);
				a.pop_back();
				break;
			}
			if (iters == 0) {
				break;
			}
		}
		if (m == n) {
			if (f.size() > 0 && !neighbours(f[0], f[f.size() - 1])) {
				if (visited.count(make_pair(f[0], f[f.size() - 1])) == 0 && visited.count(make_pair(f[f.size() - 1], f[0])) == 0) {
					edges.push_back(make_pair(f[0], f[f.size() - 1]));
				}
			}
		}
		if (edges.size() == m) {
			for (int i = 0; i < m; ++i) {
				printf("%d %d\n", edges[i].first + 1, edges[i].second + 1);
			}
			return 0;
		}
	}

	printf("-1\n");
	return 0;
}