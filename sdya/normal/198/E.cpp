#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <cmath>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 300000;
int x[maxN], y[maxN], p[maxN], r[maxN], m[maxN], n;
pair < long long, int > t[4 * maxN];

long long d[maxN];
int order[maxN];

void build(int i, int l, int r) {
	if (l == r) {
		t[i] = make_pair(d[order[l]], l);
		return ;
	}
	build(2 * i, l, (l + r) / 2);
	build(2 * i + 1, (l + r) / 2 + 1, r);
	t[i] = min(t[2 * i], t[2 * i + 1]);
}

pair < long long, int > get(int i, int cl, int cr, int l, int r) {
	if (cl == l && cr == r) {
		return t[i];
	}

	if (l > (cl + cr) / 2) {
		return get(2 * i + 1, (cl + cr) / 2 + 1, cr, l, r);
	}
	if (r <= (cl + cr) / 2) {
		return get(2 * i, cl, (cl + cr) / 2, l, r);
	}

	pair < long long, int > A = get(2 * i, cl, (cl + cr) / 2, l, (cl + cr) / 2);
	pair < long long, int > B = get(2 * i + 1, (cl + cr) / 2 + 1, cr, (cl + cr) / 2 + 1, r);
	return min(A, B);
}

void update(int i, int l, int r, int k, long long delta) {
	if (l == r) {
		t[i].first = delta;
		return ;
	}

	if (k > (l + r) / 2) {
		update(2 * i + 1, (l + r) / 2 + 1, r, k, delta); 
	} else {
		update(2 * i, l, (l + r) / 2, k, delta);
	}
	t[i] = min(t[2 * i], t[2 * i + 1]);
}

bool comp(int x, int y) {
	return m[x] < m[y];
}

int used[maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d%d%d", &x[0], &y[0], &p[0], &r[0], &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d%d%d", &x[i], &y[i], &m[i], &p[i], &r[i]);
		long long dx = x[i] - x[0];
		long long dy = y[i] - y[0];
		d[i] = dx * dx + dy * dy;
		order[i] = i;
	}
	sort(order + 1, order + n + 1, comp);
	build(1, 1, n);

	used[0] = true;
	queue < int > q;
	q.push(0);
	while (!q.empty()) {
		int v = q.front();
		q.pop();

		int lt = 1, rt = n;
		while (rt - lt > 1) {
			int key = (lt + rt) / 2;
			if (p[v] >= m[order[key]]) {
				lt = key;
			} else {
				rt = key;
			}
		}

		int start = -1;
		if (p[v] >= m[order[rt]]) {
			start = rt;
		} else if (p[v] >= m[order[lt]]) {
			start = lt;
		}
		if (start == -1) {
			continue;
		}

		while (true) {
			pair < long long, int > pos = get(1, 1, n, 1, start);
			long long dist = (long long)(r[v]) * (long long)(r[v]);
			if (dist >= pos.first) {
				int u = order[pos.second];
				if (!used[u]) {
					used[u] = true;
					q.push(u);
					update(1, 1, n, pos.second, 4000000000000000000LL);
				}
			} else {
				break;
			}
		}
	}

	int res = 0;
	for (int i = 1; i <= n; ++i) {
		if (used[i]) {
			++res;
		}
	}

	printf("%d\n", res);

	return 0;
}