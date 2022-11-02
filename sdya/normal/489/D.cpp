#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <bitset>

using namespace std;

const int maxN = 3100;
vector < int > g[maxN];
int cnt[maxN];
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
	}
	long long res = 0;
	for (int i = 1; i <= n; ++i) {
		memset(cnt, 0, sizeof(cnt));
		for (int j = 0; j < g[i].size(); ++j) {
			int u = g[i][j];
			for (int k = 0; k < g[u].size(); ++k) {
				if (g[u][k] != i) {
					++cnt[g[u][k]];
				}
			}
		}
		for (int j = 1; j <= n; ++j) {
			res += (long long)(cnt[j] - 1) * (long long)(cnt[j]) / 2LL;
		}
	}
	cout << res << endl;
	return 0;
}