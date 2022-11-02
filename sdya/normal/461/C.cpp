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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 110000;
int t[maxN], a[maxN], n, q;

void update(int k, int delta) {
	for (int i = k; i < maxN; i |= (i + 1)) {
		t[i] += delta;
	}
}

int get(int k) {
	int res = 0;
	for (int i = k; i >= 0; i = (i & (i + 1)) - 1) {
		res += t[i];
	}
	return res;
}

int get(int l, int r) {
	return get(r) - get(l - 1);
}

int cl, cr;

void fold(int length, bool& rotated) {
	int current = cr - cl;
	if (rotated) {
		length = current - length;
	}
	if (length <= current - length) {
		for (int i = cl + length, j = cl + length - 1; j >= cl; --j, ++i) {
			int value = a[j];
			a[i] += value;
			update(i, value);
		}
		cl += length;
		if (rotated) {
			rotated = false;
		}
	} else {
		for (int i = cl + length, j = cl + length - 1; i < cr; --j, ++i) {
			int value = a[i];
			a[j] += value;
			update(j, value);
		}
		cr = cl + length;
		if (!rotated) {
			rotated = true;
		}
	}
}

int calc(int l, int r, bool& rotated) {
	if (!rotated) {
		return get(cl + l, cl + r - 1);
	}
	return get(cr - r, cr - l - 1);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		update(i, +1);
		a[i] = 1;
	}

	bool rotated = false;
	cl = 1;
	cr = n + 1;
	for (int i = 1; i <= q; ++i) {
		int mode;
		scanf("%d", &mode);
		if (mode == 1) {
			int pos;
			scanf("%d", &pos);
			fold(pos, rotated);
		} else {
			int l, r;
			scanf("%d%d", &l, &r);
			printf("%d\n", calc(l, r, rotated));
		}
	}

	return 0;
}