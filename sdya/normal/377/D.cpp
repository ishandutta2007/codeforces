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

const int maxN = 310000;
int t[4 * maxN], add[4 * maxN], id[4 * maxN];

void init(int i, int l, int r) {
	if (l == r) {
		id[i] = l;
		return;
	}
	init(2 * i, l, (l + r) / 2);
	init(2 * i + 1, (l + r) / 2 + 1, r);
	id[i] = id[2 * i + 1];
}

void update(int i, int l, int r, int cl, int cr, int value) {
	if (l == cl && r == cr) {
		t[i] += value;
		add[i] += value;
		return;
	}
	if (cl > (l + r) / 2) {
		update(2 * i + 1, (l + r) / 2 + 1, r, cl, cr, value);
	} else if (cr <= (l + r) / 2) {
		update(2 * i, l, (l + r) / 2, cl, cr, value);
	} else {
		update(2 * i, l, (l + r) / 2, cl, (l + r) / 2, value);
		update(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr, value);
	}
	id[i] = (t[2 * i + 1] >= t[2 * i] ? id[2 * i + 1] : id[2 * i]);
	t[i] = max(t[2 * i], t[2 * i + 1]) + add[i];
}

pair < int, int > get(int i, int l, int r, int cl, int cr) {
	if (l == cl && r == cr) {
		return make_pair(t[i], id[i]);
	}
	if (cl > (l + r) / 2) {
		return get(2 * i + 1, (l + r) / 2 + 1, r, cl, cr);
	}
	if (cr <= (l + r) / 2) {
		return get(2 * i, l, (l + r) / 2, cl, cr);
	}
	return max(
		get(2 * i, l, (l + r) / 2, cl, (l + r) / 2),
		get(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr));
}

int n;
int l[maxN], a[maxN], r[maxN];
int orderL[maxN], orderA[maxN];

bool compL(int x, int y) {
	return l[x] < l[y];
}

bool compA(int x, int y) {
	return a[x] < a[y];
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d", &l[i], &a[i], &r[i]);
		orderL[i] = i;
		orderA[i] = i;
	}
	sort(orderA, orderA + n, compA);
	sort(orderL, orderL + n, compL);

	init(1, 0, maxN - 1);

	set < pair < int, int > > S;
	int position = 0;
	int res = 0;
	int st = -1, fn = -1;
	for (int i = 0; i < n; ++i) {
		int index = orderA[i];
		int bound = a[index];
		while (position < n && l[orderL[position]] <= bound) {
			int v = orderL[position];
			S.insert(make_pair(a[v], v));
			update(1, 0, maxN - 1, a[v], r[v], +1);
			++position;
		}

		while (!S.empty()) {
			int value = S.begin()->first;
			if (value < bound) {
				int v = S.begin()->second;
				S.erase(S.begin());
				update(1, 0, maxN - 1, a[v], r[v], -1);
			} else {
				break;
			}
		}
		pair < int, int > current = get(1, 0, maxN - 1, bound, maxN - 1);
		if (current.first > res) {
			res = current.first;
			st = index;
			fn = current.second;
		}
	}

	printf("%d\n", res);
	for (int i = 0; i < n; ++i) {
		if (l[i] <= a[st] && a[i] >= a[st] && a[i] <= fn && r[i] >= fn) {
			printf("%d ", i + 1);
		}
	}
	printf("\n");


	return 0;
}