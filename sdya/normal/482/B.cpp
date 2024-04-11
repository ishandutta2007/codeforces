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
int t[4 * maxN], add[4 * maxN];
int t2[4 * maxN], a[maxN];

void build(int i, int l, int r) {
	if (l == r) {
		t2[i] = a[l];
		return ;
	}
	build(2 * i, l, (l + r) / 2);
	build(2 * i + 1, (l + r) / 2 + 1, r);
	t2[i] = t2[2 * i] & t2[2 * i + 1];
}

int get(int i, int l, int r, int cl, int cr) {
	if (l == cl && r == cr) {
		return t2[i];
	}
	if (cl > (l + r) / 2) {
		return get(2 * i + 1, (l + r) / 2 + 1, r, cl, cr);
	}
	if (cr <= (l + r) / 2) {
		return get(2 * i, l, (l + r) / 2, cl, cr);
	}

	return
		get(2 * i, l, (l + r) / 2, cl, (l + r) / 2) &
		get(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr);
}

void update(int i, int l, int r, int cl, int cr, int value) {
	if (l == cl && r == cr) {
		t[i] |= value;
		add[i] |= value;
		return ;
	}

	if (cl > (l + r) / 2) {
		update(2 * i + 1, (l + r) / 2 + 1, r, cl, cr, value);
	} else if (cr <= (l + r) / 2) {
		update(2 * i, l, (l + r) / 2, cl, cr, value);
	} else {
		update(2 * i, l, (l + r) / 2, cl, (l + r) / 2, value);
		update(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr, value);
	}

	t[i] = (max(t[2 * i], t[2 * i + 1]) | add[i]);
}

int get(int i, int l, int r, int k) {
	if (l == r) {
		return t[i];
	}

	if (k > (l + r) / 2) {
		return get(2 * i + 1, (l + r) / 2 + 1, r, k) | add[i];
	}
	return get(2 * i, l, (l + r) / 2, k) | add[i];
}

int n, m;
int l[maxN], r[maxN], q[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &l[i], &r[i], &q[i]);
		update(1, 1, n, l[i], r[i], q[i]);
	}

	for (int i = 1; i <= n; ++i) {
		a[i] = get(1, 1, n, i);
	}

	build(1, 1, n);

	for (int i = 0; i < m; ++i) {
		if (get(1, 1, n, l[i], r[i]) != q[i]) {
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");
	for (int i = 1; i <= n; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");
	
	


	return 0;
}