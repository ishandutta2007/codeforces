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
#include <unordered_map>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1100000;
const long long P = 1000003LL;
vector < int > g[maxN];
vector < long long > h[maxN];
long long p[maxN];
int n, m;

long long getHash(int i, int l, int r) {
	return h[i][r] - (l == 0 ? 0 : (h[i][l - 1] * p[r - l + 1]));
}

unordered_map < long long, int > M;

long long getHash(int i, int k) {
	long long A = (k == 0 ? 0 : getHash(i, 0, k - 1));
	long long B = (k + 1 == g[i].size() ? 0 : getHash(i, k + 1, g[i].size() - 1));
	int length = (int)(g[i].size()) - k - 1;
	return A * p[length] + B;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	p[0] = 1LL;
	for (int i = 1; i < maxN; ++i) {
		p[i] = p[i - 1] * P;
	}

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i) {
		sort(g[i].begin(), g[i].end());
		h[i].resize(g[i].size());
		if (g[i].size() == 0) {
			++M[0];
		} else {
			h[i][0] = g[i][0];
			for (int j = 1; j < g[i].size(); ++j) {
				h[i][j] = h[i][j - 1] * P + (long long)(g[i][j]);
			}
			++M[h[i][g[i].size() - 1]];
		}
	}
	long long res = 0;
	for (unordered_map < long long, int > :: iterator it = M.begin(); it != M.end(); ++it) {
		long long n = it->second;
		res += n * (n - 1) / 2LL;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < g[i].size(); ++j) {
			int v = g[i][j];
			if (i > v) {
				continue;
			}
			if (g[i].size() != g[v].size()) {
				continue;
			}

			int k = lower_bound(g[v].begin(), g[v].end(), i) - g[v].begin();
			if (getHash(i, j) == getHash(v, k)) {
				++res;
			}
		}
	}
	cout << res << endl;

	return 0;
}