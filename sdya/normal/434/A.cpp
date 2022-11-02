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

long long get(int value) {
	return value > 0 ? value : -value;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m;
	scanf("%d%d", &n, &m);
	vector < int > a(m);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &a[i]);
		--a[i];
	}

	vector < vector < int > > c(n);
	for (int i = 0; i < m; ++i) {
		if (i > 0 && a[i - 1] != a[i]) {
			c[a[i]].push_back(a[i - 1]);
		}
		if (i + 1 < m && a[i + 1] != a[i]) {
			c[a[i]].push_back(a[i + 1]);
		}
	}
	for (int i = 0; i < n; ++i) {
		sort(c[i].begin(), c[i].end());
	}
	long long res = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < c[i].size(); ++j) {
			res += get(i - c[i][j]);
		}
	}

	res /= 2;

	long long total = res;
	for (int i = 0; i < n; ++i) {
		if (c[i].size() == 0) {
			continue;
		}
		int m = c[i].size() / 2;

		long long old = 0;
		for (int j = 0; j < c[i].size(); ++j) {
			old += get(i - c[i][j]);
		} 

		for (int j = max(0, m - 1); j <= min((int)c[i].size() - 1, m + 1); ++j) {
			long long current = 0;
			for (int k = 0; k < c[i].size(); ++k) {
				current += get(c[i][j] - c[i][k]);
			}
			res = min(res, total - old + current);
		}
	}
	cout << res << endl;
	return 0;
}