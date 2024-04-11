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
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 31000;
const long long inf = 1000000000000000000LL;
int n, q;
int w[maxN], h[maxN];
int a[maxN], b[maxN], p[maxN];
int pos[maxN];

int id[maxN];

bool comp(int x, int y) {
	return w[x] < w[y];
}

bool comp2(int x, int y) {
	return b[x] < b[y];
}

int order[maxN];
int v[maxN], nt[maxN];

long long d[maxN];
long long add[maxN][4];

void update(int i) {
	add[i][1] = add[i][2] = add[i][3] = -inf;
	if (i >= 1) {
		if (p[i - 1] != order[i - 1]) {
			add[i][1] = (long long)(a[i - 1]) * (long long)(b[order[i - 1]]);
		}
	}
	if (i >= 2) {
		if (p[i - 1] != order[i - 1] && p[i - 2] != order[i - 2]) {
			add[i][2] = max(add[i][2], (long long)(a[i - 1]) * (long long)(b[order[i - 1]]) + (long long)(a[i - 2]) * (long long)(b[order[i - 2]]));
		}
		if (p[i - 1] != order[i - 2] && p[i - 2] != order[i - 1]) {
			add[i][2] = max(add[i][2], (long long)(a[i - 1]) * (long long)(b[order[i - 2]]) + (long long)(a[i - 2]) * (long long)(b[order[i - 1]]));
		}
	}
	if (i >= 3) {
		int z[3] = {order[i - 1], order[i - 2], order[i - 3]};
		if (z[1] < z[0]) { swap(z[1], z[0]); }
		if (z[2] < z[0]) { swap(z[2], z[0]); }
		if (z[2] < z[1]) { swap(z[2], z[1]); }
		do {
			if (p[i - 1] != z[0] && p[i - 2] != z[1] && p[i - 3] != z[2]) {
				add[i][3] = max(add[i][3], (long long)(a[i - 1]) * (long long)(b[z[0]]) + (long long)(a[i - 2]) * (long long)(b[z[1]]) + (long long)(a[i - 3]) * (long long)(b[z[2]]));
			}
		} while (next_permutation(z, z + 3));
	}
}

void solve() {
	for (int i = n; i >= 1; --i) {
		update(i);
	}
}

void calc() {
	memset(d, 0, sizeof(d));
	for (int i = n; i >= 3; --i) {
		d[i - 1] = max(d[i - 1], d[i] + add[i][1]);
		d[i - 2] = max(d[i - 2], d[i] + add[i][2]);
		d[i - 3] = max(d[i - 3], d[i] + add[i][3]);
	}
	for (int i = 2; i >= 1; --i) {
		for (int j = 1; j <= i; ++j) {
			d[i - j] = max(d[i - j], d[i] + add[i][j]);
		}
	}
	printf("%I64d\n", d[0]);
}

void gen() {
	int n = 30000;
	int q = 10000;
	printf("%d %d\n", n, q);
	for (int i = 0; i < 30000; ++i) {
		printf("%d ", rand() + 1);
	}
	printf("\n");
	for (int i = 0; i < 30000; ++i) {
		printf("%d ", rand() + 1);
	}
	printf("\n");
	for (int i = 0; i < q; ++i) {
		int u = rand() % n + 1;
		int v = rand() % n + 1;
		printf("%d %d\n", u, v);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//gen();

	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &w[i]);
		order[i] = i;
		id[i] = i;
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &h[i]);
	}
	sort(order, order + n, comp);

	for (int i = 0; i < n; ++i) {
		a[i] = w[order[i]];
		b[i] = h[order[i]];
		pos[order[i]] = i;
	}
	for (int i = 0; i < n; ++i) {
		order[i] = i;
		p[i] = i;
	}
	sort(order, order + n, comp2);
	solve();
	for (int i = 0; i < q; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u;
		--v;
		int x = pos[id[u]];
		int y = pos[id[v]];
		swap(p[x], p[y]);
		swap(pos[id[u]], pos[id[v]]);
		swap(id[u], id[v]);
		for (int j = -3; j <= 3; ++j) {
			if (x + j >= 1 && x + j <= n) {
				update(x + j);
			}
			if (y + j >= 1 && y + j <= n) {
				update(y + j);
			}
		}
		calc();
	}

	//cerr << clock() << endl;

	return 0;
}