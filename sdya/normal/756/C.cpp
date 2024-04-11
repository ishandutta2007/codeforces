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
int a[maxN];
int n;

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
	t[i] = max(t[2 * i], t[2 * i + 1]) + add[i];
}

int getLast(int i, int l, int r, int added = 0) {
	if (l == r) {
		if (t[i] + added > 0) {
			return l;
		}
		return -1;
	}

	if (t[2 * i + 1] + added + add[i] > 0) {
		return getLast(2 * i + 1, (l + r) / 2 + 1, r, added + add[i]);
	}
	return getLast(2 * i, l, (l + r) / 2, added + add[i]);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int pos;
		int mode;
		scanf("%d%d", &pos, &mode);

		if (mode == 0) {
			update(1, 0, n, 0, pos, -1);
		} else {
			update(1, 0, n, 0, pos, +1);
			int value;
			scanf("%d", &value);
			a[pos] = value;
		}

		int index = getLast(1, 0, n);
		if (index == -1) {
			printf("-1\n");
		} else {
			printf("%d\n", a[index]);
		}
	}

	return 0;
}