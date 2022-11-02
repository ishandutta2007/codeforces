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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 160;
int n, m;
int a[maxN], b[maxN], d[maxN];

struct BitSet {
	long long v[3];
	BitSet() {
		v[0] = v[1] = v[2] = 0;
	}
	int at(int index) {
		if (index < 60) {
			return (bool)(v[0] & (1LL << (long long)(index)));
		}
		if (index < 120) {
			return (bool)(v[1] & (1LL << (long long)(index - 60)));
		}
		return (bool)(v[2] & (1LL << (long long)(index - 120)));
	}

	void set(int index) {
		if (index < 60) {
			v[0] |= (1LL << (long long)(index));
			return;
		}
		if (index < 120) {
			v[1] |= (1LL << (long long)(index - 60));
			return;
		}
		v[2] |= (1LL << (long long)(index - 120));
	}
};

BitSet intersect(const BitSet &a, const BitSet &b) {
	BitSet c;
	c.v[0] = (a.v[0] & b.v[0]);
	c.v[1] = (a.v[1] & b.v[1]);
	c.v[2] = (a.v[2] & b.v[2]);
	return c;
}

BitSet merge(const BitSet &a, const BitSet &b) {
	BitSet c;
	c.v[0] = (a.v[0] | b.v[0]);
	c.v[1] = (a.v[1] | b.v[1]);
	c.v[2] = (a.v[2] | b.v[2]);
	return c;
}

struct matrix {
	BitSet row[maxN];
	BitSet col[maxN];
	void buildCols() {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (row[i].at(j)) {
					col[j].set(i);
				}
			}
		}
	}
};

matrix mul(const matrix &a, const matrix &b) {
	matrix res;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			BitSet w = intersect(a.row[i], b.col[j]);
			if (w.v[0] != 0 || w.v[1] != 0 || w.v[2] != 0) {
				res.row[i].set(j);
				res.col[j].set(i);
			}
		}
	}
	return res;
}

BitSet mul(const BitSet &row, const matrix &a) {
	BitSet res;
	for (int i = 0; i < n; ++i) {
		BitSet w = intersect(row, a.col[i]);
		if (w.v[0] != 0 || w.v[1] != 0 || w.v[2] != 0) {
			res.set(i);
		}
	}
	return res;
}

BitSet pow(BitSet row, matrix a, int n) {
	while (n) {
		if (n & 1) {
			row = mul(row, a);
		}
		a = mul(a, a);
		n /= 2;
	}
	return row;
}

matrix g[maxN];
BitSet h[maxN];

bool check(int t) {
	int index = -1;
	for (int i = 0; i < m; ++i) {
		if (d[i] < t) {
			index = i;
		}
	}

	BitSet start = h[index + 1];
	start = pow(start, g[index + 1], t - (index == -1 ? 0 : d[index]));
	return start.at(n - 1);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &a[i], &b[i], &d[i]);
		--a[i];
		--b[i];
	}
	for (int i = 0; i < m; ++i) {
		for (int j = i + 1; j < m; ++j) {
			if (d[j] < d[i]) {
				swap(a[i], a[j]);
				swap(b[i], b[j]);
				swap(d[i], d[j]);
			}
		}
	}

	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j < i; ++j) {
			g[i].col[b[j]].set(a[j]);
			g[i].row[a[j]].set(b[j]);
		}
	}

	h[0].set(0);
	int flights = 0;
	for (int i = 0; i < m; ++i) {
		h[i + 1] = pow(h[i], g[i], d[i] - flights);
		flights = d[i];
	}

	long long res = 1000000000000000000LL;
	for (int i = 0; i <= m; ++i) {
		BitSet current = h[i];
		long long moves = (i == 0 ? 0 : d[i - 1]);
		for (int j = 0; j <= 400; ++j) {
			if (current.at(n - 1)) {
				res = min(res, moves + j);
			}
			current = mul(current, g[i]);
		}
	}

	if (res == 1000000000000000000LL) {
		printf("Impossible\n");
	} else {
		cout << res << endl;
	}

	/*long long left_bound = 0, right_bound = 2000000000;
	while (right_bound - left_bound > 1) {
		long long middle = (left_bound + right_bound) / 2;
		if (check(middle)) {
			right_bound = middle;
		} else {
			left_bound = middle;
		}
	}

	int res = -1;
	if (check(left_bound)) {
		res = left_bound;
	} else if (check(right_bound)) {
		res = right_bound;
	}
	if (res == -1) {
		printf("Impossible\n");
	} else {
		printf("%d\n", res);
	}*/

	/*for (int i = 0; ; ++i) {
		if (check(i)) {
			printf("%d\n", i);
			return 0;
		}
	}*/

	return 0;
}