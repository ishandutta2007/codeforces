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

const int maxN = 210000;
const int maxM = 32;
int n, q;
int a[maxN];

struct Basic {
	int a[maxM];
	char n;

	void init(int value) {
		if (value) {
			a[0] = value;
			n = 1;
		} else {
			n = 0;
		}
	}

	void update(int value) {
		for (int i = 0; i < n; ++i) {
			if (value) {
				int u = __builtin_ctz(a[i]);
				if (value & (1 << u)) {
					value ^= a[i];
				}
			} else {
				break;
			}
		}
		if (value) {
			int u = __builtin_ctz(value);
			for (int i = 0; i < n; ++i) {
				if (a[i] & (1 << u)) {
					a[i] ^= value;
				}
			}
			a[n++] = value;
		}
	}

	void update(const Basic &other) {
		for (int i = 0; i < other.n; ++i) {
			update(other.a[i]);
		}
	}
};

Basic s[4 * maxN];
int t[maxN];

void build(int i, int l, int r) {
	if (l == r) {
		s[i].init(a[l]);
		return;
	}
	build(2 * i, l, (l + r) / 2);
	build(2 * i + 1, (l + r) / 2 + 1, r);

	s[i] = s[2 * i];
	s[i].update(s[2 * i + 1]);
}

void update(int k, int value) {
	for (int i = k; i < maxN; i |= (i + 1)) {
		t[i] ^= value;
	}
}

int get(int k) {
	int res = 0;
	for (int i = k; i >= 0; i = (i & (i + 1)) - 1) {
		res ^= t[i];
	}
	return res;
}

void update(int i, int l, int r, int k, int value) {
	if (k > r) {
		return;
	}
	if (l == r) {
		a[l] ^= value;
		s[i].init(a[l]);
		return;
	}
	if (k > (l + r) / 2) {
		update(2 * i + 1, (l + r) / 2 + 1, r, k, value);
	} else {
		update(2 * i, l, (l + r) / 2, k, value);
	}
	s[i] = s[2 * i];
	s[i].update(s[2 * i + 1]);
}

Basic get(int i, int l, int r, int cl, int cr) {
	if (cl > cr) {
		Basic res;
		res.init(0);
		return res;
	}
	if (l == cl && r == cr) {
		return s[i];
	}

	if (cl > (l + r) / 2) {
		return get(2 * i + 1, (l + r) / 2 + 1, r, cl, cr);
	}
	if (cr <= (l + r) / 2) {
		return get(2 * i, l, (l + r) / 2, cl, cr);
	}
	Basic A = get(2 * i, l, (l + r) / 2, cl, (l + r) / 2);
	Basic B = get(2 * i + 1, (l + r) / 2 + 1, r, (l + r) / 2 + 1, cr);
	A.update(B);
	return A;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = n - 1; i >= 1; --i) {
		a[i] = (a[i] ^ a[i - 1]);
	}
	build(1, 0, n - 1);
	for (int i = 0; i < n; ++i) {
		update(i, a[i]);
	}

	for (int i = 0; i < q; ++i) {
		int mode;
		scanf("%d", &mode);
		if (mode == 1) {
			int l, r, k;
			scanf("%d%d%d", &l, &r, &k);
			--l;
			--r;
			update(1, 0, n - 1, r + 1, k);
			update(r + 1, k);
			update(1, 0, n - 1, l, k);
			update(l, k);
		} else {
			int l, r;
			scanf("%d%d", &l, &r);
			--l;
			--r;
			Basic res = get(1, 0, n - 1, l + 1, r);
			res.update(get(l));
			printf("%d\n", (1 << res.n));
		}
	}

	return 0;
}