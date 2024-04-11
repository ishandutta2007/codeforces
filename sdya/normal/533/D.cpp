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

const int maxN = 110000;
const long long inf = 1000000000000000000LL;
long long t[4 * maxN];

void init(int i, int l, int r) {
	if (l == r) {
		t[i] = -inf;
		return;
	}
	init(2 * i, l, (l + r) / 2);
	init(2 * i + 1, (l + r) / 2 + 1, r);
	t[i] = max(t[2 * i], t[2 * i + 1]);
}

void update(int i, int l, int r, int k, long long value) {
	if (l == r) {
		t[i] = max(t[i], value);
		return;
	}

	if (k > (l + r) / 2) {
		update(2 * i + 1, (l + r) / 2 + 1, r, k, value);
	} else {
		update(2 * i, l, (l + r) / 2, k, value);
	}
	t[i] = max(t[2 * i], t[2 * i + 1]);
}

int getIndex(int i, int l, int r, int cl, int cr, long long bound, bool isLargest = true) {
	if (l == cl && r == cr) {
		if (l == r) {
			if (t[i] >= bound) {
				return l;
			}
			return -1;
		}
		long long L = t[2 * i];
		long long R = t[2 * i + 1];
		if (isLargest) {
			if (R >= bound) {
				return getIndex(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, r, bound, isLargest);
			}
			return getIndex(2 * i, l, (l + r) / 2, l, (l + r) / 2, bound, isLargest);
		} else {
			if (L >= bound) {
				return getIndex(2 * i, l, (l + r) / 2, l, (l + r) / 2, bound, isLargest);
			}
			return getIndex(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, r, bound, isLargest);
		}
	}

	if (cl > (l + r) / 2) {
		return getIndex(2 * i + 1, (l + r) / 2 + 1, r, cl, cr, bound, isLargest);
	}
	if (cr <= (l + r) / 2) {
		return getIndex(2 * i, l, (l + r) / 2, cl, cr, bound, isLargest);
	}
	int L = getIndex(2 * i, l, (l + r) / 2, cl, (l + r) / 2, bound, isLargest);
	int R = getIndex(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr, bound, isLargest);
	if (isLargest) {
		return R != -1 ? R : L;
	} else {
		return L != -1 ? L : R;
	}
}

int n, x[maxN], d[maxN];
long long tL[maxN], tR[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i <= n + 1; ++i) {
		scanf("%d", &x[i]);
		x[i] *= 2;
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &d[i]);
		d[i] *= 2;
		tL[i] = -inf;
		tR[i] = -inf;
	}

	tL[0] = tR[0] = tL[n + 1] = tR[n + 1] = 1000000000000LL;

	init(1, 0, n + 1);
	update(1, 0, n + 1, 0, inf);

	for (int i = 1; i <= n; ++i) {
		int id = getIndex(1, 0, n + 1, 0, i - 1, x[i]);
		long long spare = (long long)(d[i]) - (long long)(x[i] - x[id]) / 2LL;
		if (spare > 0) {
			tL[i] = spare;
			update(1, 0, n + 1, i, 2LL * spare + (long long)(x[i]));
			if (2LL * ((long long)(x[i]) + spare) >= (long long)(x[i]) + (long long)(x[n + 1])) {
				printf("0\n");
				return 0;
			}
		}
	}

	for (int i = 0; i <= n + 1; ++i) {
		x[i] = -x[i];
	}
	reverse(x, x + n + 2);
	reverse(d, d + n + 2);
	init(1, 0, n + 1);
	update(1, 0, n + 1, 0, inf);
	for (int i = 1; i <= n; ++i) {
		int id = getIndex(1, 0, n + 1, 0, i - 1, x[i]);
		long long spare = (long long)(d[i]) - (long long)(x[i] - x[id]) / 2LL;
		if (spare > 0) {
			tR[n + 1 - i] = spare;
			update(1, 0, n + 1, i, 2LL * spare + (long long)(x[i]));
		}
	}
	reverse(x, x + n + 2);
	reverse(d, d + n + 2);
	for (int i = 0; i <= n + 1; ++i) {
		x[i] = -x[i];
	}

	init(1, 0, n + 1);
	for (int i = 0; i <= n + 1; ++i) {
		update(1, 0, n + 1, i, 2LL * tR[i] - (long long)(x[i]));
	}

	long long res = x[n + 1] - x[0];
	for (int i = 1; i <= n; ++i) {
		int id = getIndex(1, 0, n + 1, i + 1, n + 1, -2LL * tL[i] - (long long)(x[i]), false);
		if (id != -1) {
			res = min(res, (long long)(x[id] - x[i]));
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (tR[i] > 0) {
			res = min(res, (long long)(x[i] - x[0]));
		}
	}

	printf("%.10lf\n", (double)(res) / 4.0);
	
	return 0;
}