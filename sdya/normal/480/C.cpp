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
#include <list>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 5100;
const int P = 1000000007;
int n, a, b, k;

int d[2][maxN], s[maxN];

void set0(int u) {
	memset(d[u], 0, sizeof(d[u]));
}

inline void add(int &x, int value) {
	x += value;
	if (x >= P) {
		x -= P;
	}
}

inline void sub(int &x, int value) {
	x -= value;
	if (x < 0) {
		x += P;
	}
}

void calcS(int u) {
	for (int i = 0; i < maxN; ++i) {
		s[i] = d[u][i];
		if (i > 0) {
			add(s[i], s[i - 1]);
		}
	}
}

int getS(int l, int r) {
	if (l > r) {
		return 0;
	}
	int res = s[r] - (l == 0 ? 0 : s[l - 1]);
	if (res < 0) {
		res += P;
	}
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> a >> b >> k;

	int u = 0, v = 1;
	set0(u);

	d[u][a] = 1;
	for (int steps = 0; steps < k; ++steps, swap(u, v)) {
		calcS(u);
		set0(v);

		for (int j = 1; j <= n; ++j) {
			int l = 1, r = n;
			if (j == b) {
				continue;
			}
			if (j < b) {
				r = (b + j - 1) / 2;
			} else {
				l = (b + j) / 2 + 1;
			}
			d[v][j] = getS(l, r);
			if (l <= j && j <= r) {
				sub(d[v][j], d[u][j]);
			}
		}
	}

	int res = 0;
	for (int i = 1; i <= n; ++i) {
		add(res, d[u][i]);
	}
	cout << res << endl;

	return 0;
}