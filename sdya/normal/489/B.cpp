#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

const int maxN = 210;
int c[maxN][maxN], f[maxN][maxN];
bool used[maxN];

bool dfs(int s, int t, int C) {
	if (used[s]) {
		return false;
	}
	used[s] = true;
	if (s == t) {
		return true;
	}
	for (int i = 0; i < maxN; ++i) {
		if (c[s][i] - f[s][i] >= C && dfs(i, t, C)) {
			f[s][i] += C;
			f[i][s] -= C;
			return true;
		}
	}
	return false;
}

int flow(int s, int t) {
	int res = 0;
	memset(used, 0, sizeof(used));
	while (dfs(s, t, 1)) {
		++res;
		memset(used, 0, sizeof(used));
	}
	return res;
}

int main() {
	int n;
	int m;
	vector < int > a;
	vector < int > b;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cin >> m;
	b.resize(m);
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	int s = n + m;
	int t = n + m + 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (abs(a[i] - b[j]) <= 1) {
				++c[i][n + j];
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		c[s][i] = 1;
	}
	for (int j = 0; j < m; ++j) {
		c[n + j][t] = 1;
	}
	cout << flow(s, t) << endl;
	return 0;
}