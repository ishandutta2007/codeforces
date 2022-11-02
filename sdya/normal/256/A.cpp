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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 4100;
int d[maxN][maxN];
int n, a[maxN];
vector < int > g[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	vector < int > c;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		c.push_back(a[i]);
	}

	sort(c.begin(), c.end());
	c.resize(unique(c.begin(), c.end()) - c.begin());
	for (int i = 1; i <= n; ++i) {
		a[i] = lower_bound(c.begin(), c.end(), a[i]) - c.begin();
		g[a[i]].push_back(i);
	}

	int res = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			d[i][j] = max(2, d[i][j]);
			int id = upper_bound(g[a[i]].begin(), g[a[i]].end(), j) - g[a[i]].begin();
			if (id != g[a[i]].size()) {
				d[j][g[a[i]][id]] = max(d[j][g[a[i]][id]], d[i][j] + 1);
			}
			res = max(res, d[i][j]);
		}
	}

	printf("%d\n", res);


	return 0;
}