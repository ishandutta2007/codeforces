#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <bitset>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 11;
const int maxK = 1100;
int n, m, k, w;

char s[maxK][maxN][maxN];
int d[maxK][maxK];
int parent[maxK], used[maxK];
int dist[maxK];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d%d\n", &n, &m, &k, &w);
	for (int i = 1; i <= k; ++i) {
		for (int j = 0; j < n; ++j) {
			gets(s[i][j]);
		}
	}

	for (int i = 1; i <= k; ++i) {
		for (int j = i + 1; j <= k; ++j) {
			d[i][j] = 0;
			for (int x = 0; x < n; ++x) {
				for (int y = 0; y < m; ++y) {
					if (s[i][x][y] != s[j][x][y]) {
						++d[i][j];
					}
				}
			}
			d[i][j] *= w;
			d[j][i] = d[i][j];
		}
		d[0][i] = d[i][0] = n * m;
	}

	for (int i = 0; i <= k; ++i) {
		dist[i] = d[0][i];
		parent[i] = 0;
	}

	used[0] = true;

	int res = 0;
	vector < pair < int, int > > ans;
	for (int i = 1; i <= k; ++i) {
		int best = 1000000000;
		int index = -1;
		for (int j = 1; j <= k; ++j) {
			if (dist[j] < best && !used[j]) {
				best = dist[j];
				index = j;
			}
		}

		used[index] = true;
		ans.push_back(make_pair(index, parent[index]));
		res += best;

		for (int j = 1; j <= k; ++j) {
			if (!used[j] && d[index][j] < dist[j]) {
				dist[j] = d[index][j];
				parent[j] = index;
			}
		}
	}

	printf("%d\n", res);
	for (int i = 0; i < ans.size(); ++i) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}

	return 0;
}