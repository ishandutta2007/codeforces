#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 210000;
const int maxD = 19;
int n, p[maxN], l[maxN];
int ending[maxD][maxN], value[maxD][maxN];
int lastOne[maxD][maxN];

int t[4 * maxN];

void update(int i, int l, int r, int k, int delta) {
	if (l == r) {
		t[i] = delta;
		return;
	}

	if ((l + r) / 2 >= k) {
		update(2 * i, l, (l + r) / 2, k, delta);
	} else {
		update(2 * i + 1, (l + r) / 2 + 1, r, k, delta);
	}
	t[i] = max(t[2 * i], t[2 * i + 1]);
}

int get(int i, int l, int r, int cl, int cr) {
	if (l == cl && r == cr) {
		return t[i];
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

void precalc() {
	for (int i = n; i >= 1; --i) {
		ending[0][i] = p[i] + l[i];
		lastOne[0][i] = i;
		if (i == n) {
			update(1, 1, n, i, ending[0][i]);
			continue;
		}

		if (ending[0][i] >= p[i + 1]) {
			int id = upper_bound(p + 1, p + n + 1, ending[0][i]) - p;
			--id;
			int value = get(1, 1, n, i + 1, id);
			ending[0][i] = max(ending[0][i], value);
			lastOne[0][i] = upper_bound(p + 1, p + n + 1, ending[0][i]) - p;
			--lastOne[0][i];
		}
		update(1, 1, n, i, ending[0][i]);
	}

	for (int i = 1; i < maxD; ++i) {
		for (int j = 1; j <= n; ++j) {
			int current = ending[i - 1][j];
			int k = lastOne[i - 1][j] + 1;
			
			if (k > n) {
				value[i][j] = value[i - 1][j];
				ending[i][j] = ending[i - 1][j];
				lastOne[i][j] = lastOne[i - 1][j];
			} else {
				value[i][j] = value[i - 1][j] + (p[k] - current) + value[i - 1][k];
				ending[i][j] = ending[i - 1][k];
				lastOne[i][j] = lastOne[i - 1][k];
			}
		}
	}
}

int check(int steps, int x, int y) {
	int total = 0;
	int pos = x;
	for (int i = 0; i < maxD; ++i) {
		if (steps & (1 << i)) {
			total += value[i][pos];
			int oldEnding = ending[i][pos];
			pos = lastOne[i][pos];
			if (pos >= y) {
				return total;
			}

			++pos;
			if (pos > n) {
				return total;
			}
			total += p[pos] - oldEnding;
		}
	}
	return -1;
}

int solve(int x, int y) {
	int left_bound = 1, right_bound = n;
	while (right_bound - left_bound > 1) {
		int middle = (left_bound + right_bound) / 2;
		if (check(middle, x, y) >= 0) {
			right_bound = middle;
		} else {
			left_bound = middle;
		}
	}
	int A = check(left_bound, x, y);
	if (A >= 0) {
		return A;
	}
	return check(right_bound, x, y);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &p[i], &l[i]);
	}
	precalc();

	int q;
	scanf("%d", &q);
	for (int i = 1; i <= q; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%d\n", solve(x, y));
	}
	
	return 0;
}