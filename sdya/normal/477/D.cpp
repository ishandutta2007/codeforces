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

const int maxN = 5500;
const int P = 1000000007;
const int inf = 1000000000;
char x[maxN];
int n;

const int maxD = 20;
int c[maxN], p[maxN], q[maxN], cl[maxD][maxN], classes;

void build_step(int len, int index) {
	for (int i = 0; i < n; i ++) c[i] = 0;

	for (int i = 0; i < n; i ++) q[i] = (p[i] + n - len) % n;
	for (int i = 0; i < n; i ++) c[cl[index - 1][i]] ++;
	for (int i = 1; i < classes; i ++) c[i] += c[i - 1];
	for (int i = n - 1; i >= 0; i --) p[c[cl[index - 1][q[i]]] - 1] = q[i], c[cl[index - 1][q[i]]] --;

	classes = 0;
	cl[index][p[0]] = 0;
	for (int i = 1; i < n; i ++) {
		if (cl[index - 1][p[i]] > cl[index - 1][p[i - 1]]) {
			++classes;
		} else if (cl[index - 1][(p[i] + len) % n] > cl[index - 1][(p[i - 1] + len) % n]) {
			++classes;
		}
		cl[index][p[i]] = classes;
	}
	++classes;
}

void build_suffix_array() {
	for (int i = 0; i < 256; i ++) c[i] = 0;
	for (int i = 0; i < n; i ++) c[x[i]] ++;
	for (int i = 1; i < 256; i ++) c[i] += c[i - 1];
	for (int i = n - 1; i >= 0; i --) p[c[x[i]] - 1] = i, c[x[i]] --;

	classes = 0;
	cl[0][p[0]] = 0;
	for (int i = 1; i < n; i ++) {
		if (x[p[i]] > x[p[i - 1]]) classes ++;
		cl[0][p[i]] = classes;
	}
	classes ++;

	int len = 1;
	int index = 1;
	while (true) {
		build_step(len, index);
		++index;
		len *= 2;
		if (len >= n) {
			break;
		}
	}
}

int pk[maxN];

bool isLessThanOrEqual(int i, int j, int l) {
	int k = pk[l];
	pair<int,int> a = make_pair (cl[k][i], cl[k][i+l-(1<<k)]);
	pair<int,int> b = make_pair (cl[k][j], cl[k][j+l-(1<<k)]);
	return a <= b;
}

int d[maxN][maxN], s[maxN][maxN];

inline void add(int &x, int value) {
	x += value;
	if (x >= P) {
		x -= P;
	}
}

void calculateS(int i) {
	for (int j = 0; j < maxN; ++j) {
		s[i][j] = d[i][j];
		if (j > 0) {
			add(s[i][j], s[i][j - 1]);
		}
	}
}

void calculateM(int i) {
	for (int j = 0; j < maxN; ++j) {
		s[i][j] = d[i][j];
		if (j > 0) {
			s[i][j] = min(s[i][j], s[i][j - 1]);
		}
	}
}

struct Number {
	int a[maxN];
	Number() {
		for (int i = 0; i < maxN; ++i) {
			a[i] = 0;
		}
	}
	int len() const {
		for (int i = maxN - 1; i >= 0; --i) {
			if (a[i]) {
				return i;
			}
		}
		return 0;
	}

	void add(int value) {
		a[0] += value;
		for (int i = 0; i + 1 < maxN; ++i) {
			if (a[i] >= 2) {
				a[i + 1] += a[i] / 2;
				a[i] %= 2;
			}
		}
	}

	bool isLessThanOrEqual(const Number &other) const {
		int l1 = len();
		int l2 = other.len();
		if (l1 < l2) {
			return true;
		}
		if (l1 > l2) {
			return false;
		}
		for (int i = l1; i >= 0; --i) {
			if (a[i] < other.a[i]) {
				return true;
			}
			if (a[i] > other.a[i]) {
				return false;
			}
		}
		return true;
	}

	int toInt() {
		int l = len();
		int res = 0;
		for (int i = l; i >= 0; --i) {
			res = res + res + a[i];
			res %= P;
		}
		return res;
	}
};

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	for (int i = 1; i < maxN; ++i) {
		pk[i] = 0;
		while ((1 << (pk[i] + 1)) <= i) {
			++pk[i];
		}
	}

	scanf("%s", &x);
	n = strlen(x);

	build_suffix_array();

	d[0][0] = 1;
	calculateS(0);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			if (x[i - j] == '0') {
				continue;
			}

			if (i - j < j) {
				add(d[i][j], s[i - j][j]);
				continue;
			}
			if (isLessThanOrEqual(i - 2 * j, i - j, j)) {
				add(d[i][j], s[i - j][j]);
			} else {
				add(d[i][j], s[i - j][j - 1]);
			}
		}
		calculateS(i);
	}

	int res = 0;
	for (int i = 1; i <= n; ++i) {
		add(res, d[n][i]);
	}

	printf("%d\n", res % P);

	memset(s, 0, sizeof(s));
	for (int i = 0; i < maxN; ++i) {
		for (int j = 0; j < maxN; ++j) {
			d[i][j] = inf;
		}
	}
	d[0][0] = 0;
	calculateM(0);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			if (x[i - j] == '0') {
				continue;
			}

			if (i - j < j) {
				d[i][j] = min(d[i][j], s[i - j][j] + 1);
				continue;
			}
			if (isLessThanOrEqual(i - 2 * j, i - j, j)) {
				d[i][j] = min(d[i][j], s[i - j][j] + 1);
			} else {
				d[i][j] = min(d[i][j], s[i - j][j - 1] + 1);
			}
		}
		calculateM(i);
	}

	Number r;
	r.a[maxN - 1] = 1;

	for (int i = 0; i <= n; ++i) {
		if (d[n][i] > n) {
			continue;
		}

		Number current;
		int k = 0;
		for (int j = n - 1; j >= n - i; --j) {
			current.a[k++] = x[j] - '0';
		}
		current.add(d[n][i]);

		if (current.isLessThanOrEqual(r)) {
			r = current;
		}
	}

	printf("%d\n", r.toInt() % P);


	return 0;
}