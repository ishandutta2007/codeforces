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
int n, a[maxN];

int t1[4 * maxN], t2[4 * maxN];

void build(int t[], int i, int l, int r, int f(int, int)) {
	if (l == r) {
		t[i] = a[l];
		return;
	}
	build(t, 2 * i, l, (l + r) / 2, f);
	build(t, 2 * i + 1, (l + r) / 2 + 1, r, f);
	t[i] = f(t[2 * i], t[2 * i + 1]);
}

int get(int t[], int i, int l, int r, int cl, int cr, int f(int, int)) {
	if (cl == l && cr == r) {
		return t[i];
	}

	if (cl > (l + r) / 2) {
		return get(t, 2 * i + 1, (l + r) / 2 + 1, r, cl, cr, f);
	}
	if (cr <= (l + r) / 2) {
		return get(t, 2 * i, l, (l + r) / 2, cl, cr, f);
	}

	int a = get(t, 2 * i, l, (l + r) / 2, cl, (l + r) / 2, f);
	int b = get(t, 2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr, f);
	return f(a, b);
}

int getMin(int a, int b) {
	return min(a, b);
}

int getMax(int a, int b) {
	return max(a, b);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	build(t1, 1, 0, n - 1, getMin);
	build(t2, 1, 0, n - 1, getMax);

	int res = 0;
	for (int i = 0; i < n; ++i) {
		int l = i, r = n - 1;
		while (r - l > 1) {
			int m = (l + r) / 2;
			int mn = get(t1, 1, 0, n - 1, i, m, getMin);
			int mx = get(t2, 1, 0, n - 1, i, m, getMax);
			if (mx <= mn + 1) {
				l = m;
			} else {
				r = m;
			}
		}

		int bound = l;
		if (get(t2, 1, 0, n - 1, i, r, getMax) - get(t1, 1, 0, n - 1, i, r, getMin) <= 1) {
			bound = r;
		}
		res = max(res, bound - i + 1);
	}
	printf("%d\n", res);


	return 0;
}