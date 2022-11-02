#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110;
int n, m, k;
int a[maxN][maxN], b[maxN][maxN], c[maxN][maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i) {
		string name;
		cin >> name;
		for (int j = 1; j <= m; ++j)
			scanf("%d%d%d", &a[i][j], &b[i][j], &c[i][j]);
	}
	int best = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (i != j) {
				vector < pair < int, int > > w;
				for (int l = 1; l <= m; ++l)
					w.push_back(make_pair(b[j][l] - a[i][l], c[i][l]));
				sort(w.begin(), w.end());
				reverse(w.begin(), w.end());
				int have = k;
				int res = 0;
				for (int l = 0; l < w.size(); ++l) {
					if (w[l].first < 0) continue;
					int need = min(w[l].second, have);
					res += need * w[l].first;
					have -= need;
				}
				best = max(best, res);
			}
	printf("%d\n", best);
	return 0;
}