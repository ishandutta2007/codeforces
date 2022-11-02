#define _CRT_SECURE_NO_WARNINGS
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
#include <unordered_map>
#include <unordered_set>
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
const long long inf = 1000000000000000000LL;
int n, m, k;
vector < pair < int, long long > > g[maxN];
vector < pair < int, long long > > h;

long long d[maxN][2];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		--u;
		--v;
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}
	set < pair < long long, int > > t;
	for (int i = 0; i < k; ++i) {
		int v, w;
		scanf("%d%d", &v, &w);
		--v;
		h.push_back(make_pair(v, w));
	}

	for (int i = 0; i < n; ++i) {
		d[i][0] = d[i][1] = inf;
	}

	d[0][0] = 0;

	set < pair < long long, pair < int, int > > > S;
	S.insert(make_pair(d[0][0], make_pair(0, 0)));
	for (int i = 0; i < h.size(); ++i) {
		int u = h[i].first;
		long long w = h[i].second;
		if (w < d[u][1]) {
			S.erase(make_pair(d[u][1], make_pair(u, 1)));
			d[u][1] = w;
			S.insert(make_pair(d[u][1], make_pair(u, 1)));
		}
	}
	int res = k;
	while (!S.empty()) {
		pair < long long, pair < int, int > > p = *S.begin();
		S.erase(S.begin());
		int v = p.second.first;
		long long D = p.first;
		if (p.second.second == 1) {
			if (D >= d[v][0]) {
				continue;
			}
			--res;
		}

		for (int i = 0; i < g[v].size(); ++i) {
			int u = g[v][i].first;
			long long w = g[v][i].second;
			if (D + w < d[u][0]) {
				S.erase(make_pair(d[u][0], make_pair(u, 0)));
				d[u][0] = D + w;
				S.insert(make_pair(d[u][0], make_pair(u, 0)));
			}
		}
	}

	cout << res << endl;


	return 0;
}