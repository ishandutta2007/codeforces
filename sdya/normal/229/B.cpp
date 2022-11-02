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
#include <stack>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
const long long inf = 1000000000000000000LL;
vector < int > t[maxN];
vector < pair < int, int > > g[maxN];
long long d[maxN];
int n, m;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}

	for (int i = 1; i <= n; ++i) {
		int k;
		scanf("%d", &k);
		t[i].resize(k);
		for (int j = 0; j < k; ++j) {
			scanf("%d", &t[i][j]);
		}
	}

	set < pair < long long, int > > S;
	for (int i = 1; i <= n; ++i) {
		d[i] = inf;
	}
	d[1] = 0;
	S.insert(make_pair(d[1], 1));
	while (!S.empty()) {
		int v = S.begin()->second;
		S.erase(S.begin());
		long long score = d[v];
		int index = lower_bound(t[v].begin(), t[v].end(), score) - t[v].begin();
		if (index == t[v].size() || (long long)(t[v][index]) > score) {
		} else {
			int left_bound = index, right_bound = t[v].size() - 1;
			while (right_bound - left_bound > 1) {
				int middle = (left_bound + right_bound) / 2;
				if ((long long)(t[v][middle]) == score + (middle - index)) {
					left_bound = middle;
				} else {
					right_bound = middle;
				}
			}
			int bound = left_bound;
			if ((long long)(t[v][right_bound]) == score + right_bound - index) {
				bound = right_bound;
			}
			score = t[v][bound] + 1;
		}

		for (int i = 0; i < g[v].size(); ++i) {
			int to = g[v][i].first;
			long long len = score + (long long)(g[v][i].second);
			if (d[to] > len) {
				S.erase(make_pair(d[to], to));
				d[to] = len;
				S.insert(make_pair(d[to], to));
			}
		}
	}


	if (d[n] == inf) {
		cout << -1 << endl;
	} else {
		cout << d[n] << endl;
	}

	return 0;
}