#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 11000;
const int maxM = 21;
int n, m, k, l;
int b[maxN];
int h[maxN], pos[maxN];
int a[maxN];
vector < int > g[maxN];
int dp[maxM][maxM];
int d[maxN];

int s[1 << maxM];

void calc(int v) {
	for (int i = 0; i <= n; ++i) {
		d[i] = 1000000;
	}
	d[v] = 0;
	queue < int > q;
	q.push(v);
	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int i = 0; i < g[v].size(); ++i) {
			if (d[g[v][i]] > d[v] + 1) {
				d[g[v][i]] = d[v] + 1;
				q.push(g[v][i]);
			}
		}
	}

	v = h[v];
	for (int i = 0; i <= n; ++i) {
		if (h[i] != -1) {
			dp[v][h[i]] = d[i];
		}
	}
}

int solve(int mask) {
	if (s[mask] != -1) {
		return s[mask];
	}
	if (mask == 0) {
		return s[mask] = 0;
	}
	int index = -1;
	for (int i = 0; i < m; ++i) {
		if (mask & (1 << i)) {
			index = i;
			break;
		}
	}
	s[mask] = 1000000;
	for (int i = index + 1; i < m; ++i) {
		if (mask & (1 << i)) {
			s[mask] = min(s[mask], solve(mask ^ (1 << index) ^ (1 << i)) + dp[i][index]);
		}
	}
	return s[mask];
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &n, &k, &l);
	for (int i = 0; i < k; ++i) {
		int p;
		scanf("%d", &p);
		b[p - 1] ^= 1;
		b[p] ^= 1;
	}
	for (int i = 0; i <= n; ++i) {
		h[i] = -1;
	}
	for (int i = 0; i <= n; ++i) {
		if (b[i] != 0) {
			pos[m] = i;
			h[i] = m++;
		}
	}
	for (int i = 0; i < l; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j < l; ++j) {
			if (i + a[j] <= n) {
				g[i].push_back(i + a[j]);
				g[i + a[j]].push_back(i);
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			dp[i][j] = 1000000;
		}
	}

	for (int i = 0; i < m; ++i) {
		calc(pos[i]);
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = 0; k < m; ++k) {
				dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
			}
		}
	}

	memset(s, -1, sizeof(s));
	int res = solve((1 << m) - 1);
	if (res > 100000) {
		res = -1;
	}
	printf("%d\n", res);
	
	return 0;
}