#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <cmath>
#include <ctime>
#include <unordered_set>
#include <unordered_map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

void dfs(
	vector < vector < vector < pair < int, int > > > > &g,
	int x, int y,
	vector < pair < int, int > > &comp,
	vector < vector < bool > > &used)
{
	used[x][y] = true;
	comp.push_back(make_pair(x, y));
	for (int i = 0; i < g[x][y].size(); ++i) {
		int nx = g[x][y][i].first;
		int ny = g[x][y][i].second;
		if (!used[nx][ny]) {
			dfs(g, nx, ny, comp, used);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m;
	scanf("%d%d", &n, &m);

	vector < vector < int > > a(n, vector < int > (m, 0));
	vector < vector < int > > b(m, vector < int > (n, 0));
	vector < vector < int > > res(n, vector < int > (m, 0));
	vector < pair < int, int > > r(n, pair < int, int > (0, 0));
	vector < pair < int, int > > c(m, pair < int, int > (0, 0));

	vector < vector < vector < pair < int, int > > > > g(n, vector < vector < pair < int, int > > > (m));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
			b[j][i] = a[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		map < int, int > M;
		for (int j = 0; j < m; ++j) {
			if (M.count(a[i][j])) {
				g[i][j].push_back(make_pair(i, M[a[i][j]]));
				g[i][M[a[i][j]]].push_back(make_pair(i, j));
			}
			M[a[i][j]] = j;
		}
	}
	for (int j = 0; j < m; ++j) {
		map < int, int > M;
		for (int i = 0; i < n; ++i) {
			if (M.count(a[i][j])) {
				g[i][j].push_back(make_pair(M[a[i][j]], j));
				g[M[a[i][j]]][j].push_back(make_pair(i, j));
			}
			M[a[i][j]] = i;
		}
	}

	vector < vector < bool > > used(n, vector < bool > (m, false));
	vector < vector < pair < int, int > > > comps;
	vector < pair < int, int > > p;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!used[i][j]) {
				vector < pair < int, int > > comp;
				dfs(g, i, j, comp, used);
				p.push_back(make_pair(a[i][j], comps.size()));
				comps.push_back(comp);
			}
		}
	}

	
	sort(p.begin(), p.end());

	for (int i = 0; i < n; ++i) {
		sort(a[i].begin(), a[i].end());
	}
	for (int i = 0; i < m; ++i) {
		sort(b[i].begin(), b[i].end());
	}

	for (int t = 0; t < p.size(); ++t) {
		int index = p[t].second;

		int v = p[t].first;

		int minr = 1, minc = 1;
		for (int i = 0; i < comps[index].size(); ++i) {
			int x = comps[index][i].first;
			int y = comps[index][i].second;

			int posr = lower_bound(a[x].begin(), a[x].end(), v) - a[x].begin() + 1;
			int posc = lower_bound(b[y].begin(), b[y].end(), v) - b[y].begin() + 1;

			if (posr == r[x].first) {
				minr = max(minr, r[x].second);
			} else {
				minr = max(minr, r[x].second + 1);
			}

			if (posc == c[y].first) {
				minc = max(minc, c[y].second);
			} else {
				minc = max(minc, c[y].second + 1);
			}
		}

		for (int i = 0; i < comps[index].size(); ++i) {
			int x = comps[index][i].first;
			int y = comps[index][i].second;

			int posr = lower_bound(a[x].begin(), a[x].end(), v) - a[x].begin() + 1;
			int posc = lower_bound(b[y].begin(), b[y].end(), v) - b[y].begin() + 1;

			res[x][y] = max(minr, minc);
			r[x] = make_pair(posr, res[x][y]);
			c[y] = make_pair(posc, res[x][y]);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}


	return 0;
}