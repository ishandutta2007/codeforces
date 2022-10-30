#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <string>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 310000;
const long long inf = 1000000000000000000LL;

vector < pair < int, pair < int, int > > > g[maxN];
int n, m;
int start;

long long d[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		--u;
		--v;
		g[u].push_back(make_pair(v, make_pair(w, i + 1)));
		g[v].push_back(make_pair(u, make_pair(w, i + 1)));
	}
	scanf("%d", &start);
	--start;
	for (int i = 0; i < n; ++i) {
		if (i != start) {
			d[i] = inf;
		}
	}

	set < pair < long long, int > > S;
	S.insert(make_pair(d[start], start));

	while (!S.empty()) {
		int v = S.begin()->second;
		S.erase(S.begin());

		for (int i = 0; i < g[v].size(); ++i) {
			int u = g[v][i].first;
			long long w = g[v][i].second.first;
			if (d[u] > d[v] + w) {
				S.erase(make_pair(d[u], u));
				d[u] = d[v] + w;
				S.insert(make_pair(d[u], u));
			}
		}
	}

	long long res = 0;
	vector < int > edges;
	for (int i = 0; i < n; ++i) {
		long long len = inf;
		int index = -1;
		for (int j = 0; j < g[i].size(); ++j) {
			if (d[i] == d[g[i][j].first] + g[i][j].second.first) {
				if ((long long)(g[i][j].second.first) < len) {
					len = g[i][j].second.first;
					index = g[i][j].second.second;
				}
			}
		}
		if (len != inf) {
			res += len;
			edges.push_back(index);
		}
	}

	printf("%I64d\n", res);
	sort(edges.begin(), edges.end());
	for (int i = 0; i < edges.size(); ++i) {
		printf("%d ", edges[i]);
	}
	printf("\n");


	return 0;
}