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

const int maxN = 5100;
int n, m, a[maxN], b[maxN];

unordered_set < int > S;

int gcd(int a, int b) {
	if (a == 0 || b == 0) {
		return a + b;
	}
	if (a > b) {
		return gcd(a % b, b);
	}
	return gcd(b % a, a);
}

unordered_map < int, int > M;

int getScore(int n) {
	if (M.count(n)) {
		return M[n];
	}
	int m = n;
	int res = 0;
	for (int i = 2; i * i <= n; ++i) {
		int q = 0;
		while (m % i == 0) {
			++q;
			m /= i;
		}
		if (q == 0) {
			continue;
		}
		if (S.count(i)) {
			res -= q;
		} else {
			res += q;
		}
	}
	if (m != 1) {
		if (S.count(m)) {
			res -= 1;
		} else {
			res += 1;
		}
	}
	return M[n] = res;
}

unordered_map < int, int > d[maxN];
int g[maxN];

void update(int i, int j, int value) {
	if (d[i].count(j)) {
		d[i][j] = max(d[i][j], value);
	} else {
		d[i][j] = value;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", &b[i]);
		S.insert(b[i]);
	}
	g[0] = a[0];
	for (int i = 1; i < n; ++i) {
		g[i] = gcd(a[i], g[i - 1]);
	}

	reverse(a, a + n);
	reverse(g, g + n);
	d[0][1] = 0;
	for (int i = 0; i < n; ++i) {
		for (unordered_map < int, int > ::iterator it = d[i].begin(); it != d[i].end(); ++it) {
			update(i + 1, it->first, it->second + getScore(a[i] / it->first));
			update(i + 1, g[i], it->second + getScore(a[i] / g[i]));
		}
	}
	int res = -1000000000;
	for (unordered_map < int, int > ::iterator it = d[n].begin(); it != d[n].end(); ++it) {
		res = max(res, it->second);
	}
	printf("%d\n", res);

	return 0;
}