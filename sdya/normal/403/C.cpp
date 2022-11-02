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

const int maxN = 2010;
const int base = 32;
const int len = (maxN + base - 1) / base;

int n;

struct BitSet {
	unsigned int a[len];
	int L;
	BitSet() {
		L = (n + base - 1) / base;
		for (int i = 0; i < L; ++i) {
			a[i] = 0;
		}
	}
	void setIndex(unsigned int i) {
		a[i / base] |= ((unsigned int)(1) << (i % base));
	}
};

int sum(const BitSet& a, const BitSet& b) {
	int v = 0;
	for (int i = 0; i < a.L; ++i) {
		v = (a.a[i] & b.a[i]);
		if (v > 0) {
			return 1;
		}
	}
	return 0;
}

struct Matrix {
	bool a[maxN][maxN];
	BitSet r[maxN], c[maxN];

	void init(bool b[maxN][maxN]) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				a[i][j] = b[i][j];
				if (b[i][j]) {
					r[i].setIndex(j);
					c[j].setIndex(i);
				}
			}
		}
	}

	void norm() {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (a[i][j]) {
					r[i].setIndex(j);
					c[j].setIndex(i);
				}
			}
		}
	}
};

Matrix mul(const Matrix &a, const Matrix &b) {
	Matrix res;
	for (int i = 0; i < maxN; ++i) {
		for (int j = 0; j < maxN; ++j) {
			int cnt = sum(a.r[i], b.c[j]);
			res.a[i][j] = cnt;
		}
	}
	res.norm();
	return res;
}

bool a[maxN][maxN];
bitset < maxN > g[maxN];

void gen() {
	printf("2000\n");
	for (int i = 0; i < 2000; ++i) {
		for (int j = 0; j < 2000; ++j) {
			printf("%d ", rand() % 10);
		}
		printf("\n");
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//gen();

	scanf("%d", &n);
	//n = 2000;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int x;
			scanf("%d", &x);
			//x = (i + j) % 10;
			a[i][j] = (x > 0);
			g[i][j] = a[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (g[j][i]) {
				g[j] |= g[i];
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (g[i][j] == 0) {
				++cnt;
			}
		}
	}

	if (cnt == 0) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}

	return 0;
}