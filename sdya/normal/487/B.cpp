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

const int maxN = 110000;
int n, s, l;
int a[maxN];

int t1[4 * maxN], t2[4 * maxN];
int t[4 * maxN];

void build(int t[], int i, int l, int r, int value) {
	if (l == r) {
		t[i] = value;
		return;
	}
	build(t, 2 * i, l, (l + r) / 2, value);
	build(t, 2 * i + 1, (l + r) / 2 + 1, r, value);
	t[i] = value;
}

void updateMin(int t[], int i, int l, int r, int k, int value) {
	if (l == r) {
		t[i] = value;
		return;
	}
	if (k > (l + r) / 2) {
		updateMin(t, 2 * i + 1, (l + r) / 2 + 1, r, k, value);
	} else {
		updateMin(t, 2 * i, l, (l + r) / 2, k, value);
	}
	t[i] = min(t[2 * i], t[2 * i + 1]);
}

int getMin(int t[], int i, int l, int r, int cl, int cr) {
	if (l == cl && r == cr) {
		return t[i];
	}
	if (cl > (l + r) / 2) {
		return getMin(t, 2 * i + 1, (l + r) / 2 + 1, r, cl, cr);
	}
	if (cr <= (l + r) / 2) {
		return getMin(t, 2 * i, l, (l + r) / 2, cl, cr);
	}

	return min(
		getMin(t, 2 * i, l, (l + r) / 2, cl, (l + r) / 2),
		getMin(t, 2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr));
}

void updateMax(int t[], int i, int l, int r, int k, int value) {
	if (l == r) {
		t[i] = value;
		return;
	}
	if (k > (l + r) / 2) {
		updateMax(t, 2 * i + 1, (l + r) / 2 + 1, r, k, value);
	} else {
		updateMax(t, 2 * i, l, (l + r) / 2, k, value);
	}
	t[i] = max(t[2 * i], t[2 * i + 1]);
}

int getMax(int t[], int i, int l, int r, int cl, int cr) {
	if (l == cl && r == cr) {
		return t[i];
	}
	if (cl > (l + r) / 2) {
		return getMax(t, 2 * i + 1, (l + r) / 2 + 1, r, cl, cr);
	}
	if (cr <= (l + r) / 2) {
		return getMax(t, 2 * i, l, (l + r) / 2, cl, cr);
	}

	return max(
		getMax(t, 2 * i, l, (l + r) / 2, cl, (l + r) / 2),
		getMax(t, 2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr));
}

int d[maxN];
const int inf = 1000000000;

pair < int, int > getBounds(int i) {
	if (i - l < 0) {
		return make_pair(1, 0);
	}

	int left_bound = 1, right_bound = i - l + 1;
	while (right_bound - left_bound > 1) {
		int middle = (left_bound + right_bound) / 2;
		int diff = getMax(t2, 1, 1, n, middle, i) - getMin(t1, 1, 1, n, middle, i);
		if (diff <= s) {
			right_bound = middle;
		} else {
			left_bound = middle;
		}
	}

	if (getMax(t2, 1, 1, n, left_bound, i) - getMin(t1, 1, 1, n, left_bound, i) <= s) {
		return make_pair(left_bound, i - l + 1);
	}
	if (getMax(t2, 1, 1, n, right_bound, i) - getMin(t1, 1, 1, n, right_bound, i) <= s) {
		return make_pair(right_bound, i - l + 1);
	}
	return make_pair(1, 0);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &s, &l);
	build(t1, 1, 1, n, inf);
	build(t2, 1, 1, n, -inf);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		updateMin(t1, 1, 1, n, i, a[i]);
		updateMax(t2, 1, 1, n, i, a[i]);
	}

	d[0] = 0;
	for (int i = 1; i <= n; ++i) {
		d[i] = inf;
		updateMin(t, 1, 0, n, i, d[i]);
		pair < int, int > p = getBounds(i);
		if (p.first > p.second) {
			continue;
		}

		int res = getMin(t, 1, 0, n, p.first - 1, p.second - 1);
		d[i] = res + 1;
		updateMin(t, 1, 0, n, i, d[i]);
	}

	if (d[n] >= inf) {
		d[n] = -1;
	}
	cout << d[n] << endl;

	return 0;
}