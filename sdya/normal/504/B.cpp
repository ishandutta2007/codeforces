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

const int maxN = 210000;
int n, a[maxN], b[maxN];

int x[maxN], y[maxN];
int t[maxN];

int p[maxN];

void update(int k, int value) {
	for (int i = k; i < maxN; i |= (i + 1)) {
		t[i] += value;
	}
}

int get(int k) {
	int s = 0;
	for (int i = k; i >= 0; i = (i & (i + 1)) - 1) {
		s += t[i];
	}
	return s;
}

void build(int a[], int x[]) {
	for (int i = 0; i < maxN; ++i) {
		t[i] = 0;
	}

	for (int i = 0; i < n; ++i) {
		int cnt = get(a[i]);
		x[i] = a[i] - cnt;
		update(a[i], 1);
	}
}

int kthelement(int k) {
	int l = 0, r = n - 1;
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (get(m) >= k) {
			r = m;
		} else {
			l = m;
		}
	}
	if (get(l) >= k) {
		return l;
	}
	return r;
}

void rebuild(int x[], int a[]) {
	for (int i = 0; i < maxN; ++i) {
		t[i] = 0;
	}
	for (int i = 0; i < n; ++i) {
		update(i, 1);
	}

	for (int i = 0; i < n; ++i) {
		a[i] = kthelement(x[i] + 1);
		update(a[i], -1);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &b[i]);
	}

	build(a, x);
	build(b, y);

	for (int i = 0; i < maxN; ++i) {
		x[i] += y[i];
	}

	for (int i = n - 1, j = 0; i > 0; --i, ++j) {
		if (x[i] >= j + 1) {
			x[i] -= j + 1;
			++x[i - 1];
		}
	}
	x[0] %= n;

	rebuild(x, a);
	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}