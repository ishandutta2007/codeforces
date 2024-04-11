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

const int maxN = 2100;
vector<int> g[maxN];
bool used[maxN];
int timer, tin[maxN], fup[maxN];
int n, m;

bool bridges[maxN][maxN];
 
void dfs (int v, int p = -1) {
	used[v] = true;
	tin[v] = fup[v] = timer++;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (to == p)  {
			continue;
		}
		if (used[to]) {
			fup[v] = min (fup[v], tin[to]);
		} else {
			dfs (to, v);
			fup[v] = min (fup[v], fup[to]);
			if (fup[to] > tin[v]) {
				bridges[v][to] = bridges[to][v] = true;
			}
		}
	}
}
 
void find_bridges() {
	timer = 0;
	memset(used, false, sizeof(used));
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			dfs(i);
		}
	}
}

int comp[maxN], p;
int cnt[maxN];

void dfs2(int v, int cur_comp) {
	if (used[v]) {
		return ;
	}
	used[v] = true;
	comp[v] = cur_comp;
	++cnt[cur_comp];
	for (int i = 0; i < g[v].size(); ++i) {
		if (!used[g[v][i]] && !bridges[v][g[v][i]]) {
			dfs2(g[v][i], cur_comp);
		}
	}
}

vector < int > h[maxN];
int c[maxN][maxN], d[maxN][maxN], s[maxN];
int cur[maxN][maxN];
const int inf = 1000000000;

void calc(int v, int& res, int coef = 0) {
	used[v] = true;
	res += cnt[v] * cnt[v];
	res += coef * cnt[v];

	for (int i = 0; i < h[v].size(); ++i) {
		if (!used[h[v][i]]) {
			calc(h[v][i], res, coef + cnt[v]);
		}
	}
}

/*void calc(int v) {
	used[v] = true;
	vector < int > children;
	s[v] = cnt[v];
	for (int i = 0; i < h[v].size(); ++i) {
		if (!used[h[v][i]]) {
			calc(h[v][i]);
			children.push_back(h[v][i]);
			s[v] += s[h[v][i]];
		}
	}

	{
		for (int i = 0; i <= children.size(); ++i) {
			for (int j = 0; j <= s[v]; ++j) {
				cur[i][j] = -inf;
			}
		}

		cur[0][0] = s[v];
		for (int i = 0; i < children.size(); ++i) {
			int u = children[i];
			for (int j = 0; j <= s[v]; ++j) {
				if (cur[i][j] == -inf) {
					continue;
				}
				for (int k = 0; k <= s[children[u]]; ++k) {
					// down
					if (d[u][k] != -inf) {
						cur[i + 1][j + k] = max(cur[i + 1][j + k], cur[i][j] + d[u][k] + j * k);
					}
					// up
					if (c[u][k] != -inf) {
						cur[i + 1][j] = max(cur[i + 1][j], cur[i][j] + c[u][k] + 1);
					}
				}
			}
		}
	}
}*/

int cnt_in[maxN], cnt_out[maxN];

vector < int > dir[maxN], rev[maxN];

int calcIn(int v) {
	used[v] = true;
	int res = cnt[v];
	for (int i = 0; i < dir[v].size(); ++i) {
		if (!used[dir[v][i]]) {
			res += calcIn(dir[v][i]);
		}
	}
	return res;
}

int calcOut(int v) {
	used[v] = true;
	int res = cnt[v];
	for (int i = 0; i < rev[v].size(); ++i) {
		if (!used[rev[v][i]]) {
			res += calcOut(rev[v][i]);
		}
	}
	return res;
}

void genEdges(int v, vector < pair < int, int > >& edges) {
	used[v] = true;
	for (int i = 0; i < h[v].size(); ++i) {
		if (!used[h[v][i]]) {
			edges.push_back(make_pair(v, h[v][i]));
			genEdges(h[v][i], edges);
		}
	}
}

int cleverScore[maxN];

void cleverCalc(int v) {
	used[v] = true;
	s[v] = 0;
	cleverScore[v] = 0;
	for (int i = 0; i < h[v].size(); ++i) {
		if (!used[h[v][i]]) {
			cleverCalc(h[v][i]);
			s[v] += s[h[v][i]];
			cleverScore[v] += cleverScore[h[v][i]];
		}
	}
	cleverScore[v] += cnt[v] * cnt[v];
	cleverScore[v] += cnt[v] * s[v];
	s[v] += cnt[v];
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

	find_bridges();
	memset(used, false, sizeof(used));
	p = 0;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			dfs2(i, p);
			++p;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (bridges[i][j]) {
				h[comp[i]].push_back(comp[j]);
				h[comp[j]].push_back(comp[i]);
			}
		}
	}

	memset(used, false, sizeof(used));
	for (int i = 0; i < p; ++i) {
		for (int j = 0; j <= n; ++j) {
			c[i][j] = -inf;
			d[i][j] = -inf;
		}
	}
	
	int res = 0;
	for (int i = 0; i < p; ++i) {
		int cur = 0;
		memset(used, 0, sizeof(used));
		calc(i, cur);
		res = max(res, cur);
	}

	for (int i = 0; i < p; ++i) {
		memset(used, false, sizeof(used));
		cleverCalc(i);
		int cur = cnt[i] * cnt[i];
		vector < int > a;
		for (int j = 0; j < h[i].size(); ++j) {
			cur += cleverScore[h[i][j]];
			a.push_back(s[h[i][j]]);
		}

		vector < vector < int > > dp(2, vector < int > (n + 1, 0));
		int u = 0, v = 1;
		dp[u][0] = 1;
		for (int j = 0; j < a.size(); ++j, swap(u, v)) {
			dp[v] = dp[u];
			for (int k = a[j]; k <= n; ++k) {
				if (dp[u][k - a[j]]) {
					dp[v][k] = 1;
				}
			}
		}

		for (int j = 0; j <= n; ++j) {
			if (dp[u][j]) {
				res = max(res, cur + j * (n - cnt[i] - j) + (n - cnt[i]) * cnt[i]);
			}
		}
	}

	printf("%d\n", res);
	return 0;

	while (true) {
		if ((double)(clock()) / (double)(CLOCKS_PER_SEC) > 1.75) {
			break;
		}
		vector < pair < int, int > > edges;
		memset(used, false, sizeof(used));
		vector < int > order(p);
		for (int i = 0; i < p; ++i) {
			order[i] = i;
			dir[i].clear();
			rev[i].clear();
		}
		random_shuffle(order.begin(), order.end());
		genEdges(order[0], edges);

		int score = cnt[order[0]] * cnt[order[0]];
		for (int i = 0; i < edges.size(); ++i) {
			int u = edges[i].first;
			int v = edges[i].second;

			for (int j = 0; j < p; ++j) {
				used[j] = false;
			}
			int cntIn = calcIn(u);
			for (int j = 0; j < p; ++j) {
				used[j] = false;
			}
			int cntOut = calcOut(u);

			if (cntIn > cntOut) {
				dir[v].push_back(u);
				rev[u].push_back(v);
			} else {
				dir[u].push_back(v);
				rev[v].push_back(u);
			}
			score += max(cntIn, cntOut) * cnt[v] + cnt[v] * cnt[v];
		}
		res = max(res, score);
	}
	printf("%d\n", res);

	return 0;
}