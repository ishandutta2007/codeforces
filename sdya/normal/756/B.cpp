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

const int inf = 1000000000;
const int maxN = 110000;
int n, a[maxN];

int t[4 * maxN];

void build(int i, int l, int r) {
	if (l == r) {
		t[i] = inf;
		return;
	}
	build(2 * i, l, (l + r) / 2);
	build(2 * i + 1, (l + r) / 2 + 1, r);
	t[i] = min(t[2 * i], t[2 * i + 1]);
}

void update(int i, int l, int r, int k, int value) {
	if (l == r) {
		t[i] = value;
		return;
	}
	if (k > (l + r) / 2) {
		update(2 * i + 1, (l + r) / 2 + 1, r, k, value);
	} else {
		update(2 * i, l, (l + r) / 2, k, value);
	}
	t[i] = min(t[2 * i], t[2 * i + 1]);
}

int get(int i, int l, int r, int cl, int cr) {
	if (cl > cr) {
		return inf;
	}
	if (l == cl && r == cr) {
		return t[i];
	}
	if (cl > (l + r) / 2) {
		return get(2 * i + 1, (l + r) / 2 + 1, r, cl, cr);
	}
	if (cr <= (l + r) / 2) {
		return get(2 * i, l, (l + r) / 2, cl, cr);
	}
	int a = get(2 * i, l, (l + r) / 2, cl, (l + r) / 2);
	int b = get(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr);
	return min(a, b);
}

int d[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}

	build(1, 0, n);
	update(1, 0, n, 0, 0);
	d[0] = 0;
	for (int i = 1; i <= n; ++i) {
		d[i] = inf;
		{
			int index = lower_bound(a + 1, a + i, a[i] - 89) - a;
			d[i] = min(d[i], get(1, 0, n, index - 1, i - 1) + 50);
		}
		{
			int index = lower_bound(a + 1, a + i, a[i] - 1439) - a;
			d[i] = min(d[i], get(1, 0, n, index - 1, i - 1) + 120);
		}
		d[i] = min(d[i], d[i - 1] + 20);
		update(1, 0, n, i, d[i]);
		printf("%d\n", d[i] - d[i - 1]);
	}

	return 0;
}