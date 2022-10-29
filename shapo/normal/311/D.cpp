#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

#define maxn 100500
#define maxk 131072
#define maxs 48

const int MD = 95542721;

struct list {
	int l, r;
	int shift;
	int sum[maxs];
};

list array[2 * maxn];
int tree_root;
int arr[maxn];
int n, q;
int pnt = 0;
int l, r;

int get_root(const int l, const int r) {
	int res = ++pnt;
	if (l == r) {
		int cur = arr[l];
		for (int i = 0; i < maxs; ++i) {
			array[res].sum[i] = cur;
			cur = (ll) cur * cur % MD * cur % MD;
		}
	} else {
		array[res].l = get_root(l, (l + r) / 2),
		array[res].r = get_root((l + r) / 2 + 1, r);
		for (int i = 0; i < maxs; ++i) {
			array[res].sum[i] = array[array[res].l].sum[i] + array[array[res].r].sum[i];
			if (array[res].sum[i] >= MD) array[res].sum[i] -= MD;
		}
	}
	return res;
}

int proc(int v) {
	int lft = array[v].l, rght = array[v].r;
	array[lft].shift += array[v].shift;
	array[rght].shift += array[v].shift;
	if (array[lft].shift >= maxs) array[lft].shift -= maxs;
	if (array[rght].shift >= maxs) array[rght].shift -= maxs;
	return 0;
}

int recalc(int v) {
	int lft = array[v].l, rght = array[v].r;
	int sl = array[lft].shift,
		sr = array[rght].shift;
	array[v].shift = 0;
	for (int i = 0; i < maxs; ++i) {
		array[v].sum[i] = array[lft].sum[sl] + array[rght].sum[sr];
		if (array[v].sum[i] >= MD) array[v].sum[i] -= MD;
		++sl, ++sr;
		if (sl == maxs) sl = 0;
		if (sr == maxs) sr = 0;
	}
	return 0;
}

int upd_seg(const int l1, const int r1, int v) {
	if (max(l, l1) <= min(r, r1)) {
		if (l <= l1 && r >= r1) {
			++array[v].shift;
			if (array[v].shift == maxs) array[v].shift = 0;
			return 0;
		}
		proc(v);
		upd_seg(l1, (l1 + r1) / 2, array[v].l);
		upd_seg((l1 + r1) / 2 + 1, r1, array[v].r);
		recalc(v);
	}
	return 0;
}

int get_ans(const int l1, const int r1, const int v) {
	int res = 0;
	if (max(l, l1) <= min(r, r1)) {
		if (l <= l1 && r >= r1)
			return array[v].sum[array[v].shift];
		proc(v);
		res = get_ans(l1, (l1 + r1) / 2, array[v].l) +
			  get_ans((l1 + r1) / 2 + 1, r1, array[v].r);
		recalc(v);
		if (res >= MD) res -= MD;
	}
	return res;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", arr + i), arr[i] %= MD;
	tree_root = get_root(1, n);
	scanf("%d", &q);
	int t;
	for (int i = 0; i < q; ++i) {
		scanf("%d%d%d", &t, &l, &r);
		if (t == 1) 
			printf("%d\n", get_ans(1, n, tree_root));
		else
			upd_seg(1, n, tree_root);
	}
	return 0;
}