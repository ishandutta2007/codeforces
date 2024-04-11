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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1100;
int n, m;
int v[maxN];
vector < int > g[maxN];

bool used[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	vector < pair < int, int > > order;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &v[i]);
		order.push_back(make_pair(-v[i], i));
	}
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	sort(order.begin(), order.end());

	long long res = 0;
	for (int i = 0; i < n; ++i) {
		int u = order[i].second;
		for (int j = 0; j < g[u].size(); ++j) {
			if (!used[g[u][j]]) {
				res += v[g[u][j]];
			}
		}
		used[u] = true;
	}
	cout << res << endl;


	return 0;
}