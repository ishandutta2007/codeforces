#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int inf = 1000000000;
const int maxN = 600;
int d[maxN][maxN], a[maxN][maxN];
int n, m;

int getScore(int u, int v, int bound) {
	int best = 0;
	for (int i = 1; i <= n; ++i) {
		best = max(best, min(d[i][u] + bound, d[i][v] + a[u][v] - bound));
	}
	return best;
}

int getDist(set < pair < int, int > > &S) {
	if (S.empty()) {
		return - inf;
	}
	return S.rbegin()->first;
}

int calculate(int u, int v, int &edge) {
	int length = a[u][v];
	vector < pair < int, int > > events;
	set < pair < int, int > > U, V;
	int addU = 0, addV = length;
	for (int i = 1; i <= n; ++i) {
		if (d[i][u] < d[i][v] + length) {
			if (d[i][v] - d[i][u] <= length && d[i][v] - d[i][u] >= - length) {
				events.push_back(make_pair((d[i][v] - d[i][u] + length) / 2, i));
			}
			U.insert(make_pair(d[i][u], i));
		} else {
			V.insert(make_pair(d[i][v], i));
		}
	}

	events.push_back(make_pair(0, -1));
	events.push_back(make_pair(length, -1));
	events.push_back(make_pair(length, -1));
	sort(events.begin(), events.end());

	int res = max(getDist(U) + addU, getDist(V) + addV);
	for (int i = 1; i < events.size(); ++i) {
		int valueU = getDist(U) + addU;
		int valueV = getDist(V) + addV;

		int dist = events[i].first - events[i - 1].first;

		if (valueV - valueU >= 0  && valueV - valueU <= 2 * dist) {
			if (valueU + (valueV - valueU) / 2 < res) {
				edge = addU + (valueV - valueU) / 2;
				res = min(res, valueU + (valueV - valueU) / 2);
			}
		} else {
			if (max(valueU, valueV) < res) {
				edge = max(valueU, valueV);
				res = min(res, max(valueU, valueV));
			}
		}

		addU += dist;
		addV -= dist;
		if (events[i].second != -1) {
			U.erase(make_pair(d[u][events[i].second], events[i].second));
			V.insert(make_pair(d[v][events[i].second], events[i].second));
		}
	}

	return res;
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n + 1; ++i) {
		for (int j = 1; j <= n + 1; ++j) {
			d[i][j] = inf;
			a[i][j] = inf;
		}
	}
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		w += w;
		d[u][v] = min(d[u][v], w);
		d[v][u] = min(d[v][u], w);

		a[u][v] = d[u][v];
		a[v][u] = d[v][u];
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		d[i][i] = 0;
	}

	int res = inf, u = -1, v = -1, bound = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (a[i][j] != inf) {
				int shift = 0;
				int current = calculate(i, j, shift);
				if (current < res) {
					res = current;
					u = i;
					v = j;
					bound = shift;
				}
			}
		}
	}

	printf("%.10lf\n", (double)(res) / 2.0);

	/*a[u][n + 1] = a[n + 1][u] = bound;
	a[v][n + 1] = a[n + 1][v] = a[u][v] - bound;

	int len = a[u][v];
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			int mode_i = (d[u][i] + bound < d[v][i] + len - bound) ? u : v;
			int mode_j = (d[u][j] + bound < d[v][j] + len - bound) ? u : v;
			int di = min(d[u][i] + bound, d[v][i] + len - bound);
			int dj = min(d[u][j] + bound, d[v][j] + len - bound);
			int old = a[i][j];
			a[i][j] = a[j][i] = inf;
			if (mode_i == mode_j) {
				if (di + old == dj || dj + old == di) {
					a[i][j] = a[j][i] = old;
				}
			}
		}
	}

	for (int i = 1; i <= n + 1; ++i) {
		for (int j = 1; j <= n + 1; ++j) {
			for (int k = 1; k <= n + 1; ++k) {
				a[j][k] = min(a[j][k], a[j][i] + a[i][k]);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n + 1; ++i) {
		for (int j = i + 1; j <= n + 1; ++j) {
			ans = max(ans, a[i][j]);
		}
	}

	printf("%d\n", ans / 2);*/
}

int main() {
	//freopen("hunt.in", "r", stdin);
	//freopen("abpoems.out", "w", stdout);
	int tests;
	//scanf("%d\n", &tests);
	tests = 1;
	for (int i = 1; i <= tests; ++i) {
		solve();
	}
	return 0;
}